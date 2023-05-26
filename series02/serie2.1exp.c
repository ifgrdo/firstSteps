#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int
main ()
{

  int n,i,t1,t2,t;
  double m,r1,p;
  double v[10000];

  printf("Este programa gera números reais no intervalo [0,MAX]\n");

  printf ("Insira, por favor, quantos números aleatórios pretende gerar\n");
  t1= scanf("%d",&n);
  printf("Teste de leitura: %d\n\n",t1);
  if(t1==0){
    printf("ERRO!\n");
    return -1;
  }

  if(n<=0){
    printf("ERRO! O valor inserido é negativo. Insira um valor válido\n");
    return -1;
  }
  

  printf("Qual é o valor máximo que os números podem tomar?\n");
  t2= scanf("%lf",&m);
  printf("Teste de leitura: %d\n\n",t2);
  if (t2==0) {
    printf("ERRO!\n");
    return -1;
  }
  
   if(n<=0){
    printf("ERRO!O valor inserido é negativo. Insira um valor válido\n");
    return -1;
  }

 

  printf("Valores obtidos sem estarem ordenados\n");

  srand (time(NULL));

  for (i=0; i<n; ++i)
    {
      r1 = ((double)rand()) / ((double)RAND_MAX);
      r1 = m * r1;
      printf("%2d -- %lf\n", i,r1);
      v[i] = r1; 
    }

  //Ordenar os valores obtidos por ordem decrescente

  while(1)
    {
      t=0;
  
      for (i=0; i<n; ++i)
	{
	  if (v[i]<v[i+1])
	    {
	      p = v[i];
	      v[i]=v[i+1];
	      v[i+1]=p;

	      t=1;
	    }
	}

      if(t==0)
	break;
    }
	  
	  
  //Imprimir os valores

  printf("\nValores obtidos ordenados\n");

  for (i=0; i<n; ++i)
    {
      printf("%2d --- %lf\n",i,v[i]);
    }

  
  return 0;
}
	    

  

  
	



  

