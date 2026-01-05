#include "tray.h"
#include "resource.h"
#include <shellapi.h>
#include <windows.h>
#include <shlobj.h>  // 获取路径

#define WM_TRAY (WM_USER + 1)
#define ID_ENABLE       1001
#define ID_EXIT         1002
#define ID_OPEN_GITHUB  1003
#define ID_AUTOSTART    1004

static NOTIFYICONDATA nid = {};

// 注册表路径和键名
const char* REG_KEY  = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
const char* REG_NAME = "MouseCopy";

// --- 开机自启相关 ---
bool IsAutoStartEnabled() {
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, REG_KEY, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return false;

    char value[512];
    DWORD size = sizeof(value);
    bool exists = (RegQueryValueEx(hKey, REG_NAME, NULL, NULL, (LPBYTE)value, &size) == ERROR_SUCCESS);
    RegCloseKey(hKey);
    return exists;
}

void EnableAutoStart() {
    char path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);

    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, REG_KEY, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        RegSetValueEx(hKey, REG_NAME, 0, REG_SZ, (BYTE*)path, (DWORD)(strlen(path) + 1));
        RegCloseKey(hKey);
    }
}

void DisableAutoStart() {
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_CURRENT_USER, REG_KEY, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        RegDeleteValue(hKey, REG_NAME);
        RegCloseKey(hKey);
    }
}

// --- 托盘消息处理 ---
LRESULT CALLBACK TrayProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_TRAY:
        if (lp == WM_RBUTTONUP) {
            POINT pt;
            GetCursorPos(&pt);

            HMENU menu = CreatePopupMenu();

            // Enable 功能开关
            AppendMenu(menu,
                MF_STRING | (g_enabled ? MF_CHECKED : 0),
                ID_ENABLE, "Enable");

            // Run at Startup 开机自启
            AppendMenu(menu,
                MF_STRING | (IsAutoStartEnabled() ? MF_CHECKED : 0),
                ID_AUTOSTART, "Run at Startup");

            AppendMenu(menu, MF_SEPARATOR, 0, NULL);

            // GitHub 链接
            AppendMenu(menu, MF_STRING, ID_OPEN_GITHUB, "About");

            // Exit
            AppendMenu(menu, MF_STRING, ID_EXIT, "Exit");

            SetForegroundWindow(hwnd);
            TrackPopupMenu(menu, TPM_RIGHTBUTTON,
                           pt.x, pt.y, 0, hwnd, NULL);
            DestroyMenu(menu);
        }
        break;

    case WM_COMMAND:
        switch (LOWORD(wp)) {
        case ID_ENABLE:
            g_enabled = !g_enabled;
            break;

        case ID_AUTOSTART:
            if (IsAutoStartEnabled()) {
                DisableAutoStart();
            } else {
                EnableAutoStart();
            }
            break;

        case ID_OPEN_GITHUB:
            ShellExecute(NULL, "open", "https://github.com/DBinK/MouseCopy-Windows", NULL, NULL, SW_SHOWNORMAL);
            break;

        case ID_EXIT:
            PostQuitMessage(0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

// --- 创建托盘图标 ---
HWND CreateTrayWindow(HINSTANCE hInst) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = TrayProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "MouseCopyTray";

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        wc.lpszClassName, "",
        WS_OVERLAPPEDWINDOW,
        0, 0, 0, 0,
        NULL, NULL, hInst, NULL
    );

    nid.cbSize = sizeof(nid);
    nid.hWnd = hwnd;
    nid.uID = 1;
    nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    nid.uCallbackMessage = WM_TRAY;
    nid.hIcon = LoadIcon(GetModuleHandle(NULL),
                         MAKEINTRESOURCE(IDI_MOUSECOPY));

    lstrcpy(nid.szTip, "MouseCopy");

    Shell_NotifyIcon(NIM_ADD, &nid);
    return hwnd;
}

void RemoveTrayIcon(HWND hwnd) {
    Shell_NotifyIcon(NIM_DELETE, &nid);
}
