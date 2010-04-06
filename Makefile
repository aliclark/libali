
CCC = gcc
CC = gcc

INC = ./include/
SRC = ./src/
LIB = ./lib/

INC_DIRS = -I$(INC)

build:
	$(CC) -O2 $(INC_DIRS) -c $(SRC)*.c
	mv ./*.o $(LIB)

test:
	$(CCC) -O2 -pedantic -Wall -Wextra -std=c89 $(INC_DIRS) -c $(SRC)*.c
	mv ./*.o $(LIB)
	make clean

debug:
	$(CCC) -O0 -pedantic -Wall -Wextra -g $(INC_DIRS) -c $(SRC)*.c
	mv ./*.o $(LIB)

clean:
	rm -f ./*.o $(SRC)*.o $(LIB)*.o
	rm -f ./bin/*

rebuild: clean build

