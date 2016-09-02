#include"Definicoes.h"
#include"Pilha.h"
#include"Fila.h"
#include "Lista.h"
void sair(Pilha* pilha, Fila* fila, Lista* lista, int* variavel);
int comparaSaidas(Pilha* pilha, Fila* fila, Lista* lista, int elemento);

int main(int argc, char *argv[])
{

	int num = 0;
	Pilha* pilha = criaPilha();
	Fila* fila = criaFila();
	Lista* lista = criaLista();
	FILE* arquivo;
	int i;
	int *variavel;
	int operacao;
	int retorno;
	int lixo;
	printf("\nPrograma aberto \n");

	arquivo = fopen(argv[1], "r+t"); //Abre arquivo passado como parâtro como somente leitura
	printf("Tentou abrir o arquivo");

	if(arquivo == NULL)//Tratamento de erros pra abertura de arquivo
	{
		printf("Arquivo não existe\n");
		return NAO_FOI_POSSIVEL_ABRIR_ARQUIVO;
	}

	while(!feof(arquivo))
	{
		fscanf(arquivo, "%d %d\n", &lixo, &lixo);//só pra contar o tanto de linhas que esse arquivo tem
		printf("Linha %d\n", num);
		num++;
	}

	if(!(num >=0 && num <=1000))//Se não cumprir a condição de ser um numero entre 0 e 1000 (está no exercício), envia sinal de erro
	{
		printf("Numero de linhas incorreto\n");
		fclose(arquivo);
		return ARGUMENTO_INVALIDO;
	}

//Fecha o arquivo e abre novamente pra apontar pro inicio do arquivo
	fclose(arquivo);
	arquivo = fopen(argv[1], "r");
	variavel = (int *) malloc(sizeof(int) * num);//Alocação dinâmica num vetor, pra otimizar e economizar memória (pode trabalhar como um vetor normal)

	printf("Tudo certo até agora \n");

	for(i = 0; i<=num; i++)
	{
		fscanf(arquivo, "%d %d\n", &operacao, &variavel[i]);
		if(operacao == 1)//inserção
		{
			empilha(variavel[i], pilha);
			addFila(variavel[i], fila);
			addLista(lista, variavel[i], i);
		}
		else if(operacao == 2)//remoção
		{
			retorno = comparaSaidas(pilha, fila, lista, variavel[i]);
			if(retorno == IMPOSSIVEL || retorno == FILA || retorno == PILHA || retorno == LISTA)
			{
				return retorno;
			}
		}
		else	//Tratamento de erros
		{
			printf("Argumento invalido\n");
			return ARGUMENTO_INVALIDO;
		}
	}
	printf("Sem problemas \n");
	return INCERTO;
}

void sair(Pilha* pilha, Fila* fila, Lista* lista,int* variavel)
{
	destroiFila(fila);
	destroiPilha(pilha);
	liberaLista(lista);
	if(variavel != NULL)
	{
		free(variavel);
		variavel = NULL;
	}
}


int comparaSaidas(Pilha* pilha, Fila* fila, Lista* lista, int elemento ){

int rtPilha, rtFila, rtLista;


rmFila(fila, &rtFila);
desempilha(pilha, &rtPilha);
rmLista(lista, &rtLista, lista->ultimo);

if((rtFila == elemento)||(rtPilha == elemento)||(rtLista == elemento)){

	if((rtFila == elemento)&&(rtPilha != elemento)&&(rtLista != elemento))
	{
		return FILA;
	}

	if((rtFila != elemento)&&(rtPilha == elemento)&&(rtLista != elemento))
	{
		return PILHA;
	}

	if((rtFila != elemento)&&(rtPilha != elemento)&&(rtLista != elemento))
	{
		return LISTA;
	}

return INCERTO;

}

if((rtFila != elemento)&&(rtPilha != elemento)&&(rtLista != elemento))
{

	return IMPOSSIVEL;

}
}

