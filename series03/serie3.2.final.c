#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Tiago Miranda
// Ivan Figueiredo
// Serie 3.2



//Função que recebe uma string e um caracter e retorna o número de vezes que o caracter se encontra na string

int
fa(char *str, char ch)
{
  int i, n; //n - número de vezes que o caracter se encontra na string
  
  i = 0;
  n = 0;

  while (str[i]!=0)
    {
      if (str[i]==ch){
	++n;
      }
      
      ++i;
    }
  
  return n;
}

  

//Função que recebe uma string e um caracter e retorna a posição da primeira ocorrência desse caracter na string

int
fb(char *str, char ch)
{
  int i, p; //p - posição da primeira ocorrência do caracter na string
  
  p = -1; //de forma a obter -1 no caso de não haver ocorrência
  i = 0;

  while (str[i]!=0)
    {
      if(str[i]==ch){
	p=i;
	break;
      }

      ++i;
    }

  //Quando sai do ciclo, p pode ter recebido um novo valor ou ter continuado com o valor -1; caso p==1, a função fb retorna o valor -1 para a função main

  if (p==-1){
    return -1;
  }

  else{
    return p;
  }
}



//Função que recebe uma string e dois caracteres e substitui o primeiro caracter pelo segundo. É do tipo void pois não retorna nenhum valor

void
fc (char *str, char ch1, char ch2)
{
  int i;

  i=0;
  
  while (str[i]!=0)
    {
      if(str[i]==ch1){
	str[i]=ch2;
      }

      ++i;
    }
}



int main (int argc, char **argv)
{

  int num, pos, tam; 
  char *strfinal;
  int i;

  //Na linha de comandos insere-se uma string e dois caracteres, sendo que argv[1] corresponde à string e argv[2] corresponde aos 2 caracteres (o primeiro caracter encontra-se em argv[2][0] e o segundo em argv[2][1])
  
  if (argc!=3){
    printf("ERRO! Insira, por favor, uma string e dois caracteres\n");
    return -1;
  }
  

  //Corre a função fa - esta função recebe a string e o primeiro caracter
  
  num = fa(argv[1], argv[2][0]);
  printf("\nNúmero de vezes que o primeiro caracter se encontra na string: %d\n", num);

  
  
  //Corre a função fb
    
  pos = fb(argv[1], argv[2][0]);
  
  if(pos==-1){
    printf("\nO primeiro caracter inserido não se encontra na string!\n"); //Não se fez return -1 de modo a aparecer a string no final (que, neste caso, fica igual à string inicial)
  }

  else{
    printf("\nPrimeira posição do caracter na string: %d\n", pos); //Considera-se a primeira posição da string como sendo a posição zero
  }


  //Obter tamanho da string
  tam = strlen(argv[1]);
  

  //Criação da nova string e alocação de memória
  strfinal =(char*) malloc (tam * sizeof(char));
  

  //Cópia da informação para a nova string
  strcpy (strfinal, argv[1]);
  

  //Aplica-se a função fc à nova string obtida
  fc(strfinal, argv[2][0], argv[2][1]);


  //Lê a string

  printf("\nNova string:"); //sem mudança de linha para aparecer na mesma linha da string

  for(i=0 ; i<=tam ; ++i){
    printf("%c", strfinal[i]); //sem mudança de linha de forma a que apareçam todos os elementos seguidos
  }


  //Liberta a memória alocada

  free(strfinal);
  
  return 0;
}
