#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct complexo{
  double real;
  double imag;
  double norma;
};


void ordenar (struct complexo **v, int N){
  struct complexo *x;
  int i;
  int teste;
  
  while(1)
    {
      teste = 0;
      for (i=0; i < N-1; ++i)
	{
	  if(v[i]->norma < v[i+1]->norma){
	    x = v[i];
	    v[i]= v[i+1];
	    v[i+1]= x;
	    teste = 1;
	  }
	}
      if(teste==0)
	break;
    }

}

void trocar (struct complexo **v, int n1,int  n2){
  struct complexo *x;

  x = v[n1];
  v[n1] = v[n2];
  v[n2] = x;
}

	    
int main (int argc, char **argv){

  int N, k;
  int t1, n1, n2;
  int i, r;
  double re, im, norm;
  struct complexo **v;
  
  if(argc!=2){
    return -1;
  }

  t1=sscanf(argv[1], "%d", &N);
  if(t1!=1){
    return -1;
  }
  printf("Pediu para gerar %d números complexos aleatórios\n", N);
  
  v=(struct complexo **) malloc ((N)* sizeof(struct complexo *));

  for(i=0; i<N; ++i){
    v[i]= (struct complexo *) malloc ((1)* sizeof(struct complexo));
  }
 
  srand (time(NULL));

  printf("Numeros complexos nao ordenados\n");
  
  for(i=0; i<N; ++i){
    re = ((double) rand ()) / ((double) RAND_MAX);
    re = 21*re-7;

    im = ((double) rand ()) / ((double) RAND_MAX);
    im = 21*im-7;

    norm=sqrt((re * re) + (im * im));
    // printf("%lf\n", norm);
    
    v[i]-> real = re;
    v[i]-> imag = im;
    v[i]-> norma = norm;
    
    printf("%d= %lf + %lfi --- Norma: %lf\n",i, v[i]-> real, v[i]-> imag, v[i]-> norma); 
  }

  ordenar(v, N);

  printf("\nNumeros complexos  ordenados\n");

  for(i=0; i<N; ++i){
    printf("%d= %lf + %lfi --- Norma: %lf\n",i, v[i]-> real, v[i]-> imag, v[i]-> norma);   
  }

  k=1;

  printf("\nDeseja trocar a ordem de algum par de complexos?\n");
  printf("0 -- Não\n1 -- Sim\n");
  scanf("%d", &r);

  if(r==1){
    while(k==1){
      printf("\nQue numeros quer trocar?\n");
      scanf("%d", &n1);
      scanf("%d", &n2);
      trocar(v, n1, n2);

      for(i=0; i<N; ++i){
	printf("%d= %lf + %lfi --- Norma: %lf\n",i, v[i]-> real, v[i]-> imag, v[i]-> norma);   
      }

      printf("\nQuer voltar a trocar?\n");
      printf("0 -- Não\n1 -- Sim\n");
      scanf("%d", &k);

      if(k!=1){
	free(v);
	return -1;
      }
    }
  }
    
  if(r!=1){
    free (v);
    return -1;
  }
  
  free(v);
  return 0;
}
