#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin (int n, char *v){

  int i = 0;
  int a = 0;
  int x;

  if(n==0){
    v[0] = 48;
    v[1] = 0;
  }
      
  else{
    while (n>0){
      v[i]= 48+(n%2);
      n = n/2;
      ++i;
    }
  
    v[i]=0;

    while(a < (i/2)){
      x = v[a];
      v[a] = v[i-1-a];
      v[i-1-a] = x;
      ++a;
    }
  }
}

void oct(int n, char *v){

  int i = 0;
  int a = 0;
  int x;

  if(n==0){
    v[0] = 48;
    v[1] = 0;
  }

  else{

    while (n>0){
      v[i] = 48+(n%8);
      n = n/8;
      ++i;
    }

    v[i]=0;

    while(a < (i/2)){
      x = v[a];
      v[a] = v[i-1-a];
      v[i-1-a] = x;
      ++a;
    }
  }
}


void hex(int n, char *v){

  int i = 0;
  int a = 0;
  int resto, x;

  if(n==0){
    v[0] = 48;
    v[1] = 0;
  }

  else{
 
    while (n>0) {
      resto = n % 16;

      if(resto < 10){
	v[i] = 48 + resto;
	++i;
      }

      if(resto >= 10){
	v[i] = 55 + resto;
	++i;
      }
      n = n/16;
    }
  
    v[i]=0;
  
    while(a < (i/2)){
      x = v[a];
      v[a] = v[i-1-a];
      v[i-1-a] = x;
      ++a;
    }
  }
}
  
int  main ()
{
  char v[10];
  char p[4];
  char k[3];
  int n;

  printf("Representação decimal, binária, octal e hexadecimal\n");

  for (n=0; n<256; ++n){
    bin(n,v);
    oct(n,p);
    hex(n,k);
    printf ("%d %10s %10s %10s\n",n,v,p,k);
  } 
  return 0;
}
