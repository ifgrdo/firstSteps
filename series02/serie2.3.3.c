#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int
main (int argc, char**argv)
{
  int l1,l2;
  char *sl;
  
  printf("argv[1]= %s\n", argv[1]);
  printf("argv[2]= %s\n", argv[2]);

  l1= strlen(argv[1]);
  l2= strlen(argv[2]);

 printf("%d %d\n", l1, l2);


 sl= (char *)malloc((l1+l2+1) * sizeof(char));
 strcpy(sl,argv[2]);
 strcat(sl, argv[1]);
 
 printf("%s", sl);




  return 0;
}
