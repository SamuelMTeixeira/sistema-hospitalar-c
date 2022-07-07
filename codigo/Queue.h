#include <stdlib.h>

struct ElementFila {
   char nome[50];
   double cpf;
};

struct CellFila {
   struct ElementFila Item;
   struct CellFila *Prox;
};

struct TQueue {
   struct CellFila *Front;
   struct CellFila *Back;
   int Lenght;
};

void InitializeQueue(struct TQueue *Queue) {
   (*Queue).Front = NULL;
   (*Queue).Back = (*Queue).Front;
   (*Queue).Lenght = 0;
}

int EmptyFila (struct TQueue Queue) {
   return (Queue.Back == NULL);
}

void Enqueue(struct ElementFila E, struct TQueue *Queue) {
   struct CellFila *Aux;
   Aux = (struct CellFila*) malloc(sizeof(struct CellFila));
   (*Aux).Item = E;
   (*Aux).Prox = NULL;
   if (EmptyFila(*Queue))
   {
       (*Queue).Back = Aux;
       (*Queue).Front = (*Queue).Back;
   }
   else
   {
       (*(*Queue).Back).Prox = Aux;
       (*Queue).Back = Aux;
   }
   (*Queue).Lenght++;
}

void Dequeue(struct ElementFila *E, struct TQueue *Queue) {
   if (EmptyFila(*Queue))
      printf("Erro: Fila está vazia. \n");
   else
   {
      struct CellFila *Aux;
      Aux = (*Queue).Front;
      *E = (*Aux).Item;
      (*Queue).Front = (*Aux).Prox;
      (*Queue).Lenght--;
      if ((*Queue).Lenght == 0)
	      (*Queue).Back = (*Queue).Front;
      free(Aux);
   }
}

int LenghtQueue(struct TQueue Queue) {
    return Queue.Lenght;
}

void PrintQueue(struct TQueue Queue, struct ElementFila E) {
   if (EmptyFila(Queue)){
      printf("Opa! parece que não existe nenhum paciente na fila de espera. \n");
   }
   else{
        struct CellFila *Aux = NULL;
        Aux = Queue.Front;
        int ficha = 1;
        printf("Exibindo pessoas na lista de espera: \n");
        int pessoasAtendidas=0;

        while (Aux != NULL){
              if(ficha == 1){
                printf("\nPRÓXIMO A SER ATENDIDO... \n");
                printf("Fichaº N %d \n", ficha);
              }
              else if (ficha > 1){
                 printf("Ficha Nº %d \n", ficha);
              }

              printf("NOME: %s \n",(*Aux).Item.nome);
              printf("CPF: %.0lf \n", (*Aux).Item.cpf);
              printf("\n\n");
              ficha++;

              Aux = (*Aux).Prox;
        }
   }
}

void PrintOutPerson(struct TQueue *Queue, struct ElementFila E) {
   if (EmptyFila(*Queue)){
      printf("Opa! parece que não existe nenhum paciente na fila de espera. \n");
   }
   else{
        struct CellFila *Aux;
        int ficha = 1;
        printf("PACIENTE A SER CHAMADO: \n");
        int pessoasAtendidas=0;
        do{
             int testador = 1;
              Aux = (*Queue).Front;
              E = (*Aux).Item;
              (*Queue).Front = (*Aux).Prox;
              testador--;
              if (testador == 0)
                  (*Queue).Back = (*Queue).Front;
              free(Aux);
              (*Queue).Lenght--;
              if(testador == 1){
                printf("\n PRÓXIMO A SER ATENDIDO... \n");
              }
              printf(" NOME: %s \n", E.nome);
              printf(" CPF: %.0lf \n", E.cpf);

              // gera um numero aleatorio da sala do consultorio para a pessoa ser chamada....
              int numConsultorio;
              do{
                numConsultorio = rand() % 20;
              }while(numConsultorio < 1);

              printf(" CONSULTÓRIO %d \n", numConsultorio);

              printf("\n\n");
              break;
        }while (!EmptyFila(*Queue));
   }
}

/*
void PrintQueue(struct TQueue *Queue, struct ElementFila E) {
   if (EmptyFila(*Queue)){
      printf("Opa! parece que não existe nenhum paciente na fila de espera. \n");
   }
   else{
        struct CellFila *Aux;
        int ficha = 1;
        printf("Exibindo pessoas na lista de espera: \n");
        int pessoasAtendidas=0;
        do{
             int testador = 1;
              Aux = (*Queue).Front;
              E = (*Aux).Item;
              (*Queue).Front = (*Aux).Prox;
              testador--;
              if (testador == 0)
                  (*Queue).Back = (*Queue).Front;
              free(Aux);
              (*Queue).Lenght--;
              if(testador == 1){
                printf("\nPRÓXIMO A SER ATENDIDO... \n");
                printf("Fichaº N %d \n", ficha);
              }
              else if (ficha > 1){
                 printf("Ficha Nº %d \n", ficha);
              }

              printf("NOME: %s \n", E.nome);
              printf("CPF: %.0lf \n", E.cpf);
              printf("\n\n");
              ficha++;
        }while (!EmptyFila(*Queue));
   }
}
*/
