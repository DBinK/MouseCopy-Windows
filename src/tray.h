#pragma once
#include <windows.h>

extern bool g_enabled;

HWND CreateTrayWindow(HINSTANCE hInst);
void RemoveTrayIcon(HWND hwnd);

// Auto start
bool IsAutoStartEnabled();
void EnableAutoStart();
void DisableAutoStart();
