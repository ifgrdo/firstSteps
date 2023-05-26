#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main ()
{
  int n, t1,x1,g, te; //n-valor máximo
  g=1;
  te=0;
printf("Qual é o valor máximo para o qual quer gerar um número aleatório?\n");
scanf("%d", &n);

 if(n<500)
   {
     printf("ERRO! O valor inserido deve ser supeior a 500");
     return 1;
   }




 while(g==1)
   {
 
 srand(time(NULL));
 x1=rand () % n+1;

 printf("%d\n", x1);

     
printf("Qual é o número?\n");
 scanf("%d", &t1);



 while(t1!=x1)
   {

     if(t1<x1) printf("Ainda não foi desta vez! O número gerado é maior que o que escreveu\n");

     if(t1>x1) printf("Ainda não foi desta vez! O número gerado é menor que o que escreveu\n");
 
 printf("Tente outra vez!\n");
 scanf("%d",&t1);
 
 ++te;
   
   }


 if(t1==x1) printf("Parabéns! Acertou após %d tentativas erradas.\n", te);

 printf("Deseja voltar a jogar? Prima 1 em caso afirmativo e 0 se não quiser continuar.\n");
 scanf("%d", &g);

 if(g==1) te=0;
   }
 return 0;
}
