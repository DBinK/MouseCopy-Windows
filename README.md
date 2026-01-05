<p align="center">
  <img src="assets/mousecopy.png" alt="MouseCopy Icon" width="128" height="128">
</p>

<h1 align="center">MouseCopy-Windows</h1>

<p align="center">
让你只用鼠标就能实现复制、粘贴、撤销等功能，全程无需键盘介入 <br> copy, paste, undo, and other actions using just your mouse — no keyboard needed
</p>

<p align="center">
    <a href="https://zread.ai/DBinK/MouseCopy-Windows" target="_blank"><img src="https://img.shields.io/badge/Ask_Zread-_.svg?style=flat&color=00b0aa&labelColor=000000&logo=data%3Aimage%2Fsvg%2Bxml%3Bbase64%2CPHN2ZyB3aWR0aD0iMTYiIGhlaWdodD0iMTYiIHZpZXdCb3g9IjAgMCAxNiAxNiIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTQuOTYxNTYgMS42MDAxSDIuMjQxNTZDMS44ODgxIDEuNjAwMSAxLjYwMTU2IDEuODg2NjQgMS42MDE1NiAyLjI0MDFWNC45NjAxQzEuNjAxNTYgNS4zMTM1NiAxLjg4ODEgNS42MDAxIDIuMjQxNTYgNS42MDAxSDQuOTYxNTZDNS4zMTUwMiA1LjYwMDEgNS42MDE1NiA1LjMxMzU2IDUuNjAxNTYgNC45NjAxVjIuMjQwMUM1LjYwMTU2IDEuODg2NjQgNS4zMTUwMiAxLjYwMDEgNC45NjE1NiAxLjYwMDFaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00Ljk2MTU2IDEwLjM5OTlIMi4yNDE1NkMxLjg4ODEgMTAuMzk5OSAxLjYwMTU2IDEwLjY4NjQgMS42MDE1NiAxMS4wMzk5VjEzLjc1OTlDMS42MDE1NiAxNC4xMTM0IDEuODg4MSAxNC4zOTk5IDIuMjQxNTYgMTQuMzk5OUg0Ljk2MTU2QzUuMzE1MDIgMTQuMzk5OSA1LjYwMTU2IDE0LjExMzQgNS42MDE1NiAxMy43NTk5VjExLjAzOTlDNS42MDE1NiAxMC42ODY0IDUuMzE1MDIgMTAuMzk5OSA0Ljk2MTU2IDEwLjM5OTlaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik0xMy43NTg0IDEuNjAwMUgxMS4wMzg0QzEwLjY4NSAxLjYwMDEgMTAuMzk4NCAxLjg4NjY0IDEwLjM5ODQgMi4yNDAxVjQuOTYwMUMxMC4zOTg0IDUuMzEzNTYgMTAuNjg1IDUuNjAwMSAxMS4wMzg0IDUuNjAwMUgxMy43NTg0QzE0LjExMTkgNS42MDAxIDE0LjM5ODQgNS4zMTM1NiAxNC4zOTg0IDQuOTYwMVYyLjI0MDFDMTQuMzk4NCAxLjg4NjY0IDE0LjExMTkgMS42MDAxIDEzLjc1ODQgMS42MDAxWiIgZmlsbD0iI2ZmZiIvPgo8cGF0aCBkPSJNNCAxMkwxMiA0TDQgMTJaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00IDEyTDEyIDQiIHN0cm9rZT0iI2ZmZiIgc3Ryb2tlLXdpZHRoPSIxLjUiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIvPgo8L3N2Zz4K&logoColor=ffffff" alt="zread"/></a>
    <img src="https://img.shields.io/badge/Platform-Windows-orange" alt="Platform">
    <img src="https://img.shields.io/badge/Version-0.1.1-blue" alt="Version">
    <img src="https://img.shields.io/badge/license-Apache%20License%202.0-green" alt="License">
</p>

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
