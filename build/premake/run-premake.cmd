rem
rem delete old solution/workspace files
rem
rmdir /S /Q ..\vs2017
rmdir /S /Q ..\vs2019
rmdir /S /Q ..\obj
rem
rem create solution/workspace files
rem
premake5-alpha14.exe --os=windows --file=premake5.lua vs2017
premake5-alpha14.exe --os=windows --file=premake5.lua vs2019
