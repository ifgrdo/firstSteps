#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main ()
{
 double x1,  m; // m-valor máximo que os números gerados podem tomar; x1 - número aleatório
 int i1, n, t; // n-quantidade de números aleatórios gerados; i1- contador; t-usado para o bubblesort
 double p; //p-usado no bubble sort para trocar valores consecutivos
 
 double aleat[10000]; // aleat - vetor onde vão ser guardados os valores gerados aleatoriamente. Nota: considera-se que o utilizador não manda imprimir mais de 10000 números aleatórios;


 //Criação de um canal de escrita num ficheiro (serie1.2.txt)
 FILE *f1;
 f1=fopen("serie1.2.txt","wt");


 //Pergunta ao utilizador quantos números reais aleatórios quer gerar e qual o valor máximo que esses números podem tomar

 printf("Quantos números reais aleatórios deseja obter?\n");
 scanf("%d", &n);

 if(n>10000 || n<0)
   {
     printf("Erro: O valor inserido tem que estar compreendido entre 0 e 10000\n");
     return 1;
   }

 printf("\n");

 printf("Qual é o valor máximo que os números gerados podem tomar?\n");
 scanf("%lf",&m);

 printf("\n");

 printf("Leu '%d' e '%lf' para os valores de 'n' e 'max',respetivamente\n\n", n, m);


 // O programa gera os n aleatórios (através da função srand) e, de seguida, imprime-os no ecrã sem estarem ordenados

 printf ("Valores gerados sem estarem ordenados\n");
 
 srand(time(NULL));
 for(i1=0; i1<n; ++i1)
    {
      x1=((double) rand ()) / ((double) RAND_MAX); //x pertence a [0,1]
      x1= m * x1; //x pertence a [0,m]
      aleat[i1]=x1;

      printf("%2d - %10lf\n", i1, x1); // Imprime os valores gerados sem estarem ordenados
    }


//Bubble Sort - utilizado para ordenar, por ordem decrescente, os n valores gerados

 while (1)
   {
     t=0;
     for (i1=0; i1<n; ++i1)
       {
	 if(aleat[i1]<aleat[i1+1])
	   {
	     p=aleat[i1];
	     aleat[i1]=aleat[i1+1];
	     aleat[i1+1]=p;

	     t=1;
	   }
       }
     
     if(t==0)
       break;
   }

 
 //Imprime no ecrã e no ficheiro os valores já ordenados
 
 printf("\nValores ordenados por ordem decrescente\n");
 
 for(i1=0; i1<n; ++i1)
   {
     printf("%2d - %10lf\n",i1,aleat[i1]);
     fprintf(f1,"%2d - %10lf\n",i1,aleat[i1]);
   }
 

 fclose(f1);
 return 0;
}
