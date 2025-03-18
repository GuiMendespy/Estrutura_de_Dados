#include <stdio.h>
#include <stdlib.h>

struct sNO{
 char nome[30];
 char carg[30];
 float sal;
 struct sNO *prox;
 struct sNO *ant;
};

typedef struct sLISTA LISTA;

struct sLISTA{
  struct sNO *ini, *fim;
};

void inicializar(LISTA *lst);
void inserir_dup_valdemort(LISTA *lst,const char *nome, const char *carg, float sal);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

int main(void) {
  LISTA lst1,lst2,lst3;
  
  inicializar(&lst1);
  inicializar(&lst2);
  inicializar(&lst3);
  inserir_dup_valdemort(&lst3,"Daniel","Peão",1240);
  inserir_dup_valdemort(&lst1,"José","Gerente",200000);
  inserir_dup_valdemort(&lst1,"Guilherme","Gerente", 100000 );
  inserir_dup_valdemort(&lst2,"Jarda","Supervisor",2500);
  inserir_dup_valdemort(&lst2,"Henrique","Supervisor",1240);
  inserir_dup_valdemort(&lst2,"Carlos","Supervisor",5000);
  inserir_dup_valdemort(&lst3,"Jaqueline","Peão",12400);
  inserir_dup_valdemort(&lst1,"kaio","Gerente", 10);
  inserir_dup_valdemort(&lst3,"Klésia","Peão",10500);

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

void inserir_dup_valdemort(LISTA *lst,const char *nome, const char *carg, float sal){
  struct sNO *no = (struct sNO *) malloc(sizeof(struct sNO));
  strncpy(no->nome, nome, 29);
  no->nome[30 - 1] = '\0';
  strncpy(no->carg, carg, 29);
  no->carg[30 - 1] = '\0';
  no->sal = sal;
  no->prox = NULL;
  no->ant = NULL;

  struct sNO *aux = lst->ini;

  if (lst->ini==NULL){
    lst->ini=no;
    lst->fim=no;
    return;
  }
  if (no->sal >= lst->ini->sal) {
    no->prox = lst->ini;
    lst->ini->ant = no;
    lst->ini = no;
    return;
  }
  if (no->sal < lst->fim->sal) {
    lst->fim->prox = no;
    no->ant = lst->fim;
    lst->fim = no;
    return;
  }
  while(aux!=NULL && no->sal<sal){
    aux = aux->prox;
  }
  no->prox = aux->prox;
  no->ant = aux;
  if (aux->prox !=NULL){
    aux->prox->ant = no;
  }
  aux->prox = no;
}

void imprimir(LISTA *lst) {
  struct sNO *aux = lst->ini;
  printf("[ ");
  while (aux != NULL) {
    printf("Funcionario: %s, Cargo: %s, Salário: %.2f ", aux->nome,aux->carg,aux->sal);
    printf("\n");
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(LISTA *lst) {
  struct sNO *aux = lst->ini, *ant = NULL;
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
}