#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double integral (double(*f)(double), double inf, double sup){
  double x, altura, area;
  double integ=0;
  double i;

  x=(sup - inf)/1000;
  printf("%lf", x);
  
  i=inf;
  
  while(i<=sup)
    {
      altura = f(i+(x/2));
      area = x*altura;
      integ = integ + area;


      i = i + x;
    }

  return integ;
}

double a (double x){
  return 5*cos(3*x)*exp(-0.2*x);
}


double b (double x){
  return exp(5*x);
}

double c (double x){
  return 3*cos(2*x)*sin(4*x);
}
  
int main (int argc, char **argv){

  int f;
  int t1, t2, t3;
  double inf,sup;
  int k=1;

  while(k==1){
  
    printf("Este programa calcula numericamente o valor da derivada de uma função num ponto\n");
    printf("\nFunções disponíveis:\n");
  
    printf("\n1 -- sin(x)\n");
    printf("2 -- 5cos(3x)exp(-0.2x)\n");
    printf("3 -- sqrt(x)\n");
    printf("4 -- 3x^5-3x\n");
    printf("5 -- exp(x)\n");
    printf("6 -- (1/sqrt(pi))exp(-x^2)\n");
 

    printf("\nSelecione a função a derivar - insira um número entre 1 e 6\n");
    t1=scanf("%d", &f);

    if(t1==0){
      return -1;
    }

    if(f<1 || f>6){
      printf("Selecione uma das funções disponíveis\n");
      return -1;
    }

    printf("Insira o limite inferior de integração\n");
    t2=scanf("%lf",&inf);

    printf("%lf\n", inf);

    printf("Insira o limite superior de integração\n");
    t3=scanf("%lf", &sup);
        printf("%lf\n", sup);

	
    if(t2==0){
      return -1;
    }

    //  printf("\nCálculo da derivada da função (%d) no ponto x=%lf\n",f,p);
  
    if(f==1){
      printf("A função sen(x) está definida em IR\n");
      printf("Valor obtido numericamente: %lf\n", integral(sin, inf, sup));
    }
   
    if(f==2){
      printf("A função cos(3x) está definida em IR\n");
      printf("O valor da derivada é %lf\n", integral(a, inf, sup));
    }
    /*
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
    */

    printf("\nDeseja voltar a calcular o valor da derivada de uma função num ponto?\n");
    printf("1 -- Sim\n");
    printf("2 -- Não\n");
  
    scanf("%d", &k);
  }
  
  return 0;
}
