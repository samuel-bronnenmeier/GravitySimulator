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
-o C:\Users\Samuel\cpp\GravSim\build\bin\main.o

echo Compiled main.cpp to main.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Simulation.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Simulation.o

echo Compiled Simulation.cpp to Simulation.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Window.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Window.o

echo Compiled Window.cpp to Window.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Texture.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Texture.o

echo Compiled Texture.cpp to Texture.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Planet.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Planet.o

echo Compiled Planet.cpp to Planet.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Dialog.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Dialog.o

echo Compiled Dialog.cpp to Dialog.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Button.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Button.o

echo Compiled Button.cpp to Button.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\InputField.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\InputField.o

echo Compiled InputField.cpp to InputField.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Row.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Row.o

echo Compiled Row.cpp to Row.o...

C:\mingw-w64\mingw32\bin\g++.exe ^
-c ^
C:\Users\Samuel\cpp\GravSim\src\Utils.cpp ^
-I C:\Users\Samuel\cpp\GravSim\include ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\include\SDL2 ^
-I C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\include\SDL2 ^
-w ^
-o C:\Users\Samuel\cpp\GravSim\build\bin\Utils.o

echo Compiled Utils.cpp to Utils.o...

echo.

echo Compilation successful.

echo.
echo.

echo Start linking...

echo.

C:\mingw-w64\mingw32\bin\g++.exe ^
C:\Users\Samuel\cpp\GravSim\build\bin\main.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Simulation.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Window.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Texture.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Planet.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Dialog.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Button.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\InputField.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Row.o ^
C:\Users\Samuel\cpp\GravSim\build\bin\Utils.o ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL2\lib ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL_image\lib ^
-L C:\Users\Samuel\cpp\mingw_dev_lib\SDL_ttf\lib ^
-lmingw32 ^
-lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf ^
-o C:\Users\Samuel\cpp\GravSim\build\GravitySimulator.exe
REM -Wl,-subsystem,windows

echo Linking successful.

echo Build was successful. Press any key to close the terminal.

pause