all: a b

a: src/main.c src/functions.c src/printing.c src/notifications.c src/combat.c src/movement.c
	gcc src/main.c src/functions.c src/printing.c src/notifications.c src/combat.c src/movement.c -std=c99 -lncurses -Wall -o run -I ./include -I ./assets

b:
	./run ./assets/input.txt
