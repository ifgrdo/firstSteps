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
  int c1=1;

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

  for(i=0; i<n; ++i){
    for(j=0; j<n-i-1; ++j){
      printf("   ");
    }
    
    for(k=0; k<i+1; ++k){

      if(k==0)
	c1=1;
      
      else
	c1=(c1 * (i+1-k))/k;
     

      printf("%3d   ", c1);
    }
    printf("\n");
  }
  return 0;
}
