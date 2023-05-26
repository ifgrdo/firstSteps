#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
fa (char*str, char ch1)
{
  int i, ct;
  
  i=0;
  ct=0;

  while(str[i]!=0)
    {
      if(str[i]==ch1)
	{
	  ++ct;
	}
      ++i;
    }
  return ct;
}





int
fb (char*str1, char ch11)
{
  int p,i;
  i=0;
  p=0;
  char *res; 
  
  while(str1[i]!=0)
    {
      if (str1[i]==ch11)
	{
	  p=i+1;
	  break;
	}
      ++i;
    }

  if(p==0) p=-1;
  
  return p;
}



char
fc (char*str2, char ch22, char ch23)
{
  int i;
  i=0;
  while(str2[i]!=0)
    {
      if(str2[i]==ch22)
	{
	  str2[i]=ch23;
	}
      ++i;
    }
  

  return *str2;
}






int
    main (int argc, char**argv)
  {
    int ct1, pos;

 
    ct1 = fa(argv[1], argv[2][0]);
    pos = fb (argv[1], argv[2][0]);
    
    


    //Indica o número de vezes que o caracter se repete
    printf("O caracter repete-se %d vezes\n", ct1);


    //Posição do caracter
    if(pos==-1){
      printf("Não há valores iguais!");
      return -1;
    }
		  
    else {
      printf("Pos= %d", pos);
    }

   *res = fc(argv[1], argv[2][0], argv[3][0]);
   sprintf("%s", *res);



    return 0;
  }
