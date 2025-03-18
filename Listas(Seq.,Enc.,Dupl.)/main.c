#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EMOCAO {
  char nome[18];
  int freq;
  struct EMOCAO *ant, *prox;
};

struct NO {
  struct EMOCAO emocao;
  struct NO *ant, *prox;
};

struct sLISTA {
  struct EMOCAO *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir(LISTA *lst, char *nome, int freq);
void emocao_no_controle(LISTA *lst, char *nome);
void imprimir(LISTA *lst);
LISTA comparar(LISTA *lst1, LISTA *lst2, LISTA *lst3);
void apagar(LISTA *lst);

int main(void) {
  LISTA lst1;

  inicializar(&lst1);

  inserir(&lst1, "Tristeza", 0);
  inserir(&lst1, "Raiva", 0);
  inserir(&lst1, "Nojo", 0);
  inserir(&lst1, "Alegria", 0);
  emocao_no_controle(&lst1, "Raiva");

  imprimir(&lst1);
  apagar(&lst1);

  return 0;
}
void inicializar(LISTA *lst) {
  lst->ini = NULL;
  lst->fim = NULL;
}
void inserir(LISTA *lst, char *nome, int freq) {
  struct EMOCAO *no = malloc(sizeof(struct EMOCAO));
  strcpy(no->nome, nome);
  no->freq = 1;
  no->prox = NULL;
  no->ant = NULL;
  if (lst->ini == NULL) {
    lst->ini = lst->fim = no;
  } else {
    lst->fim->prox = no;
    no->ant = lst->fim;
    lst->fim = no;
  }
}

void emocao_no_controle(LISTA *lst, char *nome) {
  struct EMOCAO *aux = lst->ini;
  struct EMOCAO *freq = 0;
  while (aux->nome == nome) {
    aux->freq = freq + 1;
  }
}
void imprimir(LISTA *lst) {
  struct EMOCAO *aux = lst->ini;

  printf("[");

  while (aux != NULL) {
    printf("Emoção; %s, Frequência: %d", aux->nome, aux->freq);
    printf("\n");
    aux = aux->prox;
  }

  printf("]\n");
}
void apagar(LISTA *lst) {
  struct EMOCAO *aux = lst->ini, *ant = NULL;
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}