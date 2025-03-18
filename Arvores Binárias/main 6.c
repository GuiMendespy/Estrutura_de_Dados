#include <stdlib.h>
#include <stdio.h>


struct sARV{
  int dado;
  struct sARV *esq,*dir;
};

struct sARV *raiz = NULL;

struct sARV *inserir(struct sARV *no, int dado);

int alturaArvore(struct sARV *no);


struct sARV *apagar(struct sARV *no);

int main (){
  raiz = inserir(raiz,4);
  raiz = inserir(raiz,10);
  raiz = inserir(raiz,6);
  raiz = inserir(raiz,7);
  raiz = inserir(raiz,20);
  raiz = inserir(raiz,5);
  raiz = inserir(raiz,9);
  raiz = inserir(raiz,8);
  
  printf("Altura da Árvore é: %d ",alturaArvore(raiz));
  
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
int alturaArvore(struct sARV *no) {
    if (no == NULL) {
        return -1; 
    } else {
        int alturaEsq = alturaArvore(no->esq);
        int alturaDir = alturaArvore(no->dir);
        if (alturaEsq > alturaDir) {
            return alturaEsq + 1;
        } else {
            return alturaDir + 1;
        }
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