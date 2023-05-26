#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FNAME_DATA       "equacao_diferencial.txt"
#define GNUPLOT_COMMAND  "gnuplot serie8.1__Gnuplot"

int main (int argc, char **argv){
  double k, xo, ti, tf, dt, t, x;
  FILE *f1;

  

  f1=fopen("equacao_diferencial.txt", "wt");
  
  if (argc!=6)
    return -1;

  sscanf(argv[1], "%lf", &k);
  sscanf(argv[2], "%lf", &xo);
  sscanf(argv[3], "%lf", &ti);
  sscanf(argv[4], "%lf", &tf);
  sscanf(argv[5], "%lf", &dt);

  


  for(t=ti; t<=tf; t=t+dt){
    x=xo-k*xo*dt;
    if(t==ti)x=xo;
    printf("t=%lf  x=%lf\n", t, x);
    fprintf(f1,"%lf    %lf\n", t, x);

    xo=x;
  }

 system (GNUPLOT_COMMAND);

  fclose(f1);
  return 0;
}
