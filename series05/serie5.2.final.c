#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar (double *v, int tam)
{
  int i;
  double x;
  int teste;

  while(1)
    {
      teste = 0;
      for (i=0; i < tam-1; ++i)
	{
	  if(v[i] > v[i+1]){
	    x = v[i];
	    v[i] = v[i+1];
	    v[i+1] = x;
	    teste = 1;
	  }
	}
      if(teste==0)
	break;
    }
}

double *eliminar (double *v, int *qt)
{
  int i = 1;
  int j = 0;
  
  while(v[i]!=0)
    {
      if(v[i]!=v[j]){
	++j;
	v[j]=v[i];
      }
      ++i;
    }

  *qt=j+1; //por exemplo, se j=2, então o tamanho (sem contar com o terminador) é 3

  //ao fazer-se *qt+1 no realloc está-se a incluir o terminador
  v = (double *) realloc (v, (*qt+1) * sizeof(double));

  v[*qt]='\0';

  return v;
}

int main (int argc, char **argv)
{
  int N, M, tam;
  int n, m;
  int i = 0;
  int t1, t2;
  double quoc;
  double *v, *g;

  FILE *f1;

  if(argc!=3){
    printf("Insira, por favor, dois números inteiros positivos\n");
    return -1;
  }
  
  t1 = sscanf(argv[1], "%d", &N);
  t2 = sscanf(argv[2], "%d", &M);

  printf("Teste de leitura 1: %d\n", t1);
  printf("Teste de leitura 2: %d\n", t2);

  if(t1==0 || t2==0){
    printf("Os valores inseridos não são válidos\n");
    return -1;
  }

  if(N<=0 || M<=0){
    printf("Insira 2 números inteiros positivos\n");
    return -1;
  }
  
  if(N>M){
    printf("O primeiro valor tem que ser inferior ou igual ao segundo\n");
    return -1;
  }
    
  printf("N=%d e M=%d\n", N, M);

  tam = N*M;
  printf("Vão ser gerados %d números racionais\n\n", tam);

  v = (double *) malloc ((tam+1) * sizeof(double));

  if(v==NULL){
    return -1;
  }
  
  while(i<tam){
    for (n=1; n<=N; ++n)
      {
	for(m=1; m<=M; ++m)
	  {
	    quoc = ((double)n)/((double)m);
	    v[i] = quoc;

	    printf("%lf\n", v[i]);
	    ++i;
	  }
      }
  }

  v[tam]='\0';
  ordenar(v, tam);

  printf("\nValores ordenados\n");

  for(i=0; i<tam; ++i){
    printf("%lf\n", v[i]);
  }

  //O vetor g só contém os valores não repetidos
  g = eliminar (v, &tam);

  f1 = fopen("dados.txt","wt");
  if(f1 == NULL){
    printf("O ficheiro não foi corretamente aberto\n");
    return -1;
  }
    
  printf("\nSem valores repetidos\n");
  fprintf(f1,"Números racionais obtidos\n");

  for(i=0; i<tam; ++i){
    printf("%lf\n", g[i]);
    fprintf(f1,"%lf\n", g[i]);
  }
  
  fclose(f1);
  free(v);
  return 0;
}
