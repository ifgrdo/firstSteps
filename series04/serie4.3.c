#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int
main (int argc, char **argv)
{
  int a, n, num, m, y, x;



  a=0;

  sscanf(argv[1], "%d", &n);
  

  //Numero algarismos

  
  while(n!=0)
    {
      n=n/10;
      ++a;
    }

  printf("%d elementos", a);
  
  num=0;
  
  while (m<a) 
    {
      x=n%10;
      
      y=pow(x,a);

      num=num +y;

      ++m;
    }

  //Para fazer o resto do ex basta testar todos os valores até um dado pelo utilizador e ver quantos/quais são num armstrong


  // while (

  if(num==n) printf("numero armstrong");
      
  else printf("não é");


  



  return 0;
}
