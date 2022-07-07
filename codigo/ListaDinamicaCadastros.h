struct Element
{
	// variaveis dados do cadastro:
    char    nomePaciente[50];
    char    endereco[150];
    char    bairro[50];
    char    cidade[50];
    double  cpf;
    char    numeroConvenio[30];
    int     codConvenioPessoa;
    int     dataNascimento [3];

    //variaveis observações:
    float   temperaturaPacientes;
    int     batimentosCardiacos;
    char    pressao[7];

    // armazena a data
    int dia;
    int mes;
    int ano;
};

struct Cell
{
	struct Element Item;
	struct Cell    *Prox;
};

struct TList
{
	struct Cell *First;
	struct Cell *Last;
    struct Cell *Pos;
};

void InitializeList(struct TList *List)
{
	(*List).First = NULL;
	(*List).Last = (*List).First;
}

int EmptyList(struct TList *List)
{
	return ((*List).First == NULL);
}

void InsertList(struct Element E, struct TList *List)
{
     if (EmptyList(List))
     {
        (*List).Last = (struct Cell*) malloc(sizeof(struct Cell));
        (*List).First = (*List).Last;
     }
     else
     {
        (*(*List).Last).Prox = (struct Cell*) malloc(sizeof(struct Cell));
        (*List).Last = (*(*List).Last).Prox;
     }

     (*(*List).Last).Item = E;
     (*(*List).Last).Prox = NULL;
}

void RemoveList(struct Element *E, struct Cell *P, struct TList *List) {
     struct Cell *Aux = NULL;
     Aux = (*List).First;

     if (EmptyList(List) || P == NULL)
     {
        printf("\nErro!!!!");
        exit(1);
     }

     //Para retirar o primeiro item da lista
     if (Aux == P)
     {
         (*List).First = (*Aux).Prox;
         (*Aux).Prox = NULL;
     }
     else //Para retirar os demais itens da lista
     {
        while((*Aux).Prox != P)
        {
            Aux = (*Aux).Prox;
        }
        //Caso o ponteiro P esteja apontando para o último item da lista
        if ((*P).Prox == NULL)
        {
            (*List).Last = Aux;
        }
        (*Aux).Prox = (*P).Prox;
        (*P).Prox = NULL;
     }
     *E = (*P).Item;
     free(P);
     P = NULL;
}

void PrintListCadastros(struct TList List)
{
	struct Cell *Aux = NULL;
	Aux = List.First;
    int numContador=1;
	while (Aux != NULL){
        printf("\n NOME DO PACIENTE: %s",(*Aux).Item.nomePaciente);
		printf("\n ENDEREÇO: %s, bairro: %s, cidade: %s ",(*Aux).Item.endereco, (*Aux).Item.bairro, (*Aux).Item.cidade);
        printf("\n CPF: %.0lf",(*Aux).Item.cpf);
        printf("\n NÚMERO DO CONVÊNIO: %s",(*Aux).Item.numeroConvenio);
        printf("\n DATA DE NASCIMENTO: %.2d/%.2d/%.4d",(*Aux).Item.dataNascimento[0],(*Aux).Item.dataNascimento[1], (*Aux).Item.dataNascimento[2] );
        printf("\n\n OBSERVAÇÕES SOBRE O PACIENTE:");
        printf("\n DATA DO ATENDIMENTO: %.2d/%.2d/%.4d", (*Aux).Item.dia, (*Aux).Item.mes, (*Aux).Item.ano );
        printf("\n TEMPERATURA: %.2f°",(*Aux).Item.temperaturaPacientes);
        printf("\n BATIMENTOS CARDÍACOS: %.2d bpm",(*Aux).Item.batimentosCardiacos);
        printf("\n PRESSÃO ARTERIAL: %s mmHg",(*Aux).Item.pressao);
        printf("\n\n");
        Aux = (*Aux).Prox;
    }
}

 // printa os dados de apenas um paciente
void PrintPaciente (struct TList List, struct Cell *posicao) {
    struct Cell *Aux = NULL;
	Aux = List.First;

	setlocale(LC_ALL, "Portuguese");
    printf("\nExibindo os dados do paciente: \n");

	while (Aux != NULL){

	    if(Aux ==  posicao){
            printf("\n NOME DO PACIENTE: %s",(*Aux).Item.nomePaciente);
            printf("\n ENDEREÇO: %s, bairro: %s, cidade: %s ",(*Aux).Item.endereco, (*Aux).Item.bairro, (*Aux).Item.cidade);
            printf("\n CPF: %.0lf",(*Aux).Item.cpf);
            printf("\n NÚMERO DO CONVÊNIO: %s",(*Aux).Item.numeroConvenio);
            printf("\n DATA DE NASCIMENTO: %.2d/%.2d/%.4d",(*Aux).Item.dataNascimento[0],(*Aux).Item.dataNascimento[1], (*Aux).Item.dataNascimento[2] );
            printf("\n\n OBSERVAÇÕES SOBRE O PACIENTE:");
            printf("\n DATA DO ATENDIMENTO: %.2d/%.2d/%.4d", (*Aux).Item.dia, (*Aux).Item.mes, (*Aux).Item.ano );
            printf("\n TEMPERATURA: %.2f°",(*Aux).Item.temperaturaPacientes);
            printf("\n BATIMENTOS CARDÍACOS: %.2d bpm",(*Aux).Item.batimentosCardiacos);
            printf("\n PRESSÃO ARTERIAL: %s mmHg",(*Aux).Item.pressao);
            printf("\n\n");

	    }
	    Aux = (*Aux).Prox;
    }
}

