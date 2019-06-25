#include <stdio.h>

int *partition(int *vet, int tam, int pivo, int i_vetor, int i_maior, int i_menor, int *maior, int *menor){
  for (i_vetor = 1; i_vetor < tam; i_vetor++){
    if (vet[i_vetor] <= pivo){
      menor[i_menor] = vet[i_vetor];
      i_menor++;    
    }
    if (vet[i_vetor] > pivo){
      maior[i_maior] = vet[i_vetor];
      i_maior++;
    }
  }
  int maximo = i_maior + i_menor + 1;
  int controle_um = 0;
  int controle_dois = 0;

  for (i_vetor = 0; i_vetor < maximo; i_vetor++){
    if (controle_um < i_menor){
      vet[i_vetor] = menor[controle_um];
      controle_um++;
    }
    else if (i_vetor == i_menor){
      vet[i_vetor] = pivo;
    }
    else{
      vet[i_vetor] = maior[controle_dois];
      controle_dois++;
    }
  }

  return vet;
}

int main(void) {
  int vet[10] = {7, 4, 3, 10, 21, 33, 1, 6, 9, 15};
  int *p, tam, i_vetor, i_maior = 0, i_menor = 0;
  int maior[10], menor[10];
  int pivo = vet[0];
  tam = sizeof(vet)/sizeof(vet[0]);
  p = partition(vet, tam, pivo, i_vetor, i_maior, i_menor, maior, menor);
  printf("[ ");
  for (int i = 0; i < tam; i++){
    printf("%d ", p[i]);
  }
  printf("]");
  return 0;
}