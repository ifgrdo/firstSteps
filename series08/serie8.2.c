#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inf (){
  printf("\n*************TRIANGULO**********\n");
  printf("Este programa desenha um triangulo no ecran\n");
}

void help(){
  printf("O número de linhas do triangulo é fornecido pelo utilizador na linha de comandos.\nDeverá inserir o número de linhas pretendido\n");
}

int main (int argc, char **argv){
  int n;
  int t1;
  int i, j, k;

  inf();
  
  if(argc!=2){
    help();
    return -1;
  }

  t1=sscanf(argv[1],"%d",&n);
  if(t1!=1){
    help();
    return -1;
  }

  printf("Triângulo com %d linhas\n\n", n);
  
  /*
  for(i=1; i<=n; ++i){
    for(j=1; j<=i; ++j){
      printf("* ");
    }
    printf("\n");
  }
  */

  for(i=1; i<=n; ++i){
    for(j=1; j<=n-i; ++j){
      printf(" ");
    }
    for(k=1; k<=i; ++k){
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}
