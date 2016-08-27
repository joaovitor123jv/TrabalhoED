CC=gcc
FONTE=src/Inicio.c
EXE=executavel
PILHA=src/Pilha.c
OBJ=Inicio.o Pilha.o
WARNINGS=-Wunused-variable

all:
	$(CC) -c $(FONTE) $(PILHA)
	$(CC) -o $(EXE) $(WARNINGS) $(OBJ)
	rm $(OBJ)
