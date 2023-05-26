#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv)
{
  int N;
  int t1;
  int i;
  int r1;
  int *v;
  int cont = 0;
  int k;
  int max;
  int min;
  int pos = 0;
  int neg = 0;
  int par = 0;
  int impar = 0;
  int *r; //para guardar a informação acerca do número de vezes que cada número é gerado
  

  FILE *f1;

  
  
  if (argc!=2){
    printf("Insira um valor válido!\n");
    return -1;
  }

  t1=sscanf(argv[1],"%d", &N);
  printf("Teste de leitura: %d\n", t1);
  if(t1==0){
    return -1;
  }

  v = (int *) malloc (N * sizeof(int));
  r = (int *) malloc (N * sizeof(int));

  
  srand(time(NULL));


// Gera os valores e guarda-os num vetor

  
  for (i=0; i<N; ++i)
    {
      r1 =  rand () %201;
      r1 = r1 - 100;
      printf("%d --- %3d\n", i, r1);
      v[i] = r1;  
    }

  printf("\n");

  //Quantas vezes cada número apareceu

  for (i=0; i<N; ++i){

    for (k=0; k<N; ++k){

      if(v[k]==v[i]){
	  ++cont;
      }
    }
    
    printf("Número %3d: %d vezes\n", v[i], cont);
    r[i] = cont; //ficam guardados num vetor
    cont = 0;
    k = 0;
  }

  printf("\n");


  

  //Determinação do valor máximo

  max = v[0];
  
  for (i=0; i<N; ++i){
    if(v[i] > max){
      max = v[i];
    }
  }


   //Determinação do valor mínimo

  min = v[0];
  
  for (i=0; i<N; ++i){
    if(v[i] < min){
      min = v[i];
    }
  }

  //Imprime os valores max e min
  
  printf("O valor máximo é: %2d\n", max);
  printf("O valor mínimo é: %2d\n", min);


  //Determinação da quantidade de números positivos e negativos gerados

  for (i=0; i<N; ++i){
    if(v[i] < 0){
      ++neg;
    }

    else{
      ++pos;
    }
  }
  
  printf("Foram gerados %d números positivos e %d números negativos\n", pos, neg);


  //Determinação da quantidade de números pares gerados


  for (i=0; i<N; ++i){
    if((v[i] % 2) == 0){
      ++par;
    }

    else{
      ++impar;
    }
  }

  printf("Foram gerados %d números pares e %d números impares\n", par, impar);

  f1 = fopen ("ficheiro1.txt","wt");

  fprintf(f1,"Foram gerados %d números aleatórios\n", N);
  fprintf(f1,"Valor máximo: %d\n", max);
  fprintf(f1,"Valor mínimo: %d\n", min);
  fprintf(f1,"Quantidade de números positivos: %d\n", pos);
  fprintf(f1,"Quantidade de números negativos: %d\n", neg);
  fprintf(f1,"Quantidade de números pares: %d\n", par);
  fprintf(f1,"Quantidade de números impares: %d\n", impar);

  for(i=0; i<N; ++i){
    fprintf(f1,"Número %3d: %d vezes\n", v[i], r[i]);
  }

 
  fclose (f1);
  
  return 0;
}
