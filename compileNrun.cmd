@echo off
setlocal enabledelayedexpansion

:: Configuration
set BUILD_DIR=bin
set TARGET=engine.exe
set SRCS=main.cpp
set LFLAGS=-lmingw32 -lSDL2main -lSDL2

title Building %TARGET%...

echo ==================================================
echo         C++ / SDL2 Build Script
echo ==================================================
echo.

:: Check if source file exists
if not exist "%SRCS%" (
    echo [ERROR] Source file "%SRCS%" not found!
    echo Please make sure %SRCS% is in the current directory.
    echo.
    goto END
)

:: Create output directory if it doesn't exist
if not exist "%BUILD_DIR%" (
    echo Creating build directory: %BUILD_DIR%
    mkdir "%BUILD_DIR%"
)

echo Compiling %SRCS%...
g++ %SRCS% -o %BUILD_DIR%\%TARGET% %LFLAGS%

if %ERRORLEVEL% EQU 0 (
    echo.
    echo [SUCCESS] Build completed successfully!
    echo Executable created: %BUILD_DIR%\%TARGET%
    echo --------------------------------------------------
    echo Running %TARGET%...
    echo.
    "%BUILD_DIR%\%TARGET%"
) else (
    echo.
    echo [FAILED] Compilation failed with error code %ERRORLEVEL%.
    echo Please check the error messages above.
)

:END
echo.
echo ==================================================
pause