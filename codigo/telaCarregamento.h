#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// parte que faz o loadingBar
    struct temporizador {
    int pontos;
    int porcentagemPontos;
}temp;

void menuCarregamento (){
    temp.pontos= 58;
    temp.porcentagemPontos= 0;


    gotoxy(16, 7);
    printf("O programa está iniciando, por favor aguarde!!!");
    gotoxy(7, 9);
    printf("\t%d%% ", temp.porcentagemPontos);

    gotoxy(11, 9);
    for(int i=0; i<temp.pontos; i++){

         printf("%c", 22); Sleep(50);
    }
    printf(" 100%%");
    gotoxy(7, 10);
    printf("\tAbrindo o sistema");
    for(int i=0; i<2; i++){
        gotoxy(26, 10);
        printf(" ..."); Sleep(400);
        gotoxy(26, 10);
        printf("    "); Sleep(400);
    }
    // Beep(507099,800);
    system("cls");
}

