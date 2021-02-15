# My code only works for linux environments with gcc compiler I have not checked other compiler's like msvc 
# My code has a dependency of SDL2.dll file so ther's that

CC=gcc
CFLAGS= -Wall -Wextra -g -O2 -I/mingw64/include/SDL2
DEPS= -L/mingw64/lib/ -lSDL2main -lSDL2

OBJ=Main Display

all: exec

exec: $(foreach obj, $(OBJ), obj/$(obj).o)
	$(CC) $^ $(DEPS) -o bin/$@

obj/%.o:src/%.c src/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm obj/*
	rm bin/*
