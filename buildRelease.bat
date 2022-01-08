@echo off

echo Starting compilation...

echo.

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\main.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\main.o

echo Compiled main.cpp to main.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Simulation.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Simulation.o

echo Compiled Simulation.cpp to Simulation.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Window.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Window.o

echo Compiled Window.cpp to Window.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Texture.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Texture.o

echo Compiled Texture.cpp to Texture.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Planet.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Planet.o

echo Compiled Planet.cpp to Planet.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Dialog.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Dialog.o

echo Compiled Dialog.cpp to Dialog.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Button.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Button.o

echo Compiled Button.cpp to Button.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\InputField.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\InputField.o

echo Compiled InputField.cpp to InputField.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Row.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Row.o

echo Compiled Row.cpp to Row.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Utils.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Utils.o

echo Compiled Utils.cpp to Utils.o...

echo.

C:\mingw-w64\mingw32\bin\windres.exe ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\res\version.rc ^
-O coff ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\version.res

echo Compiled VERSIONINFO...

echo.

echo Compilation successful.

echo.
echo.

echo Start linking...

echo.

C:\mingw-w64\mingw32\bin\g++.exe ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\main.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Simulation.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Window.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Texture.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Planet.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Dialog.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Button.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\InputField.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Row.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\Utils.o ^
C:\Users\Samuel\cpp\GravSim\releaseBuild\bin\version.res ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\lib ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\lib ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\lib ^
-lmingw32 ^
-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf ^
-Wl,-subsystem,windows ^
-o C:\Users\Samuel\cpp\GravSim\releaseBuild\GravitySimulator.exe

echo Linking successful.

echo Build was successful. Press any key to close the terminal.

pause