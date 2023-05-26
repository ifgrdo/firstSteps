#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/* Série 7
   Programa 3
   Ivan Figueiredo, 93386
   Tiago Miranda, 93416
*/

void inf(){
  printf("************************INFORMACAO***************************\n");
  printf("\nEste programa calcula todos os números primos até um valor máximo N, fornecido pelo utilizador na linha de comandos\n");
  printf("\nNOTA: N é um número inteiro\n");
  printf("*************************************************************\n");
}

void fim(){
  printf("************************FIM DO PROGRAMA***********************\n");
}

int main(int argc, char **argv){
  
  int N,teste;
  int t1, t2, t3, t4;
  int i, k, contador;
  int h, n, j;
  int *v;
  int q=1;
  
  FILE *f1, *f2;
  
  if(argc!=2){
    inf ();
    return -1;
  }
  
  inf();

  t1=sscanf(argv[1], "%d", &N);
  if(t1!=1){
    inf ();
    return -1;
  }
    
  printf("\nPediu para calcular todos os números primos até %d\n", N);

  v=(int*) malloc ((N+1)*sizeof(int));
  if(v==NULL){
    free(v);
    return -1;
  }

  teste=sqrt(N);
  
  for(i=0; i<=N; ++i){
    v[i]=1;
  }
  
  for(i=2; i<=teste; ++i){
    for(k=i+1; k<=N; ++k){
      if(k%i==0){
	v[k]=0;
      }
    }
  }
  
  contador=0;
  printf("\n\nNumeros primos até %d\n", N);

  f1=fopen("numeros_primos.txt", "wb");
  if(f1==NULL){
    free(v);
    return -1;
  }

  for(i=2; i<=N; ++i){
    if(v[i]==1){
      printf("%d  ", i);
      fwrite(&i, sizeof(int), 1, f1);
      ++contador;
      
      if(contador%6==0){
	printf("\n");
      }
    }
  }

  fclose(f1);

  printf("\n\nHá %d números primos até %d\n", contador, N);

  printf("\n\nQuer ver algum número primo em específico?\n");
  printf("1 -- Sim\n");
  printf("0 -- Não\n");

  t2=scanf("%d", &h);
  if(t2!=1){
    printf("ERRO DE LEITURA! Deverá inserir '1' em caso afimativo e '0' em caso negativo!\n");
    free(v);
    return -1;
  }

  if(h!=1 && h!=0){
    printf("ERRO! Deverá inserir '1' em caso afimativo e '0' em caso negativo!\n");
    free(v);
    return -1;
  }
  
  if(h==0){
    fim();
    free (v);
    return -1;
  }
    
  if(h==1){
    while(q=1){
      printf("\nQual é a ordem do número primo que deseja visualizar?\n");

      t3=scanf("%d", &n);
      if(t3!=1){
	printf("Deverá inserir a ordem do número primo que deseja visualizar\n");
	free (v);
	return -1;
      }

      if(n<1 || n>contador){
	printf("ERRO!\n");
	free(v);
	return -1;
      }
    
      printf("\nPediu para obter o %d número primo\n", n);
      f2=fopen("numeros_primos.txt", "rb");
      if(f2==NULL){
	free(v);
	return -1;
      }
      
      if(fseek(f2, (n-1)*sizeof(int), SEEK_SET) !=0){
	printf("ERRO! Não foi possível posicionar-se no sítio pretendido\n");
	free(v);
	return -1;
      }
      
      if(fread(&j, sizeof(int), 1, f2) !=1){
	printf("ERRO! A leitura não foi feita de forma correta!\n");
	free(v);
	return -1;
      }

      printf("\nO número primo solicitado é: %d\n",j);

      fclose(f2);

      printf("\nDeseja visualizar mais algum número?\n");
      printf("1 - Sim\n");
      printf("0 - Não\n");
     
      t4=scanf("%d", &q);
      if(t4!=1){
	printf("Deverá inserir a ordem do número primo que deseja visualizar\n");
	free (v);
	return -1;
      }

      if(q!=1){
	fim ();
	free(v);
	return -1;
      }
    }
  }
  
  free(v);
  return 0;
}
