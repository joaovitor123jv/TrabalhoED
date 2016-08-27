CC=gcc
FONTE=Inicio.c Pilha.c Fila.c
EXE=executavel
OBJ=$(FONTE:.c=.o)
WARNINGS=-Wunused-variable
INICIO=src/Interface/Inicio.java
CC_JAVA=javac

all: interface
	cd src; $(CC) -c $(FONTE)
	cd src; $(CC) -o ../$(EXE) $(WARNINGS) $(OBJ)
	cd src; rm $(OBJ)

interface:
	$(CC_JAVA) $(INICIO)
	mv src/Interface/Inicio.class ./

run:
	java Inicio
