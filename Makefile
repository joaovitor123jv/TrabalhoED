CC=gcc
FONTE=Inicio.c
EXE=executavel
OBJ=Inicio.o

all:
	$(CC) -c $(FONTE)
	$(CC) -o $(EXE) $(OBJ)
	rm $(OBJ)
