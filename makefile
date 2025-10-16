CC = clang
CFLAGS = -Wall -Wextra -std=c11

all: tictactoe

tictactoe: main.o board.o logic.o
	$(CC) $(CFLAGS) -o tictactoe main.o board.o logic.o

main.o: main.c board.h logic.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

logic.o: logic.c logic.h
	$(CC) $(CFLAGS) -c logic.c

clean:
	rm -f *.o tictactoe
