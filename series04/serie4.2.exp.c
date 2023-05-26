#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct complexo {
  double real;
  double imag;
};


int main (int argc, char **argv)
{
  int t1, t2, t3, t4, t5;
  char operacao;
  double re1, re2, imag1, imag2;


  
  if (argc!=6){
    printf("Insira a operação que quer efetuar e dois números complexos, na seguinte forma: <operação> <Re z1> <Im z1> <Re z2> <Im z2>\n");
    return -1;
  }


  t1 = sscanf(argv[1], "%s", &operacao);
  printf("%s", operacao);

  t2 = sscanf(argv[1], "%s", &re1);
  printf("%lf",re1);

   t3 = sscanf(argv[1], "%s", &imag1);
  printf("%lf", imag1);

   t4 = sscanf(argv[1], "%s", &re2);
  printf("%lf", re2);

   t5 = sscanf(argv[1], "%s", &imag2);
  printf("%lf", imag2);

  
  
  



  return 0;
}

