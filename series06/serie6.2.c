/*
  Programa 2
  Serie 6

  Ivan Figueiredo, 93386
  Tiago Miranda, 93416
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main (){
  
  int k=1;
  int i, n, t1, t2;
  unsigned short int u=0;
  int v[16];
  char *str;
  
  v[0]=1;

  //Gerar vetor com potências de 2, entre 0 e 15
  for(i=1; i<16; ++i){
    v[i]=2*v[i-1];
  }
  
  srand(time (NULL));

  //Gerar os spins 
  for(i=0; i<16; ++i){
    if((rand () %2)==1){
      u = u | v[i];
    }
  }

  str = (char *) malloc (17 * sizeof(char));

  if(str==NULL){
    return -1;
  }
  
  // Ciclo para escrever os 0 e 1 gerados na string str
  for(i=0; i<16; ++i){
    if((u & v[i]) == v[i]){
      str[i]=49;
    }
    
    else{
      str[i]=48;
    }
  }

  str[16]='\0';
  
  while(k=1){

    printf("Configuracao de spins: %s", str);
  
    printf("\n\nPretende mudar o sinal de qual spin?\n");
    printf("O primeiro valor à esquerda corresponde à posição 0 e o último corresponde à posição 15\n");
    t1 = scanf ("%d", &n);

    if(t1==0){
      printf("O programa não leu o valor inserido!\n");
      return -1;
    }

    if(n<0 || n>15){
      printf("Deverá inserir um valor entre 0 e 15!\n");
      return -1;
    }

    //Alteração do spin escolhido
    u = (u ^ v[n]);
  
    for(i=0; i<16; ++i){
      if((u & v[i]) == v[i]){
	str[i]=49;
      }
      
      else{
	str[i]=48;
      }
    }
    printf("\nNova configuracao de spins: %s\n", str);

    printf("\nPretende mudar o sinal de outro spin?\n");
    printf("Insira 1 em caso afirmativo e 0 em caso negativo\n");
    printf("1 -- Sim\n");
    printf("0 -- Não\n");
    t2 = scanf("%d", &k);

    if(t2==0){
      printf("O programa não leu o valor inserido!\n");
      return -1;
    }
    
    if(k!=1){
      return -1;
    }
  }
  free(str);
  return 0;
}
