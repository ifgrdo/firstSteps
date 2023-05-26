/*
  Programa nº4 da 4ª Série de Programação (11/2018)

  Ivan Figueiredo, 93386

  Tiago Miranda, 93416

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função strlen
int f1(char *str){
  int i;
  int tam;

  i=0;
  while (str[i]!=0){
    ++i;
  }
  tam = i;
  return tam;
}


char *f2 (char *str1, char *str2){
  int i=0;
   
  while(str2[i]!=0){
    str1[i]=str2[i];
    ++i;
  }
  str1[i]=0;

  return str1;
}

char *f3(char *str1, char *str2){
  int p=f1(str1);
  int i=0;

  while(str2[i]!=0){
    str1[p+i]=str2[i];
    i++;
  }
    
  str1[p+i]=0;
  return str1;
}

char *f4(char *str1, char *str2){
  int l = strlen(str1);

  strcpy(str1+l, str2);
  return str1;
}

int main (int argc, char *argv[]){
  int comp1, comp2;
  char *v;
  int i;

  i=0;
  if(argc==3){

    //Comprimento do primeiro argumento
    comp1 = f1(argv[1]);
    //Comprimento do segundo argumento
    comp2 = f1(argv[2]);

    printf("Comprimento da primeira string: %d\n", comp1);
    printf("Comprimento da segunda string: %d\n", comp2);

    v = (char *) malloc ((comp2+1) * sizeof(char));
    
    // o if(v){}  foi utilizado para testar o malloc (se o malloc não funcionar corretamente o cilo não irá correr
    
    if(v){
      v[0]=0;
      //A função p2 recebe como argumentos v e argv[2]
      f2(v, argv[2]);
      printf("STRCPY: %s\n", v);
    }
        
    v = (char *) malloc ((comp2+comp1+1) * sizeof(char));

    if(v){
      v[0]=0;
      f3(v, argv[1]);
      f3(v, argv[2]);
      printf("STRCAT: %s\n", v);
    }
    
    v = (char *) malloc ((comp2+comp1+1) * sizeof(char));

    
    if(v){
      v[0]=0;
      f4(v, argv[1]); 
      f4(v, argv[2]); 
      printf("Alínea d: %s\n", v);
    }

  }
  else printf("Erro! Insira 2 strings na linha de comandos\n");
  
  free (v);
  
  return 0;
}
