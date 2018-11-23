@echo off
:: Load compilation environment
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"
:: Invoke compiler with any options passed to this batch file
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.11.25503\bin\Hostx86\x86\cl.exe" %*
pause