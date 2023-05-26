#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hora
{
  int h  ;
  int m  ;
  int s  ;
};



struct somahora
{
  int h ;
  int m ;
  int s;
};


int
main (int argc, char **argv)
{
  int t1, t2, ns1, ns2, nm1, nm2;
  double d1, d2;
  
  struct hora h1;
  struct hora h2;


  // Se o número de argumentos for inferior a 3, o programa pára;
  
  if (argc !=3){
    printf("ERRO!Deve introduzir 2 informações horárias\n");
    return -1;
  }


  //Leitura dos valores introduzidos na linaha de comandos e respetivos testes de leitura
  
  t1 = sscanf(argv[1],"%d:%d:%d",&h1.h, &h1.m, &h1.s);

  printf("Teste de leitura 1: %d\n",t1);
  if (t1!=3){
    return -1;
  }

  t2 = sscanf(argv[2],"%d:%d:%d", &h2.h, &h2.m, &h2.s);

  printf("Teste de leitura 2: %d\n\n", t2);
  if (t2!=3){
    return -1;
  }


  //Verifica se os valores introduzidos na linha de comandos satisfazem determinadas condições. Caso verifique, o programa continua; caso contrário, pára

  //h1

  if(0<=h1.h && h1.h<24 && 0=<h1.m && h1.m<60 && 0<=h1.s && h1.s<60){
    printf("A primeira informação horária introduzida está correta!\n");
  }

  else {
    printf ("ERRO! A primeira informação horária não está escrita corretamente!\n");
    return -1;
  }


  //h2
  
   if(0<h2.h && h2.h<24 && 0<h2.m && h2.m<60 && 0<h2.s && h2.s<60){
    printf("A segunda informação horária introduzida está correta!\n\n");
  }

  else {
    printf ("ERRO! A segunda informação horária não está escrita corretamente!\n");
    return -1;
  }



   //Imprimir as duas informações horárias

   printf("1ª informação horária: %d:%d:%d\n", h1.h, h1.m, h1.s);
   printf("2ª informação horária: %d:%d:%d\n\n", h2.h, h2.m, h2.s);



   //Número de segundos desde o início do dia

   ns1 = 3600*h1.h + 60*h1.m + h1.s;

   ns2 = 3600*h2.h + 60*h2.m + h2.s;

   printf("Número de segundos desde o início do dia\n");
   printf("Primeira informação horária: %d segundos\n",ns1);
   printf("Segunda informação horária: %d segundos\n\n",ns2);

  

   //Número de minutos desde o início do dia
   
   nm1 = 60*h1.h + h1.m;
   /*parte decimal*/
   d1 = ((double)h1.s / 60);

   nm2 = 60*h2.h + h2.m;
   /*parte decimal*/
   d2= ((double)h2.s / 60);

   printf("Número de minutos desde o início do dia\n");
   printf("Primeira informação horária: %d.%lf minutos\n", nm1, d1);
   printf("Segunda informação horária: %d.%lf minutos\n", nm2, d2);



   //Soma das informações horárias obtidas

   struct somahora hfinal = {h1.h + h2.h, h1.m + h2.m, h1.s + h2.s};

   printf("\nSoma das duas informações horárias inseridas na linha de comandos: %d:%d:%d\n", hfinal.h, hfinal.m, hfinal.s);
   
  return 0;
}
  
