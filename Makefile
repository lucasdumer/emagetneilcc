all:
	mkdir -p bin/
	gcc src/main.c -lncurses -o bin/game
