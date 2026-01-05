# MouseCopy-Windows

A simple Windows tray application that copies the text under the mouse cursor.

## Build

```powershell
cl src\mousecopy.cpp src\tray.cpp user32.lib shell32.lib `
   /O2 /MT /utf-8 `
   /Fo:build\ `
   /Fe:build\MouseCopy.exe `
   /link /SUBSYSTEM:WINDOWS
```
