#include <stdlib.h>
#include <stdio.h>


struct sARV{
  int dado;
  struct sARV *esq,*dir;
};

struct sARV *raiz = NULL;

struct sARV *inserir(struct sARV *no, int dado);

int getMin(struct sARV *no);
struct sARV *apagar(struct sARV *no);

int main (){
  raiz = inserir(raiz,7);
  raiz = inserir(raiz,3);
  raiz = inserir(raiz,9);
  raiz = inserir(raiz,1);
  raiz = inserir(raiz,5);
  raiz = inserir(raiz,4);

  printf("%d \n",getMin(raiz));

  raiz = apagar(raiz);
  return 0;
}

struct sARV *inserir(struct sARV *no, int dado){
  if(!no){
    no = (struct sARV*) malloc (sizeof(struct sARV));
    no->dado = dado;
    no->esq = no->dir = NULL;
  }else if(dado< no->dado){
    no->esq = inserir(no->esq,dado);
  }else{
    no->dir = inserir(no->dir,dado);
  }
  return no;
}

int getMin(struct sARV *no){
  if(no){
    if(no->esq == NULL && no->dir ==NULL){
        return no->dado;
    }
    getMin(no->esq);
  }
}

struct sARV *apagar(struct sARV *no){
  if (no){
    no->esq = apagar(no->esq);
    no->dir = apagar(no->dir);
    free(no);
  }else{
    return NULL;
  }
}