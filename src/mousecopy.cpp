#include <windows.h>
#include <math.h>
#include <stdio.h>
#include "tray.h"

/* ---------- 全局状态 ---------- */

HHOOK g_hook = NULL;
bool g_enabled = true;

bool leftPressed = false;
bool dragged = false;
POINT startPos = {0, 0};

const int MOVE_THRESHOLD = 5;

/* ---------- 工具 ---------- */

double dist(POINT a, POINT b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void SendCtrlKey(WORD vk) {
    INPUT in[4] = {};

    in[0].type = INPUT_KEYBOARD;
    in[0].ki.wVk = VK_CONTROL;

    in[1].type = INPUT_KEYBOARD;
    in[1].ki.wVk = vk;

    in[2].type = INPUT_KEYBOARD;
    in[2].ki.wVk = vk;
    in[2].ki.dwFlags = KEYEVENTF_KEYUP;

    in[3].type = INPUT_KEYBOARD;
    in[3].ki.wVk = VK_CONTROL;
    in[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(4, in, sizeof(INPUT));
}

/* ---------- 鼠标钩子 ---------- */

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (!g_enabled)
        return CallNextHookEx(g_hook, nCode, wParam, lParam);

    if (nCode == HC_ACTION) {
        MSLLHOOKSTRUCT* info = (MSLLHOOKSTRUCT*)lParam;

        switch (wParam) {

        case WM_LBUTTONDOWN:
            leftPressed = true;
            dragged = false;
            startPos = info->pt;
            break;

        case WM_MOUSEMOVE:
            if (leftPressed && !dragged) {
                if (dist(startPos, info->pt) > MOVE_THRESHOLD)
                    dragged = true;
            }
            break;

        case WM_LBUTTONUP:
            leftPressed = false;
            break;

        case WM_RBUTTONUP:
            
            if (g_enabled) {  // 模拟 Shift 松开, 以实现按住右键滚轮横滚,Shift 的释放
                INPUT in = {};
                in.type = INPUT_KEYBOARD;
                in.ki.wVk = VK_SHIFT;
                in.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &in, sizeof(INPUT));
            }

            if (leftPressed) {
                if (dragged)
                    SendCtrlKey('C');
                else
                    SendCtrlKey('V');
                return 1;
            }
            break;

        // case WM_MBUTTONUP:  // 中键覆盖粘贴, 不好用就去掉了
        //     if (leftPressed && dragged) {
        //         SendCtrlKey('V');
        //         return 1;
        //     }
        //     break;

        case WM_RBUTTONDOWN:
        // case WM_MBUTTONDOWN:  // 中键覆盖粘贴, 不好用就去掉了

            if (g_enabled) {  // 模拟 Shift 按下, 以实现按住右键滚轮横滚
                INPUT in = {};
                in.type = INPUT_KEYBOARD;
                in.ki.wVk = VK_SHIFT;
                SendInput(1, &in, sizeof(INPUT));
            }

            if (leftPressed)
                return 1;
            break;


        case WM_XBUTTONDOWN:
            if (leftPressed) {
                WORD button = HIWORD(info->mouseData);
                if (button == XBUTTON1)
                    SendCtrlKey('Z'); // 撤销
                else if (button == XBUTTON2)
                    SendCtrlKey('Y'); // 重做
                return 1; // 吞掉原生事件
            }
            break;

        }
    }

    return CallNextHookEx(g_hook, nCode, wParam, lParam);
}

/* ---------- 入口 ---------- */

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int) {
    HWND trayWnd = CreateTrayWindow(hInst);
    if (!trayWnd)
        return 1;

    g_hook = SetWindowsHookEx(
        WH_MOUSE_LL,
        MouseProc,
        GetModuleHandle(NULL),
        0
    );

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(g_hook);
    RemoveTrayIcon(trayWnd);
    return 0;
}
