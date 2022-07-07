#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#include "mensagensDeAvisos.h"
#include "cabecalhosDoPrograma.h"
#include "ListaEstaticaConvenios.h"
#include "ListaDinamicaCadastros.h"
#include "Stack.h"
#include "Queue.h"
#include "bibliotecaConio.h"
#include "telaCarregamento.h"

// função que dá efeito ao selecionar opção no menu principal
void OnClick (int x, int y, int numFuncao){
    // posiciona o cursor na tela
    gotoxy(x,y);
    // insere as cores do efeito
    textbackground(15);
    textcolor(1);
    _setcursortype(_NOCURSOR);
    if(numFuncao ==1 ){
        printf("[1] Cadastro                \n");
    }
    if(numFuncao ==2 ){
        printf("[2] Consultas               \n");
    }
    if(numFuncao ==3 ){
        printf("[3] Manutenção              \n");
    }
    if(numFuncao ==4 ){
        printf("[4] Relatórios Sintéticos   \n");
    }
    if(numFuncao ==5 ){
        printf("[5] Relatórios Analíticos   \n");
    }
    if(numFuncao ==6 ){
        printf("[6] Exportação de Dados     \n");
    }
    if(numFuncao ==7 ){
        printf("[7] Sair                    \n");
    }

    // dealy para pode perceber o descolacamento
    Sleep(30);

    // desloca o txt acima para a esquerda
    gotoxy(x-1,y);
    _setcursortype(_NOCURSOR);
    if(numFuncao ==1 ){
        printf("[1] Cadastro                \n");
    }
    if(numFuncao ==2 ){
        printf("[2] Consultas               \n");
    }
    if(numFuncao ==3 ){
        printf("[3] Manutenção              \n");
    }
    if(numFuncao ==4 ){
        printf("[4] Relatórios Sintéticos   \n");
    }
    if(numFuncao ==5 ){
        printf("[5] Relatórios Analíticos   \n");
    }
    if(numFuncao ==6 ){
        printf("[6] Exportação de Dados     \n");
    }
    if(numFuncao ==7 ){
        printf("[7] Sair                    \n");
    }




    Sleep(80);

    textbackground(7);
    system("cls");
    textcolor(1);

    // ativa o cursor
    _setcursortype(_NORMALCURSOR);
}

// função que dá efeito ao selecionar opção de sim ou não no menu alerta
void OnClickAlerta (int x, int y, int numFuncao){
    // posiciona o cursor na tela
    gotoxy(x,y);
    // insere as cores do efeito
    textbackground(15);
    textcolor(4);
    _setcursortype(_NOCURSOR);
    if(numFuncao ==1 ){
        printf("[1] Sim ");

    }
    if(numFuncao ==2 ){
        printf("[2] Não ");
    }


    // dealy para pode perceber o descolacamento
    Sleep(30);

    // desloca o txt acima para a esquerda
    gotoxy(x-1,y);
    _setcursortype(_NOCURSOR);
    if(numFuncao ==1 ){
        printf("[1] Sim ");

    }
    if(numFuncao ==2 ){
        printf("[2] Não ");
    }

    Sleep(80);

    textbackground(7);
    system("cls");
    textcolor(1);

    // ativa o cursor
    _setcursortype(_NORMALCURSOR);
}

// exibe a tela de carregamento do programa
void telaInicial(){
    textbackground(7);
    system("cls");

    textcolor(1);
    // desativa o cursor
    _setcursortype(_NOCURSOR);

    printf("\n                SISTEMA DE GERENCIAMENTO DE FICHAS HOSPITALARES");
    printf("\n--------------------------------------------------------------------------------");
    printf("\n                                      MENU                                      \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");

    menuCarregamento();

}

// declarando as variaveis da fila....
struct ElementFila  dadosFilaDeEspera;
struct TQueue       listaDeEspera;

// definindo a biblioteca "ListDynamicCadastro.h" como variaveis globais
struct TList listaCadastros;
struct Element cadastros;
struct Cell *procurarPorCPF;

    //Definindo pilha 1 de nomes
struct TStack PilhaNomes;
struct Element3 Identificacao;
int tamanho;

    //Definindo pilha 2 de nomes
