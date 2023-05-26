#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){
  FILE *f1;
  char c;
  int contador=0;
  int vogal=0;
  int consoante;
  
  if(argc!=2)
    return -1;

  f1=fopen(argv[1], "rt");

  if(f1==NULL){
    printf("ERRO ao abrir o ficheiro\n");
    return -1;
  }

  while((c=fgetc(f1))!=EOF){
      ++contador;
      if((c==65)||(c==69)||(c==73)||(c==79)||(c==85)||(c==97)||(c==101)||(c==105)||(c==111)||(c==117)){
	++vogal;
      }
  }
  printf("Número total de caracteres: %d\n", contador);
  printf("Número total de vogais: %d\n",vogal);
  printf("Número total de consoantes: %d\n", contador-vogal);

 
  fclose(f1);
  return 0;
}

  

  

  