// função que retorna a quantidade de cadastros
int CountList (struct TList List){
    struct Cell *Aux = NULL;
	Aux = List.First;
	int contador=0;

	//  retorna 0, caso a lista esteja vazia
	if(Aux == NULL){
        contador=0;
        return contador;
	}

	// retorna a soma de cadastros
	else {
        while (Aux != NULL){
             // vai somando cada vez que uma lista nova é adicionada
            contador++;

            // pula  pra proxima lista....
            Aux = (*Aux).Prox;

        }
        return contador;
    }
}

 // função  que busca a posição do item...
struct Cell *FindPos (struct TList List, double valor) {
    struct Cell *Aux = NULL;
	Aux = List.First;
    List.Pos= NULL;
	// cria um while par percorrer todas as listas...
	while (Aux != NULL){
        if(valor == (*Aux).Item.cpf ) {
            List.Pos = Aux;
            return List.Pos;
        }
        Aux= (*Aux).Prox;
	}
   if(List.Pos==NULL) {
            return List.Pos;
        }

}

 // procedimento que teste se o existe o usuario ou não, e se existir exibe seu nome....
void FindElement (struct TList List, double valor){
    struct Cell *Aux = NULL;
	Aux = List.First;
	// varivél para testar se existe ou nao um cadastro || 0 é não e 1 é sim....
    int testador;

    // cria um while par percorrer todas as listas...
    while (Aux != NULL){

        // se existir o cadastro.... (EXIBE O NOME DO FUNCIONÁRIO)
        if(valor == (*Aux).Item.cpf) {
            testador = 1;
            printf("\nO funcionário %s foi selecionado!\n\n", (*Aux).Item.nomePaciente);

        }
        Aux= (*Aux).Prox;
    }
        // se não existir o cadastro...
        if (testador == 0){
            printf("\n ESTE FUNCIONÁRIO NÃO EXISTE!\n");
        }

}

 // altera o nome do paciente
void AlterName (struct TList List, struct Cell *posicao){

            setbuf(stdin, NULL);
            printf("Informe o nome do paciente corretamente: ");
            gets( (*posicao).Item.nomePaciente);

            // faz o nome ficar todo maiusculo...
    strupr( (*posicao).Item.nomePaciente );

}

    // altera o endereço
void AlterEndereco (struct TList List, struct Cell *posicao){

            printf("\n EX: Rua Dom Pedro Nº 12\n");

            setbuf(stdin, NULL);
            printf("\n Informe o endereço do paciente: ");
            gets( (*posicao).Item.endereco );

            setbuf(stdin, NULL);
            printf("\n Informe também o nome do bairro: ");
            gets( (*posicao).Item.bairro );

            setbuf(stdin, NULL);
            printf("\n Informe também o nome da cidade: ");
            gets((*posicao).Item.cidade );
}

    // altera o cpf
void AlterCPF (struct TList List, struct Cell *posicao){

    printf("\n Digite os novos 11 numeros do CPF (sem pontuação): ");
    scanf("%lf", &(*posicao).Item.cpf);

}

    // altera o numero do conveio
void AlterNumeroConvenio (struct TList List, struct Cell *posicao){

    setbuf(stdin, NULL);
    printf("\n Digite o número da matrícula corretamente: ");
    gets( (*posicao).Item.numeroConvenio);

}

    // altera do conveio do paciente
void AlterConvenioEscolhido (struct TList List, struct Cell *posicao, int lerVariavel){

    printf("\n Opções de convênio: ");
    PrintTodosConvenios(); //mostra menu de opcoes de convenio

    printf("\n");
    do{
        printf("\n Informe o número que corresponde ao convênio do paciente: ");
        scanf("%d",&lerVariavel);
    }while(lerVariavel <1 ||lerVariavel >3);
    (*posicao).Item.codConvenioPessoa= lerVariavel - 1;

}

    // altera o numero do conveio
void AlterDataNascimento (struct TList List, struct Cell *posicao){

    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    printf("\n\n Informe a data de nascimento: ");
    scanf("%d", &(*posicao).Item.dataNascimento[0]);
    system("cls");
    tituloCadastro();

    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    printf("\n\n Informe a data de nascimento: %.2d/", (*posicao).Item.dataNascimento[0]);
    scanf("%d", &(*posicao).Item.dataNascimento[1]);
    system("cls");
    tituloCadastro();

    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    printf("\n\n Informe a data de nascimento: %.2d/%.2d/",(*posicao).Item.dataNascimento[0], (*posicao).Item.dataNascimento[1]);
    scanf("%d", &(*posicao).Item.dataNascimento[2]);


}