struct TStack PilhaNomes2;
struct Element3 Identificacao2;

    // parte para cadastrar os convenios
char nomeConvenio [3][100];
void cadastroConvenio() {
    printf("\nCADASTRE O NOME DOS 3 CONVÊNIOS:\n\n");
    for(int i=0; i<3;i++){
        setbuf(stdin, NULL);
        printf("\nInsira o %d nome do novo convênio: ", i+1);
        gets(nomeConvenio[i]);
    }
        printf("\n");
        printf("\n--------------------------------------------------------------------------------");
        printf("\nCADASTRO CONCLUÍDO COM SUCESSO!! \n");
        PausarPrograma();
}

    // variavel pra armazenar dia, mes e ano...
int d, m, a;
    //cadastra a data do atendimento no momento que o cadastro é feito
void atualizarData(){
    //ponteiro para struct que armazena data e hora
  struct tm *data_atual;

  //variável do tipo time_t para armazenar o tempo em segundos
  time_t segundos;

  //obtendo o tempo em segundos
  time(&segundos);

  //converte de segundos para o tempo local
  data_atual = localtime(&segundos);

  // armazena o dia atual
  d= data_atual->tm_mday;
  m= data_atual->tm_mon+1;
  a= data_atual->tm_year+1900;
}

    // registro para as funções do menu principal
struct variaveisMenu {
    int opcoes;
    int voltar;
    int tipoescolha;
    int codC;
    double opcExport;
    int dataDoAtendimento[3];
}vMenu;

    // imprime e recebe a entrada do menu para o usuário...
void entradasMenuPrincipal (){
    setbuf(stdin, NULL);
    printf("\n\t  -> Insira o valor correspondente à função desejada: ");
    scanf("%d", &vMenu.opcoes);

    if(vMenu.opcoes ==1 ){
        OnClick(13,7, 1);
    }
    if(vMenu.opcoes ==2 ){
        OnClick(42,7, 2);
    }
    if(vMenu.opcoes ==3 ){
        OnClick(13,8, 3);
    }
    if(vMenu.opcoes ==4 ){
        OnClick(42,8, 4);
    }
    if(vMenu.opcoes ==5 ){
        OnClick(13,9, 5);
    }
    if(vMenu.opcoes ==6 ){
        OnClick(42,9, 6);
    }
    if(vMenu.opcoes ==7 ){
        OnClick(13,10, 7);
    }

}

     // IMPRIME A ENTRADA PERGUNTANDO SE DESEJA VOLTAR OU NÃO PARA O MENU PRINCIPAL
void voltarParaMenuPrincipal () {
    scanf("%d", &vMenu.voltar);
     if(vMenu.voltar ==1 ){
        OnClickAlerta(36,9, 1);
    }
    if(vMenu.voltar ==2 ){
        OnClickAlerta(46,9, 2);
    }
}

    // registro para as variaveis da manutenção
struct variaveisManutencao {
    int entrada;
    int numID;
    double cpf;
    int opc;
} vManutencao;

 //  Imprime as entradas do cadastro
