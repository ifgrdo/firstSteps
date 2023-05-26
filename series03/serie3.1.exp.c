#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  int A, B, C, E, F;
  int t1, t2;
  int mdc, mmc;
  
  if (argc!=3){
    printf ("Insira dois números inteiros na linha de comandos!\n");
    return -1;
  }

  t1 = sscanf(argv[1], "%d", &A);
  printf("Teste de leitura: %d\n", t1);
  if (t1==0) {
    return -1;
  }

  t2 = sscanf(argv[2], "%d",&B);
  printf("Teste de leitura: %d\n", t2);
  if (t2==0) {
    return -1;
  }

  printf("Inseriu os números %d e %d\n", A, B);
  printf("\nCálculo do  máximo divisor comum e do mínimo múltiplo comum entre %d e %d\n", A, B);


  C = A % B;

  if (C==0) {
    mdc = B;
    mmc = (A*B)/mdc;
    
    printf ("O máximo divisor comum entre %d e %d é %d\n", A, B, mdc);
    printf ("O mínimo múltiplo comum entre %d e %d é %d\n", A, B, mmc);
  }


  

  else {
    // Enquanto o resto da divisão for diferente de zero, corre o ciclo
    
    E = A; // de forma a poder ser utilizado o valor inicial no printf
    F = B; // de forma a poder ser utilizado o valor inicial no printf

    while (C!=0)
      {
	A = B;
	B = C;
	C = A % B;
	mdc = B; 
      }

    mmc = (E * F)/mdc;
    
    printf ("O máximo divisor comum entre %d e %d é %d\n", E, F, mdc);
    printf ("O mínimo múltiplo comum entre %d e %d é %d\n", E, F, mmc);
  }

  return 0;
}
