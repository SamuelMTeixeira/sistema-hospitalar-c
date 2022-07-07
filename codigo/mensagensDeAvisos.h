#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

    // exibe mensagem de erro caso n�o encontre um dado do paciente
void textoErro404 (){
        printf("\n");
        printf("Infelizmente n�o conseguimos encontrar nenhum paciente com esse dado em nosso banco de dados, verifique se voc� informou os dados corretamente e tente novamente, sen�o tente cadastr�-lo primeiro!! \n");
    }

    // imprime texto de erro de n�mero inv�lido do menu
void mensagemNumeroInvalido (){
    printf("\n\t  N�mero inv�lido, informe um valor v�lido de 1 a 7.\n");
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
        printf("\n                        |        | [1] Sim | [2] N�o |        |");
        printf("\n                        |        ---------------------        |");
        printf("\n                        ---------------------------------------\n");

        printf("                        -> Deseja continuar com o procedimento? ");


}

    // mensagem de texto em desenvolvimento...
void emDesenvolvimento (){
    printf("\n");
    printf("EST� FUN��O AINDA EST� EM DESENVOLVIMENTO, AGUARDE A PR�XIMA ATUALIZA��O \n");
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
    printf("\nAs informa��es foram exportadas com sucesso! \nPor favor verifique a pasta onde se encontra o programa. \n");
    PausarPrograma();
}

     // exibe texto de cadastro concluido
void mensagemCadastroConcluido (){
    printf("\nO cadastro foi finalizado com sucesso!");
    printf("\nO paciente j� foi adicionado � lista de espera e est� � espera do m�dico! \n");
}

