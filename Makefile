CC=gcc
FONTE=main.c Sacola.c 
EXE=executavel
OBJ=$(FONTE:.c=.o)
WARNINGS=-Wunused-variable
INICIO=src/Interface/Inicio.java 
CC_JAVA=javac
CODIGOS_JAVA=src/Interface/TipoRetorno.java

all: interface
	cd src; $(CC) -c $(FONTE)
	cd src; $(CC) -o ../$(EXE) $(WARNINGS) $(OBJ)
	cd src; rm $(OBJ)

interface:
	$(CC_JAVA) $(CODIGOS_JAVA)
	mv $(CODIGOS_JAVA:.java=.class) ./
	$(CC_JAVA) $(INICIO)
	mv src/Interface/Inicio.class ./

run:
	java Inicio
