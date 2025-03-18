#include <stdlib.h>
#include <stdio.h>


struct sARV{
  int dado;
  struct sARV *esq,*dir;
};

struct sARV *raiz = NULL;

struct sARV *inserir(struct sARV *no, int dado);

int distanciaDaRaiz(struct sARV *no, int dado, int cont);

struct sARV *apagar(struct sARV *no);

int main (){
  int cont = 0;
  raiz = inserir(raiz,7);
  raiz = inserir(raiz,3);
  raiz = inserir(raiz,9);
  raiz = inserir(raiz,1);
  raiz = inserir(raiz,5);
  raiz = inserir(raiz,4);

  printf("%d ",distanciaDaRaiz(raiz,4,cont));
  
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

int distanciaDaRaiz(struct sARV *no, int dado, int cont) {
    if (no == NULL) {
        return -1;
    }

    if (no->dado == dado) {
        return cont;  
    }

    if (dado < no->dado) {
        return distanciaDaRaiz(no->esq, dado, cont + 1);  
    } else {
        return distanciaDaRaiz(no->dir, dado, cont + 1);  
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