#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double derivada (double(*f)(double), double x){
  double h;
  double deriv;

  if(x==0) h=1e-6;
  if(x!=0) h=x*(1e-6);

  deriv = (f(x+h)-f(x))/h;

  return deriv;
}

double a (double x){
  return cos(3*x);
}


double b (double x){
  return exp(5*x);
}

double c (double x){
  return 3*cos(2*x)*sin(4*x);
}
  
int main (int argc, char **argv){

  int f;
  int t1, t2;
  double p;
  int k=1;

  while(k==1){
  
    printf("Este programa calcula numericamente o valor da derivada de uma função num ponto\n");
    printf("\nFunções disponíveis:\n");
  
    printf("\n1 -- sin(x)\n");
    printf("2 -- cos(3x)\n");
    printf("3 -- tan(x)\n");
    printf("4 -- arcsin(x)\n");
    printf("5 -- arccos(x)\n");
    printf("6 -- log(x)\n");
    printf("7 -- log10(x)\n");
    printf("8 -- exp(5x)\n");
    printf("9 -- 3cos(2x)sin(4x)\n");

    printf("\nSelecione a função a derivar - insira um número entre 1 e 9\n");
    t1=scanf("%d", &f);

    if(t1==0){
      return -1;
    }

    if(f<1 || f>9){
      printf("Selecione uma das funções disponíveis\n");
      return -1;
    }

    printf("Em que ponto deseja calcular a derivada?\n");
    t2=scanf("%lf",&p);

    if(t2==0){
      return -1;
    }

    printf("\nCálculo da derivada da função (%d) no ponto x=%lf\n",f,p);
  
    if(f==1){
      printf("A função sen(x) está definida em IR\n");
      printf("Valor obtido numericamente: %lf\n", derivada (sin, p));
      printf("Valor exato: %lf\n",cos(p);
    }

    if(f==2){
      printf("A função cos(3x) está definida em IR\n");
      printf("O valor da derivada é %lf\n", derivada (a, p));
    }

    if(f==3){
      printf("A função tan(x) não está definida nos pontos da forma x=(pi/2)+kpi\n");
      printf("O valor da derivada é %lf\n", derivada (tan, p));
    }
  
    if(f==4){
      printf("A função arcsin(x) está definida no intervalo [-1,1]\n");
      if(p<-1 || p>1){
	printf("ERRO! A função selecionada não está definida em x=%d\n", p);
	return -1;
      }
      printf("O valor da derivada é %lf\n", derivada (asin, p));
    }

    if(f==5){
      printf("A função arccos(x) está definida no intervalo [-1,1]\n");
      if(p<-1 || p>1){
	printf("ERRO! A função selecioanda não está definida em x=%d\n", p);
	return -1;
      }
      printf("O valor da derivada é %lf\n", derivada (acos, p));
    }

    if(f==6){
      printf("A função log(x) está definida em IR+\n");
      if(p<=0){
	printf("ERRO! A função selecionada não está definida em x=%d\n", p);
	return -1;
      }
      printf("O valor da derivada é %lf\n", derivada(log, p));
    }

    if(f==7){
      printf("A função log10(x) está definida em IR+\n");
      if(p<0){
	printf("ERRO! A função selecionada não está definida em x=%d\n", p);
	return -1;
      }
      printf("O valor da derivada é %lf\n", derivada(log10, p));
    }

    if(f==8){
      printf("A função exp(5x) está definida em IR\n");
      printf("O valor da derivada é %lf\n", derivada(b, p));
    }

    if(f==9){
      printf("A função 3cos(2x)sin(4x) está definida em IR\n");
      printf("O valor da derivada é %lf\n", derivada(c, p));
    }


    printf("\nDeseja voltar a calcular o valor da derivada de uma função num ponto?\n");
    printf("1 -- Sim\n");
    printf("2 -- Não\n");
  
    scanf("%d", &k);
  }
  
  return 0;
}
