#include <stdlib.h>
#include <stdio.h>


struct sARV{
  int dado;
  struct sARV *esq,*dir;
};

struct sARV *raiz = NULL;

struct sARV *inserir(struct sARV *no, int dado);
struct sARV *remover(struct sARV *no, int dado);

void emOrdem(struct sARV *no);
void preOrdem(struct sARV *no);
void posOrdem(struct sARV *no);

struct sARV *buscar(struct sARV *no, int dado);
int obter(struct sARV *no);

struct sARV *apagar(struct sARV *no);

int main (){
  raiz = inserir(raiz,7);
  raiz = inserir(raiz,3);
  raiz = inserir(raiz,9);
  raiz = inserir(raiz,1);
  raiz = inserir(raiz,5);
  raiz = inserir(raiz,4);

  emOrdem(raiz);
  printf("\n");
  
  raiz = remover(raiz,4);
  emOrdem(raiz);
  printf("\n");

  preOrdem(raiz);
  printf("\n");

  posOrdem(raiz);
  printf("\n");

  printf("NÃºmero buscado: %d",obter(raiz));
  
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

struct sARV *remover(struct sARV *no, int dado){
  struct sARV *aux =NULL, *aux2 = NULL;
  if(no){
    if(no->dado == dado){
      if(no->esq ==no->dir){
        free(no);
        return NULL;
      }else if(!no->esq){
        aux = no->dir;
        free(no);
        return aux;
      }else if(!no->dir){
        aux = no->esq;
        free(no);
        return aux;
      }else{
        aux = aux2 = no->dir;
        while (no->esq)
          aux = aux->esq;
        aux->esq = no->esq;
        free(no);
        return aux2;
      }
    }else{
      if(dado<no->dado)
        no->esq = remover(no->esq,dado);
      else
        no->dir = remover(no->dir,dado);
      }
    }
    return no;
}

void emOrdem(struct sARV *no){
  if(no){
  emOrdem(no->esq);
  printf("%d",no->dado);
  emOrdem(no->dir);
  }
}

void preOrdem(struct sARV *no){
  if (no){
  printf("%d",no->dado);
  preOrdem(no->esq);
  preOrdem(no->dir);
  }
}

void posOrdem(struct sARV *no){
  if(no){
  posOrdem(no->esq);
  posOrdem(no->dir);
  printf("%d",no->dado);
  }
}

struct sARV *buscar(struct sARV *no, int dado){
  if (no){
    if(no->dado == dado){
      return no;
    }else if(dado<no->dado){
      return buscar(no->esq,dado);
    }else{
      return buscar(no->dir,dado);
    }
  }else{
    return NULL;
  }
}

int obter(struct sARV *no){
  if(no){
    return no->dado;
  }else{
    printf("Nenhum dado a retornar\n");
    exit(0);
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