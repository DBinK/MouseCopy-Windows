#include "tray.h"
#include <shellapi.h>

#define WM_TRAY (WM_USER + 1)
#define ID_ENABLE  1001
#define ID_EXIT    1002

static NOTIFYICONDATA nid = {};

LRESULT CALLBACK TrayProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {

    case WM_TRAY:
        if (lp == WM_RBUTTONUP) {
            POINT pt;
            GetCursorPos(&pt);

            HMENU menu = CreatePopupMenu();
            AppendMenu(menu,
                MF_STRING | (g_enabled ? MF_CHECKED : 0),
                ID_ENABLE, "Enable");
            AppendMenu(menu, MF_SEPARATOR, 0, NULL);
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
    nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    lstrcpy(nid.szTip, "MouseCopy");

    Shell_NotifyIcon(NIM_ADD, &nid);
    return hwnd;
}

void RemoveTrayIcon(HWND hwnd) {
    Shell_NotifyIcon(NIM_DELETE, &nid);
}
