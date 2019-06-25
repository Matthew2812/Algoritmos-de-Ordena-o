#include <stdio.h>

void enderecamento(int *v, int tam){
  //1° Passo: Criar um vetor suficientemente grande
  int w[100];

  //2° Passo: Preencher o vetor com 0s
  for (int i = 0; i < 100; i++){
    w[i] = 0;
  }
  
  //3° Passo: Varrer o vetor V e incrementar o valor guardado em W, de índice valor de V 
  for (int j = 0; j < tam; j++){
    w[v[j]] += 1;
  }

  //4° Passo: Varrer o vetor W e colocar em V cada elemento
  int contV = 0;
  int contW = 0;
  while (contW != 100){
    if (w[contW] > 0){
      v[contV] = contW;
      contV++;
      w[contW]--;
    }
    else{
      contW++;
    }
  }
}

int main() {
  int vetor[8] = {88, 44, 55, 21, 33, 21, 88, 55};
  int tamanho = sizeof(vetor)/sizeof(vetor[0]);

  printf("Vetor original: ");
  printf("[ ");
  for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
  }
  printf("]");

  enderecamento(vetor, tamanho);
  printf("\nVetor ordenado por endereçamento direto: ");
  printf("[ ");
  for (int i = 0; i < tamanho; i++){
    printf("%d ", vetor[i]);
  }
  printf("]");
  return 0;
}