#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario{
 char nome[30];
 char carg[30];
 float sal;
};

struct sNO{
  struct funcionario *func;
  struct sNO *prox;
  struct sNO *ant;
};

typedef struct sLISTA LISTA;

struct sLISTA{
  struct sNO *ini, *fim;
};

void inicializar(LISTA *lst);
void inserir_dup_valdemort(LISTA *lst,char *nome,char *carg,float sal);
int prioridadeCargo(const char *carg);
void imprimir(LISTA *lst);
void apagar(LISTA *lst);

int main(void) {
  LISTA lst1;

  inicializar(&lst1);
  
  inserir_dup_valdemort(&lst1,"Daniel","Peão",1240);
  inserir_dup_valdemort(&lst1,"José","Gerente",200000);
  inserir_dup_valdemort(&lst1,"Guilherme","Gerente", 100000 );
  inserir_dup_valdemort(&lst1,"Jarda","Supervisor",2500);
  inserir_dup_valdemort(&lst1,"Henrique","Supervisor",1240);
  inserir_dup_valdemort(&lst1,"Carlos","Supervisor",5000);
  inserir_dup_valdemort(&lst1,"Jaqueline","Peão",12400);
  inserir_dup_valdemort(&lst1,"kaio","Gerente", 10);
  inserir_dup_valdemort(&lst1,"Klésia","Peão",10500);

  imprimir(&lst1);

  apagar(&lst1);

  return 0;
}
void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

int prioridadeCargo(const char *carg) {
  if (strcmp(carg, "Gerente") == 0) return 1;
  if (strcmp(carg, "Supervisor") == 0) return 2;
  if (strcmp(carg, "Peão") == 0) return 3;
  return -1;
}

void inserir_dup_valdemort(LISTA *lst, char *nome, char *carg, float sal) {
  struct sNO *no = (struct sNO *)malloc(sizeof(struct sNO));

  no->func = (struct funcionario *)malloc(sizeof(struct funcionario));

  strcpy(no->func->nome, nome);
  strcpy(no->func->carg, carg);
  no->func->sal = sal;

  no->prox = NULL;
  no->ant = NULL;

  if (lst->ini == NULL) {
      lst->ini = no;
      lst->fim = no;
  } else {
      struct sNO *atual = lst->ini;
      int prioridade_no = prioridadeCargo(no->func->carg);

      while (atual != NULL && (prioridadeCargo(atual->func->carg) < prioridade_no ||
             (prioridadeCargo(atual->func->carg) == prioridade_no && no->func->sal < atual->func->sal))) {
          atual = atual->prox;
      }

      if (atual == NULL) {
          no->ant = lst->fim;
          lst->fim->prox = no;
          lst->fim = no;
      } else if (atual->ant == NULL) {
          no->prox = lst->ini;
          lst->ini->ant = no;
          lst->ini = no;
      } else {
          no->prox = atual;
          no->ant = atual->ant;
          atual->ant->prox = no;
          atual->ant = no;
      }
  }
}

void imprimir(LISTA *lst) {
  struct sNO *aux = lst->ini;
  printf("[ ");
  while (aux != NULL) {
    printf("Funcionario: %s, Cargo: %s, Salário: %.2f ", aux->func->nome,aux->func->carg,aux->func->sal);
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
