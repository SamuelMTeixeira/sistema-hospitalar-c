#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

    // imprime os cabeçalhos        "menu > nome"
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
                    printf("\n                                      MENU > MANUTENÇÃO\n");
                    printf("--------------------------------------------------------------------------------\n");
}
void tituloRalatoriosSinteticos (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > RELATÓRIOS SINTETÉTICOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloRelatoriosAnalitico (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > RELATÓRIOS ANALÍTICOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}
void tituloExportacaoDados (){
                    printf("--------------------------------------------------------------------------------");
                    printf("\n                                      MENU > EXPORTAÇÃO DE DADOS\n");
                    printf("--------------------------------------------------------------------------------\n");

}

    // tabela do menu construída...
void menu (){
        system("cls");
        printf("\n                SISTEMA DE GERENCIAMENTO DE FICHAS HOSPITALARES");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n                                      MENU                                      \n");
        printf("--------------------------------------------------------------------------------\n");

        printf("          ------------------------------------------------------------\n");
        printf("          | [1] Cadastro                |  [2] Consultas             |\n");
        printf("          | [3] Manutenção              |  [4] Relatórios Sintéticos |\n");
        printf("          | [5] Relatórios Analíticos   |  [6] Exportação de Dados   |\n");
        printf("          | [7] Sair do Programa        |                            |\n");
        printf("          ------------------------------------------------------------\n");

    }

    //  exibe as opções disponiveis para cadastrar
void cadastrosEscolhas (){
        printf("\n  Escolha uma das opções abaixo:");
        printf("\n  -------------------------------------------------------------------");
        printf("\n  | [1]Cadastrar convênios                                          |");
        printf("\n  | [2]Cadastrar dados do paciente                                  |");
        printf("\n  | [3]Cadastrar nome do(a) atendente                               |");
        printf("\n  -------------------------------------------------------------------");
        printf("\n  -> Informe a sua escolha: ");

}


//  exibe as opções disponiveis para fazer manutenção
void manutencaoescolhas(){
    printf("\nEscolha uma das opções abaixo:");
    printf("\n  ------------------------------------------------------------");
    printf("\n  | [1] Fazer manutenção dos convênios                       |");
    printf("\n  | [2] Fazer manutenção dos dados do paciente               |");
    printf("\n  | [3] Andar com a fila de espera (chamar próximo paciente) |");
    printf("\n  | [4] Fazer manutençaõ dos atendentes cadastrados          |");
    printf("\n  ------------------------------------------------------------");
    printf("\n  -> Informe a sua escolha: ");
}

//  exibe as opções disponiveis para consultar
void consultaescolhas(){
    printf("\nEscolha uma das opções abaixo:");
    printf("\n  ----------------------------------------");
    printf("\n  | [1]Consultar convênios               |");
    printf("\n  | [2]Consultar dados do paciente       |");
    printf("\n  | [3]Ver status da lista de espera     |");
    printf("\n  | [4]Consultar atendentes cadastrados  |");
    printf("\n  ----------------------------------------");
    printf("\n  -> Informe a sua escolha: ", 16);
}

//  exibe as opções disponiveis para visualizar
void relatoriossescolha(){
    printf("\nEscolha uma das opções abaixo:");
    printf("\n  -------------------------------------------------");
    printf("\n  | [1] Visualizar todos os convênios             |");
    printf("\n  | [2] Visualizar os dados de todos os pacientes |");
    printf("\n  | [3] Visualizar a lista de espera              |");
    printf("\n  | [4] Visualizar atendentes cadastrados         |");
    printf("\n  -------------------------------------------------");
    printf("\n  -> Informe a sua escolha: ");

}

     //  exibe as opções disponiveis para exportar
void exportacaoEscolhas (){
     printf("\n -----------------------------------------------------------------");
     printf("\n | [1] EXPORTAR A LISTA DE CONVÊNIOS                             |");
     printf("\n | [2] EXPORTAR A LISTA DE TODOS OS PACIENTES CADASTRADOS        |");
     printf("\n | [3] EXPORTAR A LISTA DE UM PACIENTES ESPECIFICO               |");
     printf("\n -----------------------------------------------------------------");
     printf("\n  -> Qual opção você deseja exportar: ");

}


void manutencaoOpcoes (){
    setlocale(LC_ALL,"Portuguese");
    printf("\n");
    printf("\n [1]  Nome do paciente");
    printf("\n [2]  Endereço");
    printf("\n [3]  Número do CPF");
    printf("\n [4]  Nome do Convênio");
    printf("\n [5]  Número do Convênio");
    printf("\n [6]  Data de nascimento");
    printf("\n [7]  Temperatura do paciente");
    printf("\n [8]  Batimentos cardíacos");
    printf("\n [9]  Pressão Arterial");

    printf("\n\n  -> Qual opção você deseja alterar? ");
}


void manutencaoTextoConclusao (){
    printf("\n\n");
    printf("\n--------------------------------------------------------------------------------");
    printf("\nALTERAÇÃO CONCLUÍDA COM SUCESSO!! \n");
}



