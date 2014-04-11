CC = gcc
CFLAGS = -Wall -Wextra -g

turtle: main.c
	$(CC) $(CFLAGS) -o turtle main.c

clean:
	rm -f ./*.o turtle
