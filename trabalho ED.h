int comparaSaidas(Pilha* pilha, Fila* fila, Lista* lista, int elemento ){

int rtPilha, rtFila, rtLista;


rmFila(fila, &rtFila);
desempilha(pilha, &rtPilha);
rmLista(lista, &rtLista, lista->inicio);

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

if((rtFila != elemento)&&(rtPilha != elemento)&&(rtLista != elemento)){

	return IMPOSSIVEL;

}





}


