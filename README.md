# sdl2_example
An example of drawing to the screen and responding to mouse input in C with SDL2

To compile:
```
gcc -I"C:\SDL2\include" -L"C:\SDL2\lib" main.c -o square.exe -lmingw32 -lSDL2main -lSDL2 -mwindows
```

Left clicking turns the red square blue. Right clicking turns the blue square red.
