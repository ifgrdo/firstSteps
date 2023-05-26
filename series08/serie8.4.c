#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

int main(int argc, char**argv){
  DIR *d1;
  struct dirent *dent;
  struct stat buf;
  struct tm *tml;
  char str[32];
  char *v;

  v=(char *) malloc (1000 * sizeof(char));

  if(argc==1){
    d1=opendir(".");

    while((dent=readdir(d1))!=NULL){
      printf("%s\n", dent->d_name);
    }
    
    closedir(d1);
  }

  if(argc==2){
    d1=opendir(argv[1]);

    while((dent=readdir(d1))!=NULL){
      printf("%s\n", dent->d_name);
    }
    closedir(d1);
  } // Falta adicionar o caso correspondente a escrever ls -l no terminal

  if(argc==3){
    d1=opendir(argv[2]);

    while((dent=readdir(d1))!=NULL){

      //fazer teste do tamanho de v
      
      strcpy(v, argv[2]);
       
#ifdef _WIN32
      strcat(v, "\\");

#else
      strcat(v, "/");

#endif

       
      strcat(v,dent->d_name);

       

#ifdef _WIN32
      stat(v, &buf);

#else
      lstat(v, &buf);

#endif

      tml=localtime(&buf.st_mtime);
      strftime(str, 32, "%b %2d %2H:%M ", tml);
      printf("%5d   %s %s\n", buf.st_size,  str, dent->d_name);
    }
    closedir(d1);
  }

  return 0;
}




  
