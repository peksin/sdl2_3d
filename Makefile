CC = g++
CFLAGS = -g -Wall -Wextra -std=c++20 -lSDL2
all: sdl2_3d.o


sdl2_3d.o: main.cpp
	$(CC) $(CFLAGS) main.cpp screen.cpp shapes.cpp -o sdl2_3d

clean:
	rm sdl2_3d