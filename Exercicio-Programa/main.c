/*Nome                  TIA
Kayque Lima Silva       31783511
Matheus Soares Santos   31895263 
Wanderson Lima Santos   31895591
*/
#include "encontra.c"

int main()
{
  char texto[1000]; //Definindo o vetor da frase
  int i = 0; //Indíce para imprimir o vetor

  //Criando um verificador para que o texto seja maior que 20 caracteres
  while (i < 20){
    printf("\nDigite um texto com mais de 20 caracteres: ");
    fgets(texto, 1000, stdin);//Pegando a frase

    //For para contar a quantidade de caracteres do texto
    for (i = 0; texto[i] != 0; i++);
  }
  //Imprimindo o tamanho do texto para comparação
  printf("\nTamanho do Texto armazenado: %d", i-1);

  //Idioma recebe o valor da função identifica
  int idioma = identifica(texto, i);

  //Se o idioma for igual a 0 (Português)
  if (idioma == 0){
    printf("\n\nIdioma do texto: Português");
  }

  //Se o idioma for igual a 1 (Inglês)
  else if (idioma == 1){
    printf("\n\nIdioma do texto: Inglês");
  }

  //Se não for igual a 0 ou 1 (Alemão)
  else{
    printf("\n\nIdioma do texto: Alemão");
  }
  
  return 0;
}