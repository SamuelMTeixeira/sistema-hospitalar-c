#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

    // imprime os cabe�alhos        "menu > nome"
void tituloCadastro() {
    system("cls");
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > CADASTRO\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloConsultas (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > CONSULTAS\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloManutencao (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > MANUTEN��O\n");
                    printf("--------------------------------------------------------------------------------\n");
}
void tituloRalatoriosSinteticos (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > RELAT�RIOS SINTET�TICOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloRelatoriosAnalitico (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > RELAT�RIOS ANAL�TICOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloExportacaoDados (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > EXPORTA��O DE DADOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}

    // tabela do menu constru�da...
void menu (){
        system("cls");
        printf("\n                SISTEMA DE GERENCIAMENTO DE FICHAS HOSPITALARES");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n                                      MENU                                      \n");
        printf("--------------------------------------------------------------------------------\n");

        printf("          ------------------------------------------------------------\n");
        printf("          | [1] Cadastro                |  [2] Consultas             |\n");
        printf("          | [3] Manuten��o              |  [4] Relat�rios Sint�ticos |\n");
        printf("          | [5] Relat�rios Anal�ticos   |  [6] Exporta��o de Dados   |\n");
        printf("          | [7] Sair do Programa        |                            |\n");
        printf("          ------------------------------------------------------------\n");

    }

    //  exibe as op��es disponiveis para cadastrar
void cadastrosEscolhas (){
        printf("\n  Escolha uma das op��es abaixo:");
        printf("\n  -------------------------------------------------------------------");
        printf("\n  | [1]Cadastrar conv�nios                                          |");
        printf("\n  | [2]Cadastrar dados do paciente                                  |");
        printf("\n  | [3]Cadastrar nome do(a) atendente                               |");
        printf("\n  -------------------------------------------------------------------");
        printf("\n  -> Informe a sua escolha: ");

}


//  exibe as op��es disponiveis para fazer manuten��o
void manutencaoescolhas(){
    printf("\nEscolha uma das op��es abaixo:");
    printf("\n  ------------------------------------------------------------");
    printf("\n  | [1] Fazer manuten��o dos conv�nios                       |");
    printf("\n  | [2] Fazer manuten��o dos dados do paciente               |");
    printf("\n  | [3] Andar com a fila de espera (chamar pr�ximo paciente) |");
    printf("\n  | [4] Fazer manuten�a� dos atendentes cadastrados          |");
    printf("\n  ------------------------------------------------------------");
    printf("\n  -> Informe a sua escolha: ");
}

//  exibe as op��es disponiveis para consultar
void consultaescolhas(){
    printf("\nEscolha uma das op��es abaixo:");
    printf("\n  ----------------------------------------");
    printf("\n  | [1]Consultar conv�nios               |");
    printf("\n  | [2]Consultar dados do paciente       |");
    printf("\n  | [3]Ver status da lista de espera     |");
    printf("\n  | [4]Consultar atendentes cadastrados  |");
    printf("\n  ----------------------------------------");
    printf("\n  -> Informe a sua escolha: ", 16);
}

//  exibe as op��es disponiveis para visualizar
void relatoriossescolha(){
    printf("\nEscolha uma das op��es abaixo:");
    printf("\n  -------------------------------------------------");
    printf("\n  | [1] Visualizar todos os conv�nios             |");
    printf("\n  | [2] Visualizar os dados de todos os pacientes |");
    printf("\n  | [3] Visualizar a lista de espera              |");
    printf("\n  | [4] Visualizar atendentes cadastrados         |");
    printf("\n  -------------------------------------------------");
    printf("\n  -> Informe a sua escolha: ");

}

     //  exibe as op��es disponiveis para exportar
void exportacaoEscolhas (){
     printf("\n -----------------------------------------------------------------");
     printf("\n | [1] EXPORTAR A LISTA DE CONV�NIOS                             |");
     printf("\n | [2] EXPORTAR A LISTA DE TODOS OS PACIENTES CADASTRADOS        |");
     printf("\n | [3] EXPORTAR A LISTA DE UM PACIENTES ESPECIFICO               |");
     printf("\n -----------------------------------------------------------------");
     printf("\n  -> Qual op��o voc� deseja exportar: ");

}


void manutencaoOpcoes (){
    setlocale(LC_ALL,"Portuguese");
    printf("\n");
    printf("\n [1]  Nome do paciente");
    printf("\n [2]  Endere�o");
    printf("\n [3]  N�mero do CPF");
    printf("\n [4]  Nome do Conv�nio");
    printf("\n [5]  N�mero do Conv�nio");
    printf("\n [6]  Data de nascimento");
    printf("\n [7]  Temperatura do paciente");
    printf("\n [8]  Batimentos card�acos");
    printf("\n [9]  Press�o Arterial");

    printf("\n\n  -> Qual op��o voc� deseja alterar? ");
}


void manutencaoTextoConclusao (){
    printf("\n\n");
    printf("\n--------------------------------------------------------------------------------");
    printf("\nALTERA��O CONCLU�DA COM SUCESSO!! \n");
}



