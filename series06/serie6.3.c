#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){

  FILE *f1, *f2;
  char v[1024];
  int i = 0;
  int l, x;

  f1 = fopen(argv[1], "rt");
  f2 = fopen(argv[2], "wt");

  
  while (1){
    if(fgets(v, 1024, f1)==NULL){
      break;
    }
    printf("%s\n", v);

    l=strlen(v);



    if(v[l-1]==10 && v[l-2]!=13){
      l=l-1;
    }

    if(v[l-1]==10 && v[l-2]==13){
      l=l-2;
    }
    
    for(i=0; i<(l/2); ++i){
      x=v[i];
      v[i]=v[l-i-1];
      v[l-i-1]=x;
    }

   printf("%s\n", v);
   fprintf(f2,"%s\n", v);
   x=0;
  }


  return 0;
}
