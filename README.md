# MouseCopy-Windows

MouseCopy 是一个轻量级的 Windows 系统托盘工具，通过鼠标组合键实现快速复制与粘贴等操作。

## 功能特点

- 利用鼠标手势快速执行复制/粘贴
- 静默运行于系统托盘，不干扰正常工作流
- 无需配合键盘快捷键，仅用鼠标即可完成操作

## 交互逻辑

1. **按住左键不拖动，同时再点击右键** → 执行**粘贴**操作  
2. **按住左键拖动以选中文本，同时再点击右键** → 执行**复制**操作  
3. ~~**按住左键拖动选中文本，同时再点击中键** → 执行**覆盖粘贴**操作~~（因操作体验不佳，已移除）  
4. **按住左键的同时点击鼠标侧键1（后退键）** → 执行**撤销**操作  
5. **按住左键的同时点击鼠标侧键2（前进键）** → 执行**重做**操作  
6. **按住右键的同时滚动滚轮** → 触发**水平滚动**功能  

## 已知问题

- 无法对表格的单元格进行复制粘贴, 其它功能正常

## 构建

```powershell
pwsh .\build.ps1
```

# MouseCopy-Windows

MouseCopy is a lightweight Windows tray application that enables quick copy and paste actions through intuitive mouse gestures.

## Features

- Perform copy and paste operations using simple mouse gestures  
- Runs silently in the system tray with minimal footprint  
- No keyboard shortcuts required — everything is mouse-driven  

## Interaction Logic

1. **Hold left button (without dragging), then click right button** → **Paste**  
2. **Hold left button, drag to select text, then click right button** → **Copy**  
3. ~~**Hold left button, drag to select text, then click middle button** → **Overwrite Paste**~~ (Removed — found to be unintuitive)  
4. **Hold left button and press Side Button 1 (Back)** → **Undo**  
5. **Hold left button and press Side Button 2 (Forward)** → **Redo**  
6. **Hold right button and scroll the wheel** → **Horizontal scrolling**  

## Known Issues

- The cells in the table cannot be copied and pasted, while other functions are working normally

## Build

```powershell
pwsh .\build.ps1
```
