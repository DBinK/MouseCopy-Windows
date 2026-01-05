# MouseCopy-Windows

MouseCopy 是一个简单的 Windows 托盘应用程序，能够通过鼠标手势实现快速复制粘贴。

## 功能特点

- 通过鼠标手势实现快速复制粘贴
- 静默运行于系统托盘
- 不需要额外的键盘操作

## 交互逻辑

1. **按住左键不拖动，点击右键** → 实现**粘贴**功能
2. **按住左键拖动选中文本，点击右键** → 实现**复制**功能
3. **按住左键拖动选中文本，点击中键** → 实现**覆盖粘贴**功能（并不顺手, 已移除）
4. **按住左键时点击鼠标侧键1（后退键）** → **撤销**功能
5. **按住左键时点击鼠标侧键2（前进键）** → **重做**功能

## 构建

```powershell
pwsh .\build.ps1
```

# MouseCopy-Windows

MouseCopy is a simple Windows tray application that enables quick copy and paste with mouse gestures.

## Features

- Quick copy and paste with mouse gestures
- Runs silently in the system tray
- No additional keyboard operations required

## Interaction Logic

1. **Hold left button without dragging and click right button** → **Paste** function
2. **Hold left button, drag to select text and click right button** → **Copy** function
3. **Hold left button, drag to select text and click middle button** → **Overwrite paste** function (removed)
4. **Click mouse side button 1 (back button) while holding left button** → **Undo** function
5. **Click mouse side button 2 (forward button) while holding left button** → **Redo** function


## Build

```powershell
pwsh .\build.ps1
```
