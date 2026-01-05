# MouseCopy-Windows

MouseCopy 让你只用鼠标就能实现复制、粘贴、撤销等功能，全程无需键盘介入

## 功能特点

- 利用鼠标手势快速执行复制/粘贴
- 静默运行于系统托盘，不干扰正常工作流
- 无需配合键盘快捷键，仅用鼠标即可完成操作

## 交互逻辑

- **按住左键不拖动，再点击右键** → **粘贴**  
- **按住左键拖动选中文本，再点击右键** → **复制**  
- ~~**按住左键拖动选中文本，再点击中键** → **覆盖粘贴**~~（因操作不顺手，已移除）  
---
- **按住左键时点击侧键1（后退键）** → **撤销**  
- **按住左键时点击侧键2（前进键）** → **重做**  
---
- **按住右键时滚动滚轮** → **水平滚动**  

## 已知问题

- 无法对表格的单元格进行复制粘贴, 其它功能正常

## 构建

```powershell
pwsh .\build.ps1
```

# MouseCopy-Windows

MouseCopy enables copy, paste, undo, and other actions using just your mouse — no keyboard needed

## Features

- Perform copy and paste operations using simple mouse gestures  
- Runs silently in the system tray with minimal footprint  
- No keyboard shortcuts required — everything is mouse-driven  

## Interaction Logic

- **Hold left button (no drag), then right-click** → **Paste**  
- **Hold left button, drag to select text, then right-click** → **Copy**  
- ~~**Hold left button, drag to select text, then middle-click** → **Overwrite Paste**~~ (Removed — awkward in practice)  
---
- **Hold left button and press Side Button 1 (Back)** → **Undo**  
- **Hold left button and press Side Button 2 (Forward)** → **Redo**  
---
- **Hold right button and scroll wheel** → **Horizontal scroll**  

## Known Issues

- The cells in the table cannot be copied and pasted, while other functions are working normally

## Build

```powershell
pwsh .\build.ps1
```
