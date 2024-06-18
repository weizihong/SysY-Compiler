@echo off  
setlocal  

if exist output\*.* (  
    echo The output folder is not empty, do you want to clean it? (Y/N) 
    set /p choice=  
    if %choice%==Y (  
        del /q output\*.*  
        echo The output folder has been cleaned.
        pause Please press any key to continue...
    )  
)

for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17) do (  
    echo Compiling %%i.c ...  
    compiler.exe test\%%i.c output\%%i.s output\%%i.exe 
    echo.  
)  
pause Please press any key to continue...
  
echo Test start
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17) do (  
    echo Running output\%%i.exe ...  
    output\%%i.exe  
    echo. 
    echo Running gccoutput\%%i.exe ...  
    gccoutput\%%i.exe  
    echo. 
    pause Please press any key to continue... 
)  
echo Test finish
pause Please press any key to exit...

endlocal