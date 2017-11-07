#Compilacion
file=main.cpp
dep=cell.o
CC=g++
flags= -lncurses
game: main.cpp $(dep)
	$(CC) $(file) $(dep) $(flags) -o game
cell.o: cell.h cell.cpp
	$(CC) -c cell.cpp

