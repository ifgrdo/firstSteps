#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


double
f1 (double a, double b)
{
  double m;
  
  m = sqrt((a*a)+(b*b));

  return m;
}


double
f2 (double a, double b, double c, double d)
{
  double e, f;

  e = a + c;
  f = b + d;

  return e, f;
}



int
main (int argc, char **argv)
{
  double modulo;
  double soma;
  int t1, t2, t3, t4;
  double real1, imag1, real2, imag2;

  if(argc!=5){
    return -1;
  }

  t1 = sscanf(argv[1], "%lf", &real1);
  t2 = sscanf(argv[2], "%lf", &imag1);

  t3 = sscanf(argv[3], "%lf", &real2);
  t4 = sscanf(argv[4], "%lf", &imag2);

  

  modulo = f1(real1, imag1);
  soma = f2(real1, imag1, real2, imag2);

  printf("O módulo do número complexo inserido é: %lf\n", modulo);
  printf("A soma dos números complexos inseridos é: %lf + %lfi\n",soma);

  return 0;
}


  
