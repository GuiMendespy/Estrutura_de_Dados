#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NO {
   char emocao[18];
   struct NO *prox;
};

struct sLISTA{
 struct NO *ini,*fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir_emo(LISTA *lst, char *emocao);
void imprimir(LISTA *lst);
LISTA comparar(LISTA *lst1, LISTA *lst2, LISTA *lst3);
void apagar(LISTA *lst);

int main(void){
   LISTA lst1,lst2,lst3;

   inicializar(&lst1);
   inicializar(&lst2);
   inicializar(&lst3);
   
   inserir_emo(&lst1, "Tristeza");
   inserir_emo(&lst1, "Raiva");
   inserir_emo(&lst1, "Nojo");
   inserir_emo(&lst1, "Raiva");
   inserir_emo(&lst2, "Alegria");
   inserir_emo(&lst2, "Tristeza");
   inserir_emo(&lst2, "Tristeza");
   inserir_emo(&lst2, "Nojo");
   
   comparar(&lst1,&lst2,&lst3);
   
   imprimir(&lst1);
   imprimir(&lst2);
   imprimir(&lst3);
   
   apagar(&lst1);
   apagar(&lst2);
   apagar(&lst3);
   return 0;
}
void inicializar(LISTA *lst){
   lst->ini = NULL;
   lst->fim = NULL;
}
void inserir_emo(LISTA *lst,char *emocao){
  struct NO *novo = malloc(sizeof(struct NO));
  strcpy(novo->emocao , emocao);
  novo->prox = NULL;

  if (lst->ini == NULL)
  {
    lst->ini = novo;
    lst->fim = novo;
  }
  else
  {
    lst->fim->prox = novo;

    lst->fim = novo; 
  }
}

LISTA comparar(LISTA *lst1, LISTA *lst2, LISTA *lst3){
   int a;
   struct NO *novo2 = malloc(sizeof(struct NO));
   struct NO *aux = lst1->ini, *aux2 = lst2->ini;
   while (aux){
     a = strcmp(aux->emocao, aux2->emocao);
      if (a<0){
         inserir_emo(lst3, aux->emocao);
      }else{
         inserir_emo(lst3, aux2->emocao);
      }
      aux2 = aux2 -> prox;
      aux = aux -> prox;
   }
}
void imprimir(LISTA *lst){
  struct NO *aux = lst->ini;

  printf("[");

  while(aux != NULL){
    printf("%s ", aux->emocao);
    aux = aux->prox;
  }

  printf("]\n");
}
void apagar(LISTA *lst){
  struct NO *aux = lst->ini;
  struct NO *ant = NULL;

  while (aux != NULL){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->ini = lst->fim = NULL; 
}