#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double
fd(double x)
{

 if(x<0)
    {
   x=fmod (x, 2*M_PI);
    x = x + 2*M_PI;
    }
  
  if(x>0)  x=fmod (x, 2*M_PI);

  return x;
}


double
fat(int n)
{
  double y;
  
  y=1;
     
      while(n>1)
	{
	  y= n * y;
	  --n;
	}
  return y;
}


double
seno(double x)
{
  int i, n;
  double v, t;
 
  v=0;
  i=0;
  t=10; //entra no ciclo
  while (fabs(t)>1e-10)
    {
      n=2*i+1;
      if(i%2==0)
	t=(pow(x,2*i+1))/ fat(n);
      else
	t=-(pow(x,2*i+1))/ fat(n);
      printf("%d -- %8lf\n",i,t);
      v=v+t;
      ++i;
    }
  return v;
}


int
main()
{
  double x,y, v;
  int n;
  

  printf("Insira o valor de x\n");
  scanf("%lf",&x);

  x= fd(x);
  printf("%lf\n", x);

  printf("Insira o valor de n\n");
  scanf("%d",&n);

  y= fat(n);
  printf("%lf\n",y);

  v=seno(x);
  printf("%lf", v);

  return 0;
}


