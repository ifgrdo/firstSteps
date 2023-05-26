#include <stdio.h>

void // A função fib é do tipo void, pois não retorna qualquer valor
fib (int n, int *v) //n - variável pedida ao utilizador; v - vetor onde são guardados os n primeiros elementos 
{
  int i; //i - ordem de cada elemento da Sucessão de Fibonacci

  v[0]=0;
  v[1]=1;

  //Ciclo que calcula os n primeiros elementos da Sucessão e os guarda num vetor
  
  for(i=2; i<=n; ++i)
    {
      v[i]=v[i-1] + v[i-2]; 
    }
}



int main()
{
  int n, i;
  int v[46]; //Utiliza-se o valor de 46 visto que n assume valores entre 0 e 45

  
  //Abertura de um canal (f1) para escrita do ficheiro "Fibonacci.txt"
  
  FILE *f1;
  f1=fopen("Fibonacci.txt", "wt");
  
  printf("Até que ordem ('n') da Sucessão de Fibonacci deseja obter os valores?\n");
  scanf("%d", &n);

 
  if(n<0 || n>45)
    {
      printf("ERRO! O valor de n deve estar compreendido entre 0 e 45\n");

      return 1;
    }

  fib(n,v); //A função fib corre;


  //Ciclo que imprime os valores da Sucessão no ecrã e num ficheiro

  printf("\nValores da Sucessão de Fibonacci\n");
   
  for (i=0; i<=n; ++i)
    {
      fprintf(f1, "%d ", v[i]);
      printf("%d ", v[i]);

      if (i%6==5) //Para imprimir 6 valores por linha no ecrã e no ficheiro
	{
	  printf ("\n");
	  fprintf(f1,"\n");
	}
    }

  return 0;
}



     