// altera a temperatura do paciente
void AlterTemperatura (struct TList List, struct Cell *posicao){

    printf("\n\n Informe a temperatura do corpo(em graus): ");
    scanf("%f", &(*posicao).Item.temperaturaPacientes);

}

// altera os batimentos cardiacos
void AlterBC (struct TList List, struct Cell *posicao){

    printf("\n Informe a frequência dos batimentos cardíacos: ");
    scanf("%d", &(*posicao).Item.batimentosCardiacos);

}

// altera a pressão arterial
void AlterPressao (struct TList List, struct Cell *posicao){

    printf("\n Informe a pressão arterial ");
    printf(" (exemplo: 120/80): ");
    scanf("%s", &(*posicao).Item.pressao);

}

 // exporta a lista dinamica (lista de cadastro dos pacientes)
void ExportDataCadastros (struct TList List, struct Element cadastros){
    struct Cell *Aux = NULL;
	Aux = List.First;

	// abre o arquivo txt...
	exportarCadastros = fopen ("Lista de Todos os Pacientes.txt","w");

	fprintf(exportarCadastros, "LISTA DE PACIENTES: \n");

	fprintf(exportarCadastros, "------------------------------------------------------------------------- \n");

	while (Aux != NULL) {

        fprintf(exportarCadastros, "\nNOME DO PACIENTE: %s", (*Aux).Item.nomePaciente);
        fprintf(exportarCadastros, "\nENDEREÇO: %s, bairro: %s, cidade de: %s ", (*Aux).Item.endereco, (*Aux).Item.bairro, (*Aux).Item.cidade);
        fprintf(exportarCadastros, "\nCPF: %.0lf", (*Aux).Item.cpf);
        exportaconvenios(&ListaConvenios, (*Aux).Item.codConvenioPessoa);
        fprintf(exportarCadastros, "\nNUMERO DO CONVÊNIO: %s", (*Aux).Item.numeroConvenio);
        fprintf(exportarCadastros, "\nDATA DE NASCIMENTO: %.2d/%.2d/%.4d", (*Aux).Item.dataNascimento[0], (*Aux).Item.dataNascimento[1],(*Aux).Item.dataNascimento[2] );
        fprintf(exportarCadastros, "\n\nOBSERVACOES SOBRE O PACIENTE:");
        fprintf(exportarCadastros, "\nTEMPERATURA: %.2f°", (*Aux).Item.temperaturaPacientes);
        fprintf(exportarCadastros, "\nBATIMENTOS CARDIACOS: %.2d bpm", (*Aux).Item.batimentosCardiacos);
        fprintf(exportarCadastros, "\nPRESSAO ARTERIAL: %s mmHg", (*Aux).Item.pressao);
        fprintf(exportarCadastros, "\n-------------------------------------------------------------------------");
        fprintf(exportarCadastros, "\n\n");

        Aux = (*Aux).Prox;
	}

	// fecha o arquivo txt...
	fclose(exportarCadastros);

}


// exporta apenas um paciente
void ExportDataPaciente (struct TList List, struct Cell *posicao){
    struct Cell *Aux = NULL;
	Aux = List.First;

        // abre o arquivo txt...
	exportarPaciente= fopen("Dados do Paciente.txt","w");

        //Exporta texto
	fprintf(exportarPaciente, "DADOS DO PACIENTE: \n");

	while (Aux != NULL){

	    if(Aux ==  posicao){
                //Exportação dos dados do paciente escolhido
            fprintf(exportarPaciente, "\nNOME DO PACIENTE: %s", (*Aux).Item.nomePaciente);
            fprintf(exportarPaciente, "\nENDEREÇO: %s, bairro: %s, cidade de: %s ", (*Aux).Item.endereco, (*Aux).Item.bairro, (*Aux).Item.cidade);
            fprintf(exportarPaciente, "\nCPF: %.0lf", (*Aux).Item.cpf);
            exportaconvenioconsulta(&ListaConvenios, (*Aux).Item.codConvenioPessoa);
            fprintf(exportarPaciente, "\nNUMERO DO CONVÊNIO: %s", (*Aux).Item.numeroConvenio);
            fprintf(exportarPaciente, "\nDATA DE NASCIMENTO: %.2d/%.2d/%.4d", (*Aux).Item.dataNascimento[0], (*Aux).Item.dataNascimento[1],(*Aux).Item.dataNascimento[2] );
            fprintf(exportarPaciente, "\n\nOBSERVACOES SOBRE O PACIENTE:");
            fprintf(exportarPaciente, "\nTEMPERATURA: %.2f°", (*Aux).Item.temperaturaPacientes);
            fprintf(exportarPaciente, "\nBATIMENTOS CARDIACOS: %.2d bpm", (*Aux).Item.batimentosCardiacos);
            fprintf(exportarPaciente, "\nPRESSAO ARTERIAL: %s mmHg", (*Aux).Item.pressao);
            fprintf(exportarPaciente, "\n\n");
	    }

        Aux = (*Aux).Prox;
	}
	// fecha o arquivo txt...
	fclose(exportarPaciente);

}


