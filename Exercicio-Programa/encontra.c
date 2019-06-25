#define ALFABETO 27
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
Substituimos a frequência de cada letra por um pontuação de números inteiros, cada letra terá uma pontuação diferente em cada idioma

Exemplo: Letra a
            Português    Inglês     Alemão
Frequência   14.63%      8.167%     6.51%
Pontuação      26          24        21

Assim, todos terão a mesma escala de pontuação e poderemos comparar igualmente o texto com a frequencia das letras
*/

//Função que identifica o idioma do texto
static inline int identifica(char *frase, int tam){
  //Definindo a pontuação de cada idioma.
  int portugues = 0, ingles = 0, alemao = 0;

  //Vetor de letras para comparação. Definimos o caracteres 'espaço' para que ele não atribuísse pontuação
  char vet_alf[ALFABETO] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};

  //Vetor de inglês
  int vet_ing[ALFABETO] = {24, 7,	15, 17,	26, 11, 10, 19, 22, 4, 5, 16, 13, 21, 23, 8, 2, 18, 20, 25, 14, 6, 12, 3, 9, 1, 0};

  //Vetor de alemão
  int vet_ale[ALFABETO] = {21, 11, 15, 19, 26, 9, 14, 18, 24, 4, 8, 16, 13, 25, 12, 6, 1, 22, 23, 20, 17, 5, 10, 2, 3, 7, 0};

  //Vetor de português
  int vet_port[ALFABETO] = {26, 8, 15, 19, 25, 7, 11, 10, 21, 5, 3, 14, 18, 20, 24, 13, 9, 22, 23, 16, 17, 12, 2, 4, 1, 6, 0};

  //Índices para comparação 
  int i, j;

  //Transforma a frase toda para letras minusculas
  for (i = 0; i < tam; i++){
    frase[i] = tolower (frase[i]);
  }
  //Primeiro for é pro texto inteiro
  for (i = 0; i < tam; i++){
    //Segundo for pra analisar a primeira letra com o vetor alfabeto
    for (j = 0; j < ALFABETO; j++){
      //Se a letra da posição i for igual a 26, ele sairá do for de comparação
      if (j == 26)
        break;
        
      //Se a letra de i estiver no vetor do alfabeto, retorna a posição da letra
      if (frase[i] == vet_alf[j]){
        //Sai do for da letra
        break;
      }
    }
    //Com a posição da letra, vamos somar a pontuação de cada idioma com o valor da posição da letra correspondente
    portugues = portugues + vet_port[j];
    ingles = ingles + vet_ing[j];
    alemao = alemao + vet_ale[j];
  }
  //Mostra as pontuações para comparar no final
  printf ("\n\nPontuação Português %d", portugues);
  printf ("\nPontuação Inglês %d", ingles);
  printf ("\nPontuação Alemão %d", alemao);

  //Se a pontuação do Português for maior que as outras, retorna 0
  if (portugues > alemao && portugues > ingles)
    //0 é um identificador do idioma Português
    return 0;
  
  //Se a pontuação do Inglês for maior que as outras, retorna 1
  else if (ingles > portugues && ingles > alemao)
    //1 é um identificador do idioma Inglês
    return 1;
  
  //Se o Inglês ou o Português não tiverem a maior pontuação, então o Alemão terá, retorna 2
  else
    //2 é um identificador do idioma Alemão
    return 2;
}