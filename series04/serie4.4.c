#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Função strlen


int
f1(char *str)
{
  int i;
  int tam;
  i=0;

  while (str[i]!=0)
    {
      ++i;
    }
 
  //Como i começa no zero, então o último valor de i obtido corresponde ao comprimento da string;
  return i; 
}



//Função strcopy

char 
*f2 (char *str1, char *str2)
{
  int i;
  i=0;
  
  while (str2[i]!=0)
    {
      str1[i]=str2[i];
      ++i;
    }
  
  //Quando se chegar ao terminador de str2, coloca-se o terminador em str1
  
  if(str2[i]==0){
    str1[i]=0;
  }

  return str1;
}


//Função strcat
  
char 
*f3 (char *str1, char *str2)
{
  int i, p, k, j;
  int tam;
  i=0;
  p=0;

  tam = f1(str1); //Obtém o comprimento de str1

 //Enquando str2 não atingir o terminador, a string str1 recebe o respetivo valor de str2, avançando (i+tam). Inicialmente, i=0, portanto str2[0] ocupa a primeira posição após o final de str1
  
  while (str2[p]!=0)
    {
      str1[i+tam] = str2[p];
      ++i;
      ++p;
    }

  //O último valor de p obtido no ciclo anterior corresponde à posição do terminador em str2. Por isso,faz-se com que a última posição de str1 (tam+p) seja ocupada pelo terminador 

  str1[tam+p]=0;
  
  return str1;
}



//Função strcat
char
*f4 (char *str1, char *str2)
{
  int t;
  t=strlen (str1);

  strcpy(str1 + t, str2);

  return str1;
}
  



int main (int argc, char **argv)
{
  int comp1, comp2, comp3;
  char *v, *b;
  int i;
  char *t;
  char *g;

  i=0;

  if(argc!=3){
    printf("Erro! Insira 2 strings na linha de comandos\n");
  }

  //Comprimento do primeiro argumento
  comp1 = f1(argv[1]);

  //Comprimento do segundo argumento
  comp2 = f1(argv[2]);

  printf("Comprimento da primeira string: %d\n", comp1);
  printf("Comprimento da segunda string: %d\n", comp2);

  
  //Cópia do primeiro argumento para duas novas strings

  comp1 = 1 + comp1; //inclui o terminador
  
  v = (char *) malloc (comp1 * sizeof(char));
  b = (char *) malloc (comp1 * sizeof(char));

  for (i=0; i<=comp1; ++i)
    {
      v[i]=argv[1][i];
      b[i]=argv[1][i];
    }

  printf("\nString depois do malloc: %s\n", v);


  //Realoca espaço para que v fique com o comprimento do 1º argumento + 1

  comp2 = 1 + comp2; //inclui o terminador
  v = (char *) realloc (v, comp2 * sizeof(char));

  printf("String v depois do realloc: %s\n", v);


   //Realoca espaço para que b fique com o comprimento dos dois argumentos + 1

  comp3 = 1 + comp1 + comp2;
  b = (char *) realloc (b, comp3 * sizeof(char));

  printf("String b depois do realloc: %s\n", b);

  
  //Corre a função f2

  t = f2(v, argv[2]);

  printf("\nStrcpy: %s\n", t);
  printf("Comprimento da string: %d", f1(t));
 

  //Corre a função f3
  
  g = f3(b, argv[2]);
  printf("\n");
  printf("\nStrcat: %s\n", g);
  printf("Comprimento da string: %d", f1(g));


  free (v);
  free (b);
  

  return 0;
}
