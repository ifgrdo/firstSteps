#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void help(){
  printf("\nEste programa efetua somas, diferenças e multiplicações de matrizes\n");
  printf("\nOperações disponíveis:\n");
  printf("\nSoma de matrizes - <soma>\n");
  printf("Diferença de matrizes - <diferenca>\n");
  printf("Multiplicação de matrizes - <multiplicacao>\n");
  
  printf("\n<./nome_programa> <operação a efetuar> <ficheiro que contém a matriz 1> <ficheiro que contém a matriz 2>\n");
}

double **ler_matriz(char *v, int *m, int *n){

  int i, j;
  FILE *f1;
  double **p;
  
  f1 = fopen(v, "rt");

  if(f1==NULL){
    printf("O ficheiro não foi corretamente aberto\n");
  }

  //Os vetores m e n passam a apontar para os valores lidos no ficheiro 
  fscanf(f1,"%dx%d",m,n);

  p = (double **) malloc ((*m)*sizeof(double*));
  if(p==NULL){
    printf("ERRO!");
  }

  for (i=0; i<*m; ++i){
    p[i] = (double *) malloc ((*n)*sizeof(double));
    if (p[i]==NULL){
      printf("ERRO!\n");
    }
  }
  
  
  for(i=0; i<*m; ++i)
    {
      for (j=0; j<*n; ++j)
	{
	  fscanf(f1,"%lf",&p[i][j]);
	}
    }
  
  fclose(f1);
  return p;
}


void imprimir_matriz(double **u, int m, int n){
  int i, j;
  for(i=0; i<m; ++i)
    {
      for (j=0; j<n; ++j)
	{
	  printf("%lf   ",u[i][j]);
	}
      printf("\n");
    }
}

void soma_matriz (double **p, double **g, double **r, int m, int n){
  int i, j;

  for(i=0; i<m; ++i)
    {
      for (j=0; j<n; ++j)
	{
	  r[i][j] = p[i][j] + g[i][j];
	}
    }
}

void diferenca_matriz (double **p, double **g, double **r, int m, int n){
  int i, j;

  for(i=0; i<m; ++i)
    {
      for (j=0; j<n; ++j)
	{
	  r[i][j] = p[i][j] - g[i][j];
	}
    }
}

void multipl_matriz (double **p, double **g, double **r, int m, int c, int k){
  int i, j, t;

  //A variável k recebe o número de colunas da primeira matriz (que corresponde ao número de linhas da segunda)
  
  for(i=0; i<m; ++i)
    {
      for (j=0; j<c; ++j)
	{
	  r[i][j]=0;
	  for (t=0; t<k; ++t)
	    {
	      r[i][j] = r[i][j] +  p[i][t] * g[t][j];
	    }
	}
    }
}

int main (int argc, char **argv){
  
  int m = 0;
  int n = 0;
  int l = 0;
  int c = 0;
  int i, j;
  double **p;
  double **g;
  double **r;
  int mfinal, nfinal;
  int k;

  if(argc!=4){
    help ();
    return -1;
  }
  
  p = ler_matriz(argv[2], &m, &n);
  g = ler_matriz(argv[3], &l, &c);
  
  printf("Matriz 1:\n");
  printf("As dimensões da matriz 1 são %dx%d\n", m, n);
  imprimir_matriz(p, m, n);

  printf("\nMatriz 2:\n");
  printf("As dimensões da matriz 2 são %dx%d\n", l, c);
  imprimir_matriz(g, l, c);


  //Testes de dimensões
  if((strcmp(argv[1], "soma")==0) || strcmp(argv[1], "diferenca")==0){
    if((m==l) && (n==c)){
      printf("\nÉ possível efetuar a operação pedida!\n");
      printf("A matriz resultante terá dimensões %dx%d\n\n", m, n);
      mfinal=m;
      nfinal=n;
    }

    else{
      printf("\nERRO! As dimensões das matrizes não são compatíveis para efetuar a soma!\n");
      return -1;
    }
  }

  if(strcmp(argv[1], "multiplicacao")==0){
    if (n==l){
      printf("\nÉ possível multiplicar as matrizes!\n");
      printf("A matriz resultante terá dimensões %dx%d\n\n", m, c);
      mfinal=m;
      nfinal=c;
      k = n; 
    }

    else{
      printf("ERRO! Para efetuar a operação selecionada, o número de colunas da primeira matrtiz deverá ser igual ao número de linhas da segunda matriz\n");
      return -1;
    }
  }

  //Alocação de memória
  r = (double **) malloc (mfinal * sizeof(double*));

  for (i=0; i<m; ++i){
    r[i] = (double *) malloc (nfinal * sizeof(double));
  }
  
  //Operação pedida

  if((strcmp(argv[1], "soma"))==0){

    soma_matriz(p, g, r, mfinal, nfinal);
    imprimir_matriz(r, mfinal, nfinal);
  }

  if((strcmp(argv[1], "diferenca"))==0){

    diferenca_matriz(p, g, r, mfinal, nfinal);
    imprimir_matriz(r, mfinal, nfinal);
  }

  if((strcmp(argv[1], "multiplicacao"))==0){
    multipl_matriz(p, g, r, mfinal, nfinal, k);
    imprimir_matriz(r, mfinal, nfinal);
  }

  else{
    help();
  }
    
  free(r);
  return 0;
}
