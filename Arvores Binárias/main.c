#include <stdlib.h>
#include <stdio.h>


struct sARV{
  int dado;
  struct sARV *esq,*dir;
};

struct sARV *raiz = NULL;

struct sARV *inserir(struct sARV *no, int dado);
void mostrarFolhas(struct sARV *no, int *l, int *tamanho);
int distanciaDaRaiz(struct sARV *no, int l, int cont);
void alturaArvore(struct sARV *no, int *l,int *tamanho,int *l2,int *tamanho2,int cont);
void troca(int *a, int *b);

struct sARV *apagar(struct sARV *no);

int main (){
  int l[10],l2[10];
  int tamanho = 0,tamanho2 = 0,i = 0,cont = 0;
  raiz = inserir(raiz,10);
  raiz = inserir(raiz,6);
  raiz = inserir(raiz,4);
  raiz = inserir(raiz,7);
  raiz = inserir(raiz,20);
  raiz = inserir(raiz,5);
  raiz = inserir(raiz,9);
  raiz = inserir(raiz,8);
  
  alturaArvore(raiz,l,&tamanho,l2,&tamanho2,cont);
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

void mostrarFolhas(struct sARV *no, int *l, int *tamanho){
    if(no){
      mostrarFolhas(no->esq,l,tamanho);
      mostrarFolhas(no->dir,l,tamanho);
    if(no->esq == NULL && no->dir == NULL){
      l[*tamanho] = no->dado;
      (*tamanho)++;
    }
  }
}

void alturaArvore(struct sARV *no, int *l,int *tamanho,int *l2,int *tamanho2,int cont){
  int i;
  mostrarFolhas(no,l,tamanho);
  for (i=0; i<*tamanho ;i++){
      l2[*tamanho2] = distanciaDaRaiz(no,l[i],cont);
      (*tamanho2)++;
  }
  for (int i = 0 ; i < *tamanho2 ; i++){
    for (int j = 0 ; j < *tamanho2 - 1 - i; j++){
      if (l2[j] > l2[j+1])
        troca(&l2[j],&l2[j+1]);
    }
}
  printf("%d",l2[*tamanho2-1]);
}
void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int distanciaDaRaiz(struct sARV *no, int l, int cont){
    if (no == NULL) {
        return -1;
    }

    if (no->dado == l) {
        return cont;  
    }

    if (l < no->dado) {
        return distanciaDaRaiz(no->esq, l, cont + 1);  
    } else {
        return distanciaDaRaiz(no->dir, l, cont + 1);  
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