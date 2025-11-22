@echo off

echo ==================================
echo       Compiling Source Code
echo ==================================

set /p FILE="Enter a file nate for compiling: "

if not exist "%FILE%" (
    echo ERROR: %FILE% does not exist.
    GOTO :SKIP
)

gcc "%FILE%".c -o 

if %ERRORLEVEL% neq 0 (
    echo ERROR: Compilation Failed.
    GOTO :SKIP
)

echo Compilation Completed.
:SKIP
gcc main.c -o app.exe