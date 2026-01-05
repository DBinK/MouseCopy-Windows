rc /nologo /fo build\resources.res resources.rc
cl src\mousecopy.cpp src\tray.cpp build\resources.res `
   user32.lib shell32.lib `
   /O2 /MT /utf-8 `
   /Fo:build\ `
   /Fe:build\MouseCopy.exe `
   /link /SUBSYSTEM:WINDOWS
