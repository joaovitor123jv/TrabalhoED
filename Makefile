CC=gcc
FONTE=Inicio.c
EXE=executavel
PILHA=Pilha.c
OBJ=Inicio.o Pilha.o
WARNINGS=-Wunused-variable

all:
	$(CC) -c $(FONTE) $(PILHA)
	$(CC) -o $(EXE) $(WARNINGS) $(OBJ)
	rm $(OBJ)