void cadastrarPaciente(){
    system("cls");
    tituloCadastro();
    atualizarData();

    cadastros.dia = d;
    cadastros.mes = m;
    cadastros.ano = a;

    setbuf(stdin, NULL);
    printf("\n Informe o nome do paciente: ");

    SetConsoleCP(1252);
    gets(cadastros.nomePaciente);
    SetConsoleOutputCP(1252);

    // faz o nome ficar todo maiusculo...
    strupr(cadastros.nomePaciente);

    // copia o nome da pessoa para inserir na lista de espera
    strcpy (dadosFilaDeEspera.nome, cadastros.nomePaciente);

    system("cls");
    tituloCadastro();
    textcolor(4);
    printf("\n EX: Rua Dom Pedro Nº 12\n");
    textcolor(1);

    setbuf(stdin, NULL);
    printf("\n Informe o endereço do paciente: ");

    SetConsoleCP(1252);
    gets(cadastros.endereco);
    SetConsoleOutputCP(1252);

    setbuf(stdin, NULL);
    printf("\n Informe também o nome do bairro: ");

    SetConsoleCP(1252);
    gets(cadastros.bairro);
    SetConsoleOutputCP(1252);

    setbuf(stdin, NULL);
    printf("\n Informe também o nome da cidade: ");

    SetConsoleCP(1252);
    gets(cadastros.cidade);
    SetConsoleOutputCP(1252);

    system("cls");
    tituloCadastro();

    printf("\n Digite os 11 numeros do CPF");
    textcolor(4);
    printf("(sem pontuação)");
    textcolor(1);
    printf(": ");

    scanf("%lf", &cadastros.cpf);
    dadosFilaDeEspera.cpf = cadastros.cpf;

    system("cls");
    tituloCadastro();

    printf("\n Opções de convênio: ");
    PrintTodosConvenios(); //mostra menu de opcoes de convenio

    printf("\n");
    do{
        printf("\n Informe o número que corresponde ao convênio do paciente: ");
        scanf("%d",&vMenu.codC);
    }while(vMenu.codC <1 || vMenu.codC >3);
    cadastros.codConvenioPessoa= vMenu.codC;

    setbuf(stdin,NULL);
    printf("\n\n Informe o número da matrícula do convênio: ");
    gets(cadastros.numeroConvenio);

    system("cls");
    tituloCadastro();
    textcolor(4);
    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    textcolor(1);
    printf("\n\n Informe a data de nascimento: ");
    scanf("%d", &cadastros.dataNascimento[0]);
    system("cls");
    tituloCadastro();

    textcolor(4);
    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    textcolor(1);
    printf("\n\n Informe a data de nascimento: %.2d/", cadastros.dataNascimento[0]);
    scanf("%d", &cadastros.dataNascimento[1]);
    system("cls");
    tituloCadastro();

    textcolor(4);
    printf("\n DIGITE APENAS NÚMEROS!! (NA SEGUINTE SEQUÊNCIA DD/MM/AAAA)*");
    textcolor(1);
    printf("\n\n Informe a data de nascimento: %.2d/%.2d/", cadastros.dataNascimento[0], cadastros.dataNascimento[1]);
    scanf("%d", &cadastros.dataNascimento[2]);

    system("cls");
    tituloCadastro();

    printf("\n OBSERVAÇÕES SOBRE O ESTADO DO PACIENTE ");
    printf("\n\n Informe a temperatura do corpo(em graus): ");
    scanf("%f", &cadastros.temperaturaPacientes);

    printf("\n Informe a frequência dos batimentos cardíacos: ");
    scanf("%d", &cadastros.batimentosCardiacos);

    printf("\n Informe a pressão arterial ");
    textcolor(4);
    printf(" (exemplo: 120/80): ");
    textcolor(1);

    SetConsoleCP(1252);
    scanf("%s", &cadastros.pressao);
    SetConsoleOutputCP(1252);

    Enqueue(dadosFilaDeEspera, &listaDeEspera);
    InsertList(cadastros, &listaCadastros);

    system("cls");
    tituloCadastro();
    mensagemCadastroConcluido();

}

    // exporta os arquivos
void exportar (){
    do{
        system("cls");
        tituloExportacaoDados();
        exportacaoEscolhas();
        scanf("%d", &vManutencao.opc);

        if(vManutencao.opc == 1){
             ExportDataConvenios(ListaConvenios);
             system("cls");
             tituloExportacaoDados();
             mensagemExportacaoConcluida();
        }

        else if (vManutencao.opc == 2){
            ExportDataCadastros(listaCadastros, cadastros);
            system("cls");
            tituloExportacaoDados();
            mensagemExportacaoConcluida();
        }
        else if (vManutencao.opc == 3){
            printf("  -> Informe o CPF do paciente: ");
            scanf("%lf", &vMenu.opcExport);

            FindElement(listaCadastros, vMenu.opcExport);
            procurarPorCPF =FindPos(listaCadastros, vMenu.opcExport);
            if (procurarPorCPF != NULL){
                ExportDataPaciente(listaCadastros, procurarPorCPF);
                system("cls");
                tituloExportacaoDados();
                mensagemExportacaoConcluida();
            }
            else {
                PausarPrograma();
            }
        }

        else {
            system("cls");
            tituloExportacaoDados();
            printf("Valor Inválido, por favor informe um valor correto\n");
        }

    }while(vManutencao.opc < 1 || vManutencao.opc > 3);
}

    // stwitch que executa a parte da manutenção
