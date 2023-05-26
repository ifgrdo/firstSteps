#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
main (int argc, char**argv)
{
  int N, t1;
  int i, x1, i1, cont, cpos, cneg, cpar, cimp;
  int v[201];

  if (argc!=2) {
    printf("Insira um valor válido!\n");
    return -1;
  }

  //Ler o valor inserido na linha de comandos

  t1 = sscanf(argv[1],"%d", &N);
  printf("Teste de leitura: %d\n", t1);
  if(t1!=1){
    printf("ERRO\n");
    return -1;
  }

  i1=0;
  cont=0;
  cpar=0;
  cimp=0;

  //Gerar os N inteiros
  
  srand(time(NULL));

  for (i=0; i<N; ++i){
    x1 = rand () %201;
    x1 = x1 - 100;
    printf("%2d -- %3d\n", i, x1);
    v[x1+100]=v[x1+100]+1;    
  }

  printf("Leu o  valor de %d para N\n", N);

  //Verificar quantas vezes cada número aparece

  for(x1=0; x1<N; ++x1)
    {
      for(i1=0; i1<N; ++i1)
	{
	      
	  if(v[x1+100]==v[x1+100+i1])
	    {
	      ++cont;
	    }
	}
      printf("%d\n", v[x1+100]);
      printf("%d -- %d vezes\n", x1, cont);
      cont=0;
      i1=0;
    }


  // Verificar quantos números positivos e negativos  foram gerados

   for(x1=0; x1<N; ++x1)
    {
         
	  if(v[x1+100]>=0)
	    {
	      ++cpos;
	    }
	  else{
	    ++cneg;
	  }

      printf("%d\n", v[x1+100]);
     
     
    }

     printf("Foram gerados %d números positivos e %d números negativos\n", cpos, cneg);


     // Verificar quantos números pares e quantos números ímpares foram gerados

   for(x1=0; x1<N; ++x1)
    {
         
	  if(v[x1+100]%2==0)
	    {
	      ++cpar;
	    }
	  else{
	    ++cimp;
	  }

      printf("%d\n", v[x1+100]);
     
     
    }

   printf("Foram gerados %d número(s) par(es) e %d número(s) ímpar(es)\n", cpar, cimp);
     
	  
  return 0;
}
