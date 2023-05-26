#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char **argv)
{
  int t1, i;
  double x, r, z;

  FILE *f1;

  f1=fopen("Bernoulli.dat.txt", "wt");

  
  if (argc!=2){
    printf("Insira uma condição inicial\n");
    return -1;
  }

  t1 = sscanf (argv[1], "%lf", &x);
  printf("Teste de leitura: %d\n", t1);

  if(t1==0){
    printf("Não inseriu um número natural!\n");
    return -1;
  }

  printf("Leu: %lf\n", x);


  for (i=0; i<100; ++i)
    {
      x = 2 * x;
      r = modf(x,&z);
      printf ("%2d ----%2.10lf\n",i, r);
      fprintf(f1, "%2d      %2.10lf\n", i, r);
    }

  fclose (f1);
  return 0;
}