void switchManutencao (){
    switch(vManutencao.entrada){
            case 1 :
                system("cls");
                tituloManutencao();
                AlterName(listaCadastros, procurarPorCPF);

                // faz o nome ficar todo maiusculo...
                strupr(cadastros.nomePaciente);

                manutencaoTextoConclusao ();
                break;

            case 2 :
                system("cls");
                tituloManutencao();
                AlterEndereco(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;

            case 3 :
                system("cls");
                tituloManutencao();
                AlterCPF(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;

            case 4 :
                system("cls");
                tituloManutencao();
                AlterConvenioEscolhido(listaCadastros, procurarPorCPF, vMenu.codC);

                manutencaoTextoConclusao ();
                break;

            case 5 :
                system("cls");
                tituloManutencao();
                setbuf(stdin,NULL);
                AlterNumeroConvenio(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;
            case 6 :
                system("cls");
                tituloManutencao();
                AlterDataNascimento (listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;
            case 7 :
                system("cls");
                tituloManutencao();
                AlterTemperatura(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;
            case 8 :
                system("cls");
                tituloManutencao();
                AlterBC(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;
            case 9 :
                system("cls");
                tituloManutencao();
                AlterPressao(listaCadastros, procurarPorCPF);

                manutencaoTextoConclusao ();
                break;
            }
}

    // programa principal...
int main()
{
    int pessoasAtendidas= 0;
    int escolha, op; //variáveis de escolha e opções
    double cpfconsulta;
    int c = 0, c1 =0;

    InitializeQueue (&listaDeEspera);
    InitializeList(&listaCadastros);
    Iniciarlista(&ListaConvenios);
    InitializeStack(&PilhaNomes);
    InitializeStack(&PilhaNomes2);

    setlocale(LC_ALL, "Portuguese");

    telaInicial();

     // ativa o cursor
    _setcursortype(_NORMALCURSOR);

    do{
    // retorna o tamanho da lista de espera
    int tamanhoDaLista = LenghtQueue(listaDeEspera);

    menu();
    entradasMenuPrincipal();
    // menu sendo chamado...
    switch (vMenu.opcoes) {

        case 1:
                do{
                    tituloCadastro();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    // ENTRADA PERGUNTA SE DESEJA VOLTAR OU NÃO PARA O MENU PRINCIPAL
                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");

                        break;
                    }
                    else if(vMenu.voltar == 1){
                        //executa o cadastro...
                        system("cls");
                        tituloCadastro();
                        cadastrosEscolhas();
                        scanf("%d", &escolha);
                        switch (escolha){
                            case 1:
                                system("cls");
                                tituloCadastro();
                                //cadastra os convenios do hospital
                                cadastroconvenio();
                                break;
                            case 2:
                                system("cls");
                                tituloCadastro();
                                // pega a data que o cadastro está sendo feito (data do atendimento)
                                atualizarData();
                                // executa o cadastro...
                                cadastrarPaciente(listaCadastros, cadastros);
                                 break;
                            case 3:
                                system("cls");
                                tituloCadastro();
                                // executa o cadastro...
                                setbuf(stdin, NULL);
                                if (c1 >=2){
                                    printf("Limite de atendentes atingido, é permitido o cadastro de apenas 2 atendentes por dia.");
                                }
                                else{

                                    printf("Informe o nome do(a) atendente que está utilizando o sistema: ");
                                    gets(Identificacao.Nome);
                                    Push(Identificacao, &PilhaNomes);
                                    c1++;
                                }

                                break;


                        }
                        PausarPrograma();

                    }
                }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                break;

        case 2:
                do{
                    system("cls");
                    tituloConsultas ();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");
                        break;
                    }
                    else if(vMenu.voltar == 1){
                        system("cls");
                        consultaescolhas();
                        scanf("%d", &escolha);
                        switch (escolha){
                            case 1:
                                system("cls");
                                tituloConsultas();
                                Iniciarlista(&ListaConvenios);
                                //consulta convenios do hospital
                                printf("\nInforme o convênio que deseja consultar: ");
                                scanf("%d", &op);

                                printf("\nConvênio consultado: ");
                                consultaconvenio(ListaConvenios,op);
                                break;
                            case 2:
                                system("cls");
                                tituloConsultas();

                                printf("\nInfome o CPF da pessoa que você deseja consultar: ");
                                scanf("%lf", &cpfconsulta);

                                FindElement(listaCadastros, cpfconsulta);
                                procurarPorCPF= FindPos(listaCadastros, cpfconsulta);
                                if (procurarPorCPF != NULL){
                                    system("cls");
                                    tituloConsultas();
                                    PrintPaciente(listaCadastros, procurarPorCPF);
                                }
                                break;

                                case 3:
                                    system("cls");
                                    tituloConsultas();
                                    printf("\n %d PESSOAS FORAM ATENDIDAS ATÉ O MOMENTO.", pessoasAtendidas);
                                    printf("\n %d PESSOAS ESTÃO AGUARDANDO AO MÉDICO \n", tamanhoDaLista);
                                break;

                            case 4:

                                system("cls");
                                tituloConsultas();
                                printf("\nInforme o atendente que deseja consultar[1 ou 2]: ");
                                scanf("%d", &op);

                                if (op == 1){

                                        if(c == 0 && c1 > 1){
                                                //remove do topo da pilha na primeira vez
                                            Pop(&Identificacao, &PilhaNomes);
                                        }

                                        if(c1 > 1){//Se for mais de uma atendente cadastrada

                                                //Copia o texto de uma pilha 1 para a pilha 2
                                            strcpy(Identificacao2.Nome, Identificacao.Nome);
                                            Push(Identificacao2, &PilhaNomes2); //Insere na pilha 2
                                            Pop(&Identificacao, &PilhaNomes);// Remove da pilha 1
                                        }
                                        if(c1 == 0){
                                            printf("\nAtendente 1 não cadastrado.");
                                        }
                                        else{
                                           printf("\nAtendente-> %s", Identificacao.Nome);
                                        }

                                        if(c1 > 1){//Se for mais de uma atendente cadastrada

                                                //Copia o texto de uma pilha 1 para a pilha 2
                                            strcpy(Identificacao2.Nome, Identificacao.Nome);

                                                //Reempilha na pilha 1 os mesmos dados
                                            strcpy(Identificacao.Nome,Identificacao2.Nome);
                                            Push(Identificacao, &PilhaNomes);

                                            Pop(&Identificacao2, &PilhaNomes2);

                                                //Reempilha na pilha 1 os mesmos dados
                                            strcpy(Identificacao.Nome,Identificacao2.Nome);
                                            c++;
                                        }

                                }
                                else if(op == 2){
                                    if(c1 <=1){
                                        printf("\nAtendente 2 não cadastrado.");
                                    }
                                    else{

                                        printf("\nAtendente-> %s", Identificacao.Nome);
                                    }
                                }
                            }
                            PausarPrograma();
                    }
                }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                 break;

        case 3:
                do{
                    system("cls");
                    tituloManutencao();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");
                        break;
                    }
                    else if(vMenu.voltar == 1){
                        //executa a manutenção...
                        system("cls");
                        tituloManutencao();
                        manutencaoescolhas();
                        scanf("%d", &escolha);
                        switch (escolha){
                            case 1:
                                system("cls");
                                tituloManutencao();
                                //opcoes de convenio para alterar
                                PrintTodosConvenios();
                                printf("\n");
                                //manutenção dos convenios do hospital
                                printf("\nInforme o convênio que deseja alterar: ");
                                scanf("%d", &op);

                                // Função para realizar a manutenção
                                manutencaoconvenio(&ListaConvenios, op);
                                break;
                            case 2:
                                system("cls");
                                tituloManutencao();
                                printf("\n  -%c Informe o CPF do paciente: ", 16);
                                scanf("%lf", &cpfconsulta);
                                FindElement(listaCadastros, cpfconsulta);
                                procurarPorCPF= FindPos(listaCadastros, cpfconsulta);

                                if (procurarPorCPF != NULL){
                                    system("cls");
                                    tituloManutencao();
                                    manutencaoOpcoes();
                                    scanf("%d", &vManutencao.entrada);
                                    switchManutencao();
                                }

                                break;
                            case 3:
                                system("cls");
                                tituloManutencao();
                                // É um Dequeue, porém com sáida de dadoos
                                PrintOutPerson(&listaDeEspera, dadosFilaDeEspera);
                                Sleep(30);

                                printf(" Tudo certo! O paciente foi chamado e foi retirado da lista de espera \n");

                                // contador de pessoas quue já foram atendidas pelo médico
                                pessoasAtendidas++;
                                break;
                            case 4:
                                system("cls");
                                tituloManutencao();

                                printf("\nInforme o atendente que deseja alterar[1 ou 2]: ");
                                scanf("%d", &op);

                                if (op == 1){

                                        if(c == 0 && c1 > 1){
                                                //remove do topo da pilha na primeira vez
                                            Pop(&Identificacao, &PilhaNomes);
                                        }

                                        if(c1 > 1){//Se for mais de uma atendente cadastrada

                                                //Copia o texto de uma pilha 1 para a pilha 2
                                            strcpy(Identificacao2.Nome, Identificacao.Nome);
                                            Push(Identificacao2, &PilhaNomes2); //Insere na pilha 2
                                            Pop(&Identificacao, &PilhaNomes);// Remove da pilha 1
                                        }

                                        setbuf(stdin, NULL);
                                        printf("\nInforme o novo nome do(a) novo(a) antendente:");
                                        gets(Identificacao.Nome);

                                        if(c1 > 1){//Se for mais de uma atendente cadastrada

                                                //Copia o texto de uma pilha 1 para a pilha 2
                                            strcpy(Identificacao2.Nome, Identificacao.Nome);

                                                //Reempilha na pilha 1 os mesmos dados
                                            strcpy(Identificacao.Nome,Identificacao2.Nome);
                                            Push(Identificacao, &PilhaNomes);

                                            Pop(&Identificacao2, &PilhaNomes2);

                                                //Reempilha na pilha 1 os mesmos dados
                                            strcpy(Identificacao.Nome,Identificacao2.Nome);

                                        }

                                }
                                else if(op == 2){

                                        //Copia o texto de uma pilha 1 para a pilha 2


                                        setbuf(stdin, NULL);
                                        printf("\nInforme o novo nome do(a) novo(a) antendente:");
                                        gets(Identificacao.Nome);

                                            //Copia o texto de uma pilha 1 para a pilha 2
                                        strcpy(Identificacao2.Nome, Identificacao.Nome);
                                        Push(Identificacao2, &PilhaNomes2); //Insere na pilha 2
                                        Pop(&Identificacao, &PilhaNomes);// Remove da pilha 1

                                            //Copia o texto de uma pilha 1 para a pilha 2
                                        strcpy(Identificacao2.Nome, Identificacao.Nome);

                                            //Reempilha na pilha 1 os mesmos dados
                                        strcpy(Identificacao.Nome,Identificacao2.Nome);
                                        Push(Identificacao, &PilhaNomes);

                                        Pop(&Identificacao2, &PilhaNomes2);

                                            //Reempilha na pilha 1 os mesmos dados
                                        strcpy(Identificacao.Nome,Identificacao2.Nome);
                                }

                        }
                        PausarPrograma();

                    }
                }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                break;

        case 4:
                do{
                    system("cls");
                    tituloRalatoriosSinteticos();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");
                        break;
                    }
                    else if(vMenu.voltar == 1){
                        system("cls");
                        tituloRalatoriosSinteticos();
                        relatoriossescolha();
                        scanf("%d", &escolha);
                        switch (escolha){
                            case 1:
                                system("cls");
                                tituloRalatoriosSinteticos();
                                //relatorios sinteticos dos convenios do hospital
                                printf("\nTodos os convênios do hospital: ");
                                PrintTodosConvenios();

                                break;
                            case 2:
                                system("cls");
                                tituloRalatoriosSinteticos();
                                //relatorios sinteticos dos pacientes do hospital
                                PrintListCadastros(listaCadastros);

                                break;
                            case 3:
                                system("cls");
                                tituloRalatoriosSinteticos();
                                int n;
                                PrintQueue(listaDeEspera, dadosFilaDeEspera);
                                pessoasAtendidas+=n;
                                break;
                            case 4:
                                system("cls");
                                tituloRalatoriosSinteticos();
                                printf("\nAtendentes cadastrados: ");

                                if(c == 0 && c1 > 1){
                                        //remove do topo da pilha na primeira vez
                                    Pop(&Identificacao, &PilhaNomes);
                                }

                                if(c1 > 1){//Se for mais de uma atendente cadastrada

                                        //Copia o texto de uma pilha 1 para a pilha 2
                                    strcpy(Identificacao2.Nome, Identificacao.Nome);
                                    Push(Identificacao2, &PilhaNomes2); //Insere na pilha 2
                                    Pop(&Identificacao, &PilhaNomes);// Remove da pilha 1
                                }


                                printf("\n%s", Identificacao.Nome);


                                if(c1 > 1){//Se for mais de uma atendente cadastrada

                                        //Copia o texto de uma pilha 1 para a pilha 2
                                    strcpy(Identificacao2.Nome, Identificacao.Nome);

                                        //Reempilha na pilha 1 os mesmos dados
                                    strcpy(Identificacao.Nome,Identificacao2.Nome);
                                    Push(Identificacao, &PilhaNomes);

                                    Pop(&Identificacao2, &PilhaNomes2);

                                        //Reempilha na pilha 1 os mesmos dados
                                    strcpy(Identificacao.Nome,Identificacao2.Nome);

                                }

                                printf("\n%s", Identificacao.Nome);

                                //Copia o texto de uma pilha 1 para a pilha 2
                                strcpy(Identificacao2.Nome, Identificacao.Nome);
                                Push(Identificacao2, &PilhaNomes2); //Insere na pilha 2
                                Pop(&Identificacao, &PilhaNomes);// Remove da pilha 1

                                    //Copia o texto de uma pilha 1 para a pilha 2
                                strcpy(Identificacao2.Nome, Identificacao.Nome);

                                    //Reempilha na pilha 1 os mesmos dados
                                strcpy(Identificacao.Nome,Identificacao2.Nome);
                                Push(Identificacao, &PilhaNomes);

                                Pop(&Identificacao2, &PilhaNomes2);

                                    //Reempilha na pilha 1 os mesmos dados
                                strcpy(Identificacao.Nome,Identificacao2.Nome);


                                if(c1 == 0){
                                    system("cls");
                                    tituloRalatoriosSinteticos();
                                    printf("\nNenhum atendente foi cadastrado.");
                                }
                        }
                        PausarPrograma();
                    }
                }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                break;

        case 5:
                do{
                    system("cls");
                    tituloRelatoriosAnalitico();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");
                        break;
                    }
                    else if(vMenu.voltar == 1){

                        system("cls");
                        tituloRelatoriosAnalitico();
                        emDesenvolvimento();
                    }

                }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                break;

        case 6:
                do{
                    system("cls");
                    tituloExportacaoDados();

                    // coloca o alerta na cor vermelha
                    textcolor(4);
                    alerta();
                    textcolor(1);

                    voltarParaMenuPrincipal();

                    if(vMenu.voltar == 2){
                    // volta para o menu principal...
                        system("cls");
                        break;
                    }
                    else if(vMenu.voltar == 1){

                        system("cls");
                        tituloExportacaoDados();
                        exportar();


                    }
                 }while(vMenu.voltar!= 1 && vMenu.voltar!= 2);
                break;

        case 7:
               break;
        default :
                system("cls");
                menu();
                mensagemNumeroInvalido();
                break;

        }

    } while(vMenu.opcoes!=7);
    system("cls");
    printf("--------------------------------------------------------------------------------");
    printf("\n                              PROGRAMA FINALIZADO!\n");
    printf("--------------------------------------------------------------------------------");

    return 0;
}
