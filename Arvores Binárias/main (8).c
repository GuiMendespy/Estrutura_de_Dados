#include <stdio.h>
#include <stdlib.h>

struct sNODE{
 int dado;
 struct sNODE *prox;
};

struct sNODE *topo = NULL;
struct sNODE *topo2 = NULL;

void fulerar(int elemento);
int desfulerar();

void imprimirFILA();

int main(void) {
  fulerar(100);
  fulerar(75);
  fulerar(86);
  fulerar(34);
  fulerar(10);
  fulerar(7);
  fulerar(8);
  fulerar(3);
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  imprimirFILA();
  printf("%d\n",desfulerar());
  

  return 0;
}


void fulerar(int elemento){
    struct sNODE *no = (struct sNODE*) malloc (sizeof(struct sNODE));
    no->dado = elemento;
    no->prox = NULL;

    if (!topo){
        topo = no;
    }else{
        no->prox = topo;
        topo = no;
  }
}

int desfulerar(){
    int a = topo->dado;
    struct sNODE *tmp = topo;
    if(!topo){
        exit(1);
    }else{
        topo = topo->prox;
    }
    return a;
}

void imprimirFILA(){
    struct sNODE *aux = topo;
    printf("F[ ");
    while(aux){
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}


