#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char**argv)
{

  int A, B, c, D, E;
  int t1, t2;
  int mdc;
  int mmc;
  
  if(argc !=3) {
    printf ("ERRO! Insira dois números inteiros\n");
    return -1;
  }


  t1 = sscanf (argv[1],"%d", &A);
  printf ("Teste de leitura: %d\n",t1);

  t2 = sscanf (argv[2],"%d", &B);
  printf ("Teste de leitura: %d\n",t2);

  c = A%B;
  if(c==0)
    {
      mdc = B;
      printf ("MDC= %d\n", mdc);
    }

  else {
    while (c!=0)
      {
	D=B;
        E=c;
	c=D%E;

	if (c==0){
	  mdc = E;
	  printf("MDC=%d\n", mdc);
	}
	
      }

     
  }
	  
  mmc=((A*B)/mdc);

  printf("MMC = %d\n",mmc);
	

  return 0;
}
