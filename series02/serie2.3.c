#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int
main (int argc, char**argv)
{
  int l1,l2;
  char *sl;
  char *s2;
  
  printf("argv[1]= %s\n", argv[1]);
  printf("argv[2]= %s\n", argv[2]);

  l1= strlen(argv[1]);
  l2= strlen(argv[2]);

 printf("%d %d\n", l1, l2);


 sl= (char *)malloc((l1+l2+1) * sizeof(char));
 strcpy(sl,argv[1]);
 strcat(sl, argv[2]);
 
 printf("%s\n", sl);

  s2= (char *)malloc((l1+l2+1) * sizeof(char));
 strcpy(s2,argv[2]);
 strcat(s2, argv[1]);
 
 printf("%s\n", s2);

 strcmp(sl,s2);
 
 if(strcmp>0)
   printf("A string sl é menor que s2");

 if(strcmp<0)
   printf("A string sl é maior que s2");

 



  return 0;
}
