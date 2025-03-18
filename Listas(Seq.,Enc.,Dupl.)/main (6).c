//LISTA SEQUENCIAL USANDO PILHA:

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void push(int elemento);
int pop();
int getTopo();

int tamanho();
void imprimir();
void apagar();

int main(void) {
  push(100);
  push(75);
  push(86);
  push(200);
  imprimir();
  
  printf("%d",getTopo());
  printf("\n");

  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");

  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");

  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");
  
  return 0;
}

void push(int elemento){
  if (pos < MAX)
  l[pos++] = elemento;
  else
  printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
  if (pos)
  return l[--pos];
  else {
  printf("Não há elementos. Pilha vazia.\n");
  exit(1);
  }
}

int getTopo(){
  if (pos)
    return l[pos-1];
  else
    printf("Pilha Vazia");
}
int tamanho(){
  return pos;
}

void imprimir(){
  printf("P[ ");
  for (int i = pos -1 ; i >= 0 ; i--)
  printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}

///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//LISTA SIMPLESMENTE ENCADEADA USANDO PILHA:

/*#include <stdio.h>
#include <stdlib.h>

struct sNODE{
 int dado;
 struct sNODE *prox;
};

struct sNODE *topo = NULL;

void push(int elemento);
int pop();
int getTopo();

int tamanho();
void imprimir();
void apagar();

int main(void) {
  push(100);
  push(75);
  push(86);
  push(34);
  imprimir();
  
  printf("%d",getTopo());
  printf("\n");
  
  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");

  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");

  printf("%d",pop());
  printf("\n");
  imprimir();

  printf("%d",getTopo());
  printf("\n");

  return 0;
}

void push(int elemento){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = elemento;
  novo->prox = NULL;

  if (!topo)
    topo = novo;
  else
    novo->prox = topo;
    topo = novo;
}

int pop(){
  if(topo){
    int dado = topo->dado;
    struct sNODE *tmp = topo;

    topo = topo->prox;

    free(tmp);

    return dado;
  }else{
    printf("Pilha vazia");
    exit(1);
  }
}

int getTopo(){
  if (topo){
    return topo->dado;
  }else{
    printf("Pilha vazia");
  }
}
int tamanho(){
  struct sNODE *aux = topo;
  int tam =0;
  while (aux){
    tam++;
    aux = aux->prox;
  }
  return tam;
}

void imprimir(){
  struct sNODE *aux = topo;

  printf("P[ ");
  while(aux){
    printf("%d ",aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}
void apagar(){
  struct sNODE *aux = topo, *ant;

  while(aux){
    aux = ant;
    aux = aux->prox;
    free(ant);
  }
  topo = NULL;
}*/



