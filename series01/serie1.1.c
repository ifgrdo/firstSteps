#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{

  double x, y, r; //x - abcissa; y - ordenada; r - razão entre nc e n;
  int i, n; // i - contador; n - número total de pontos; 
  int nc=0; //nc -  número de pontos que ficam no círculo


  printf("Problema da Agulha de Buffon\n\n");
  printf("Este problema consiste em gerar aleatoriamente pontos num quadrado centrado na origem e de lado 1 e contar aqueles que caem no círculo de raio 0.5 inscrito nesse mesmo quadrado.\n");
  
  srand (time(NULL));

  // Pergunta ao utilizador quantos números quer gerar
  
  printf ("Quantos pontos  quer gerar?\n");
  scanf ("%d",&n);
  printf("\n");
  printf("Pediu para gerar %d números aleatórios\n\n", n);


  
  for (i=1; i<=n; ++i)
    {
      //Seja x a abcissa do ponto gerado;
      
      x = ((double)rand() )/((double)RAND_MAX);  //x pertence a [0, 1];
      x = x-0.5; //x pertence a [-0.5,0,5]

      //Seja y a ordenada do ponto gerado

      y = ((double)rand() )/((double)RAND_MAX); //y pertence a [0,1]
      y = x-0.5; //y pertence a [-0.5,0.5]

      printf("Gerou o ponto (%4lf,%4lf)\n",x,y);

      

      
  //O círculo está centrado na origem e tem raio 0.5. Portanto, a equação do circulo é x^2+y^2 <=0.25
      
      if (x*x + y*y <= 0.25){
	printf("O ponto gerado pertence ao círculo centrado na origem e de raio 0.5\n\n");
	nc=nc+1; //Quando se obtém um ponto no círculo, nc incrementa 1 unidade;	
      }
      
      else {
	printf("O ponto gerado NÃO pertence ao círculo centrado na origem e de raio 0.5\n\n");
      }    
    }


  printf("%d pontos dos %d pontos gerados pertencem ao círculo centrado na origem e de raio 0.5\n",nc, n);

  r = 4*((double)nc / (double)n); // Quádruplo da razão entre o número de pontos que caem no círculo e o número total de pontos gerados;

  printf("r = %lf\n",r);
 
  return 0;
}


