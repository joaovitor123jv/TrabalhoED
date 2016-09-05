#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"Sacola.h"


int main ( int argc, char *argv[] ) {
	int comando, valor;
	int n, i;
	int flag[ 3 ];
	int recebido;

	Sacola sacola;

	while ( scanf ( "%d", &n ) != EOF ) {
		memset ( flag, 0, sizeof( flag ) );//Copia o caracter 0 para as posições de flag

		sacola.comeco_fila = 0;
		sacola.final_fila = 0;
		sacola.indice_pilha = 0;
		sacola.indice_lista_prioridade = 0;

		for ( i=0; i<n; i++ ) {
			scanf( "%d %d", &comando, &valor );//EDITAR AQUI
			if ( comando == 1 ) {
				insere_fila ( valor, &sacola );
				insere_pilha ( valor, &sacola );
				insere_lista_prioridade ( valor, &sacola );
			}

			else {
				recebido = remove_fila ( &sacola );
				if ( recebido != valor ) {
					flag[0] = 1;
				}
				recebido = remove_pilha ( &sacola );
				if ( recebido != valor ) {
					flag[1] = 1;
				}
				recebido = remove_lista_prioridade ( &sacola );
				if ( recebido != valor ) {
					flag[2] = 1;
				}
			}
		}

		if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] == 3 )
			printf ( "impossible\n" );

		else
			if ( flag[ 0 ] + flag[ 1 ] + flag[ 2 ] < 2 )
				printf ( "not sure\n" );
			else {
				if ( !flag[0] ) printf ( "queue\n" );
				if ( !flag[1] ) printf ( "stack\n" );
				if ( !flag[2] ) printf ( "priority queue\n" );
			}
	}
	return 0;
}
