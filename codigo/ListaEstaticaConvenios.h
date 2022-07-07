#define MaxLen1 3

FILE  *exportarConvenios;
FILE  *exportarCadastros;
FILE  *exportarPaciente;

    //Estrutura para o nome do conv�nio
struct Elemento {
    char NomeConvenio[10];

};

struct TLista{
	struct Elemento Item[MaxLen1];
	int Primeiro, Ultimo;
};

    //Iniciar Lista
void Iniciarlista(struct TLista *Lista)  {
	(*Lista).Primeiro = 0;
	(*Lista).Ultimo = (*Lista).Primeiro;
}

    // Limpa a lista
int LimparLista(struct TLista *Lista)  {
	return ((*Lista).Primeiro == (*Lista).Ultimo);
}

    //Insere dados na lista
void InserirLista(struct Elemento E, struct TLista *Lista) {
	if ((*Lista).Ultimo == MaxLen1)
	{
		printf("Lista est� cheia!");
    }
	else
    {
		(*Lista).Item[(*Lista).Ultimo] = E;
		(*Lista).Ultimo++;
	}
}

    // Remove da lista
void RemoverdaLista(struct Elemento *E, int posicao, struct TLista *Lista){
	if (LimparLista(Lista) || posicao >= (*Lista).Ultimo) {
		printf("Lista vazia ou Item n�o existe!!!");
	}
	else {
		*E = (*Lista).Item[posicao];
		(*Lista).Ultimo--;
		for (int i=posicao; i<(*Lista).Ultimo; i++)
			(*Lista).Item[i] = (*Lista).Item[i+1];
	}
}

    // Imprime todos os convenios, que tamb�m � o menu de escolhas do convenio.
void PrintConvenios(struct TLista Lista) {
	for (int c=0; c<3; c++){

		printf("\n %d - %s",c + 1, Lista.Item[c].NomeConvenio);

    }
}

    //Fun��o para realizar a manuten��o do conv�nio
void manutencaoconvenio(struct TLista *Lista, int x){
    do{
            setbuf(stdin, NULL);
            printf("\nInforme o nome do novo conv�nio: ");
            gets((*Lista).Item[x - 1].NomeConvenio);

            printf("\nConv�nio atualizado: ");
            printf("\n [%d] %s",x, (*Lista).Item[x - 1].NomeConvenio);
            break;

    }while(x!= 1 && x!= 2 && x!= 3);

}

    //Fun��o para consultar o conv�nio
void consultaconvenio(struct TLista Lista, int x){
    do{
        switch(x){

        case 1:
            printf("\n[1] - %s", Lista.Item[0].NomeConvenio);
            break;
        case 2:
            printf("\n[2] - %s", Lista.Item[1].NomeConvenio);
            break;
        case 3:
            printf("\n[3] - %s", Lista.Item[2].NomeConvenio);
            break;
        default:
            printf("\nFalha na busca, informe um conv�nio de 1 a 3");
        }
    }while(x!= 1 && x!= 2 && x!= 3);
}

   //Fun��o para subtituir o n�mero do convenio pelo seu nome nas consultas e relat�rios
void mostrarconvenios(struct TLista *Lista, int x){

    printf("\nConv�nio: %s", Lista->Item[x - 1].NomeConvenio);

}

    //Fun��o para subtituir o n�mero do convenio pelo seu nome na exporta��o de todos os pacientes
void exportaconvenios(struct TLista *Lista, int x){

    fprintf(exportarCadastros, "\n CONVENIO: %s", Lista->Item[x - 1].NomeConvenio);

}

    //Fun��o para subtituir o n�mero do convenio pelo seu nome na exporta��o de um unico paciente
void exportaconvenioconsulta(struct TLista *Lista, int x){

    fprintf(exportarPaciente, "\n CONVENIO: %s", Lista->Item[x - 1].NomeConvenio);

}

struct TLista ListaConvenios;
struct Elemento Convenio;

    // Cadastra as opcoes de convenio
void cadastroconvenio(){

    printf("\nCADASTRE O NOME DOS 3 CONV�NIOS:");
    printf("\n");

    for(int i=0; i<3;i++){
        setbuf(stdin, NULL);
        printf("\nConv�nio [%d] - Informe o nome: ", i+1);
        gets(Convenio.NomeConvenio);
        InserirLista(Convenio, &ListaConvenios);

    }
}

    //Imprime todos os convenios cadastrados
void PrintTodosConvenios(){
    PrintConvenios(ListaConvenios);
}

    // exporta a lista est�tica (lista de cadastro dos conv�nios)
void ExportDataConvenios (struct TLista Lista){
    exportarConvenios = fopen ("Lista de convenios.txt", "w");
    fprintf(exportarConvenios, "LISTA DE CONVENIOS: \n");
    for (int c=0; c<MaxLen1; c++){

		fprintf(exportarConvenios,"\n [%d CONVENIO] - %s",c + 1, Lista.Item[c].NomeConvenio);
    }
    fclose(exportarConvenios);
}

