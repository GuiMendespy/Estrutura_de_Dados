#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
 char nome[20];
 char paren[20];
 int idade;
 char city[20];
 struct sNODE *prox;
};

struct sLISTA{
 struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void inserir(LISTA *lst,const char *nome,const char *paren,int idade,const char *city);
void inserir_ord(LISTA *lst,const char *nome,const char *paren,int idade,const char *city);
void inserir_dup(LISTA *lst,const char *nome,const char *paren,int idade,const char *city);
void inserir_dup_ord(LISTA *lst,const char *nome,const char *paren,int idade,const char *city);
void remover(LISTA *lst, int dado);
struct sNODE buscar(int dado);
int obter(struct sNODE *lst);
void apagar(LISTA *lst);
void imprimir(LISTA *lst);
void tamanho(LISTA *lst);


int main(void) {
  LISTA lst1;
  
  inicializar(&lst1);
  

  /*inserir(&lst1,"Maria","avó",61,"Campina");
  inserir(&lst1,"Antonio","avô",64,"Campina");
  inserir(&lst1,"Jarda","Irmã",22,"Campina");
  inserir(&lst1,"Jaqueline","Mãe",41,"Ourilandia");
  inserir(&lst1,"David","Irmão",15,"Ourilandia");
  inserir(&lst1,"Daniel","Padrasto",39,"Ourilandia");
  inserir(&lst1,"Henrique","Tio",32,"Campina");
  inserir(&lst1,"Lino","Tio",40,"Cubati");*/

  inserir_ord(&lst1,"Maria","avó",61,"Campina");
  inserir_ord(&lst1,"Antonio","avô",64,"Campina");
  inserir_ord(&lst1,"Jarda","Irmã",22,"Campina");
  inserir_ord(&lst1,"Jaqueline","Mãe",41,"Ourilandia");
  inserir_ord(&lst1,"David","Irmão",15,"Ourilandia");
  inserir_ord(&lst1,"Daniel","Padrasto",39,"Ourilandia");
  inserir_ord(&lst1,"Henrique","Tio",32,"Campina");
  inserir_ord(&lst1,"Lino","Tio",40,"Cubati");
  //buscar(3);
  //printf("%d",obter(&lst1));

  

  //remover(&lst1, 2);
  

  //tamanho(&lst1);
  

  imprimir(&lst1);
  

  //apagar(&lst1);
  

  
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = NULL;
  lst->fim = NULL;
}

void inserir(LISTA *lst,const char *nome,const char *paren,int idade,const char *city){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  strcpy(novo->nome, nome);
  strcpy(novo->paren,paren);
  novo->idade = idade;
  strcpy(novo->city,city);
  novo->prox = NULL;
  

  //struct sNODE *aux=lst->ini;

  if(lst->ini == NULL){
    lst->ini=lst->fim = novo;
  }else{
    lst->fim->prox= novo;
    lst->fim = novo;
  }
}

void inserir_ord(LISTA *lst,const char *nome,const char *paren,int idade,const char *city){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  strcpy(novo->nome, nome);
  strcpy(novo->paren,paren);
  novo->idade = idade;
  strcpy(novo->city,city);
  novo->prox = NULL;
  struct sNODE *aux=lst->ini;

  while (aux != NULL && aux->idade < idade)
    aux = aux->prox;

  if (lst->ini == NULL)
    lst->ini = lst->fim = novo;
  else if (aux == lst->ini) {
    novo->prox = lst->ini;
    lst->ini = novo;
  } else if (aux == NULL) {
    lst->fim->prox = novo;
    lst->fim = novo;
  } else {
    aux->ant->prox = no;
    no->ant = aux->ant;
    no->prox = aux;
    aux->ant = no;    
  }
  }
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
  while(aux){
  printf("Nome: %s, Paren: %s, Idade: %d, Cidade: %s",aux->nome,aux->paren,aux->idade,aux->city);
  printf("\n");
    aux = aux->prox;
  }
}