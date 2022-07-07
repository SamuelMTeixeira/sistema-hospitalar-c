#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

    // exibe mensagem de erro caso não encontre um dado do paciente
void textoErro404 (){
        printf("\n");
        printf("Infelizmente não conseguimos encontrar nenhum paciente com esse dado em nosso banco de dados, verifique se você informou os dados corretamente e tente novamente, senão tente cadastrá-lo primeiro!! \n");
    }

    // imprime texto de erro de número inválido do menu
void mensagemNumeroInvalido (){
    printf("\n\t  Número inválido, informe um valor válido de 1 a 7.\n");
    printf("\t  ");
    system("pause");
    system("cls");
}

    // alerta para perguntar se o usuario deseja continuar...
void alerta(){

        printf("\n                        ---------------------------------------");
        printf("\n                        |           ALERTA IMPORTANTE         |");
        printf("\n                        |                                     |");
        printf("\n                        |        ---------------------        |");
        printf("\n                        |        | [1] Sim | [2] Não |        |");
        printf("\n                        |        ---------------------        |");
        printf("\n                        ---------------------------------------\n");

        printf("                        -> Deseja continuar com o procedimento? ");


}

    // mensagem de texto em desenvolvimento...
void emDesenvolvimento (){
    printf("\n");
    printf("ESTÁ FUNÇÃO AINDA ESTÁ EM DESENVOLVIMENTO, AGUARDE A PRÓXIMA ATUALIZAÇÃO \n");
    system("\n pause");
    system("cls");
}

    // pausa o texto
void PausarPrograma (){
    printf("\nPressione qualquer tecla para voltar ao menu principal...");
    getch();
}

    // exibe mensagem apos exportar o arquivo.
void mensagemExportacaoConcluida (){
    printf("\nAs informações foram exportadas com sucesso! \nPor favor verifique a pasta onde se encontra o programa. \n");
    PausarPrograma();
}

     // exibe texto de cadastro concluido
void mensagemCadastroConcluido (){
    printf("\nO cadastro foi finalizado com sucesso!");
    printf("\nO paciente já foi adicionado à lista de espera e está à espera do médico! \n");
}

