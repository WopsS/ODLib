SETLOCAL 
SET architecture=x86_64

IF [%1] NEQ [] SET architecture=%1

premake5.exe vs2017 --architecture=%architecture%
ENDLOCAL