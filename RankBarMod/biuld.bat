@echo off
echo === Building RankBar.asi with MSYS2 MinGW64 ===

:: Path to MSYS2 MinGW64
set MSYS_PATH=C:\msys64\mingw64.exe

:: Path to your project (adjust if needed)
set PROJECT_PATH=C:\Users\user\Downloads\SC-CL-SampleProject-master\RankBarMod

:: Run make inside MSYS2
%MSYS_PATH% -c "cd '%PROJECT_PATH%' && mingw32-make"

echo.
echo Build finished. Check build\RankBar.asi
pause
