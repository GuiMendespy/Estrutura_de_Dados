#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned MAX = 40;
int l[MAX], pos = 0;

void inserir(int elemento);
void domingos_divertidos(int elemento);
int imprimir();
void apagar();

int main(void) {
  int i;
  for(i=1;i<32;i++){
    inserir(i);
  }
  imprimir();
  printf("\n");
  domingos_divertidos(7);
  domingos_divertidos(14);
  domingos_divertidos(21);
  domingos_divertidos(28);
  imprimir();
  apagar();
  
  return 0;
}

void inserir(int elemento)
{
  if (pos < MAX) {
    l[pos] = elemento;
    pos++;
  } else
    printf("Lista cheia!!\n");
}

void domingos_divertidos(int elemento){
  int i,r;
  for (int r = 0 ; r < pos ; r++)
    if (l[r] == elemento)
    {
      for (int i = r ; i < pos - 1 ; i++)
        l[i] = l[i+1];
      pos--;
      break;
    }
}
int imprimir()
{
  printf("[ ");
  for (int i = 0 ; i < pos ; i++)
    printf("%d ",l[i]);
  printf("]\n");
printf("\n");
}

void apagar()
{
  pos = 0;
}