#include <stdio.h>
/*Nome: Matheus Soares Santos     TIA: 31895263
Fiz com o Wanderson Bezerra Lima  TIA: 31895591

Função Afunda do HeapSort

Fizemos uma função recursiva do Afunda com os parâmetros:
vet = Vetor
i = Indice
tam = Tamanho do Vetor                    */
int *afunda(int *vet, int i, int tam){  
  /*Definimos 3 variáveis para as trocas:
  maior = Número do maior filho
  indice = Indice do maior filho
  aux = Auxiliar para trocar com o pai    */
  int maior, indice, aux;
  //Verifica se o Indice é válido para comparação pai com filhos  
  if (i < 0 || i > tam || i*2 > tam || (i*2)+1 > tam){
    //Se não for, retorna o vetor
    return vet;
  }
  //Verifica se o primeiro pai só tem um filho
  else if ((i*2) + 1 > tam){
    //Se ele tiver, então o maior filho é o único filho que ele possui
    maior = vet[i*2];
    indice = i*2;
  }
  //Nesse caso, os pai tem dois filhos
  else{
    //Verifica se o filho da direita é o maior
    if (vet[i*2] < vet[(i*2)+1]){
      //Se for, então salva o valor e o índice do filho
      maior = vet[(i*2)+1];
      indice = (i*2) + 1;
    }
    //Verifica se o filho da esquerda é o maior
    else{
      //Se for, então salva o valor e o índice do filho
      maior = vet[i*2];
      indice = i*2;
    }
  }
  //Compara se o maior filho é maior que o pai
  if (vet[i] < maior){
    //Se for, então troca o filho com o pai
    aux = vet[i];
    vet[i] = vet[indice];
    vet[indice] = aux;
    //Chama a função Afunda para verificar se o pai precisa ser afundado mais uma vez
    afunda(vet, indice, tam);
  }  
  //No final, retorna o vetor.
  return vet;
}

int main(){
  //Criação do vetor, ponteiro e os índices para criar o HeapMax com o Afunda
  int vet[11] = {-1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7}, *p, i, j;
  //Calcula e aloca em tam o tamanho do vetor
  int tam = sizeof(vet)/sizeof(vet[0]);
  //For para criar o HeapMax com a função Afunda (For de 10 até 1, consideramos que o vetor começa da posição 1)
  for (i = tam-1; i > 0; i--){
    printf("I: %d\n", i);
    //O ponteiro recebe o vetor retornado da função Afunda
    p = afunda(vet, i, tam);
    tam = sizeof(vet)/sizeof(vet[0]);
    printf("Vetor: [ ");
    //Imprime o vetor no final de cada Afunda
    for (j = 0; j < tam; j++)
      //Utilizando o ponteiro para imprimir o vetor
      printf("%d ", p[j]);
    printf("]\n\n");
  }
  return 0;
}