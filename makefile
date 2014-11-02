CC=gcc
SRC=tema1.c
EXE=tema1
CFLAGS=-Wall -lm


build:
	$(CC) $(SRC) -o $(EXE) $(CFLAGS)

.PHONY:clean	

clean:
	rm -f $(EXE)


