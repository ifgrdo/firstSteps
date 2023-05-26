#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (int argc, char**argv)
{
  int n,i1,t, j, k,e; //n-quantidade de números gerados; i-contador; x-número aleatório
  double m,x, p; //m-valor máximo
  double *v;

  k=5;
  e=0;

  while(k==5)
    {
      if(argc!=3)
	{
	  printf("Insira o valor de 'n' e 'm'\n");
	  scanf("%d %lf", &n, &m);
	  //Apenas lê os 2 primeiros valores inseridos, ignorando os outros
      
	  printf("Leu os valores %d e %lf para 'n' e 'm'\n", n, m);
	}

      if(argc==3)
	{
	  sscanf(argv[1], "%d", &n);
	  sscanf(argv[2], "%lf", &m);
	  printf("Leu o valor de %d para 'n' e de %lf para 'max'\n", n, m);
	}


    
      printf("Leu os valores %d e %lf para 'n' e 'm'\n", n, m);
      

      //Criação de um canal de escrita num ficheiro
      FILE *f1;
      f1=fopen("serie2.1.txt","wt");

  
      printf("Este programa gera N números reais aleatórios no intervalo [0, Max]\n");

      if(e==0)   v=(double*)malloc(n*sizeof(double)); //Vetor onde vão ser guardados os n gerados

      if(e!=0)  v=(double*)realloc(v, n*sizeof(double));
  

      //Gera os n aleatórios

      printf("Valores gerados sem estarem ordenados\n");
  
      srand(time(NULL));
      for(i1=0; i1<n; ++i1)
	{
	  x=((double)rand ()) / ((double)RAND_MAX); //x pertence a [0,1]
	  x= m * x; //x pertence a [0,m]

	  v[i1]=x;
      
	  printf("%2d - %10lf\n",i1,x);
	}



      //BubbleSort

      while (1)
	{
	  t=0;
	  for (i1=0; i1<n; ++i1)
	    {
	      if(v[i1]<v[i1+1])
		{
		  p=v[i1];
		  v[i1]=v[i1+1];
		  v[i1+1]=p;

		  t=1;
		}
	    }
     
	  if(t==0)
	    break;
	}

  
  
      //Imprimir no ecrã e no ficheiro os valores já ordenados
 
      printf("\nValores ordenados por ordem decrescente\n");
 
      for(i1=0; i1<n; ++i1)
	{
	  printf("%2d - %10lf\n",i1,v[i1]);
	  fprintf(f1,"%2d - %10lf\n",i1,v[i1]);
	} 

      fclose(f1);

 
      printf("Deseja voltar a executar o programa (escreva 1 em caso afirmativo ou 0 caso contrário)?\n");
      scanf("%d", &j);

      if(j==1) k=5;

      if(j==0) k=4;

      ++e;  
    }

  free (v);
  return 0;
}
