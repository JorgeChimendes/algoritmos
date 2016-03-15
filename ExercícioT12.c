#include <stdio.h>
#include <stdlib.h>

#define N1 13
#define N2 10
#define NOMES 100
#define VET 53

int main (){
	int n1 = N1, n2 = N2, c, i, x, z, dif, soma;
	int v[VET];
	char user[NOMES], pai[NOMES], mae[NOMES];

	if(n1>n2){
		c = n1;
	}
	else{
		c = n2;
	}

	printf("O valor de N1 é: %d\n", n1);
	printf("O valor de N2 é: %d\n", n2);

	if(n1>n2){
		printf("O maior valor é: %i.\n E o menor valor é: %i\n",n1,n2);
	}
	else if(n1==n2){
		printf("Os dois valores sao iguais.\n");
	}
	else{
		printf("O maior valor é: %i.\n E o menor valor é: %i\n",n2,n1);
	}
		
	//LEITURA DOS NOMES
		printf("================================\n");
		printf("Digite o seu nome(sem acentos):\n");
		fgets(user,NOMES,stdin);
		printf("Digite o nome do seu pai(sem acentos):\n");
		fgets(pai,NOMES,stdin);
		printf("Digite o nome da sua mae(sem acentos):\n");
		fgets(mae,NOMES,stdin);
		printf("================================\n");
	
		if(n1>n2){
		dif = n1-n2;
		if ( (n2 % 2) == 0) {
			printf("N2 e um numero par \n");
		}else{
			printf("N2 e um numero impar \n");
		}			
	}
	else{
		dif = n2-n1;
		if ((n1 % 2) == 0) {
			printf("N1 e um numero par \n");
		}
		else {
			printf("N1 e um numero impar \n");
		}
	}
		
	for(i=0;i < VET;i++){
		do {
			printf("digite um valor: ");
			scanf("%d", &v[i]);
			printf("\n");			
			if (v[i] < 0) {
				printf("error! valores negativos nao podem ser inseridos.\n\n");
			}
		} while (v[i] < 0);
		//feito no t11 <t11>
		if(i == 0){
			v[0]=0;
		}
		else{
			v[i] = v[i-1] + dif;
		}
		printf("Posicao[%i] = %d \n",i,v[i]);
		if(v[i] > 1000){
			v[i]=i;
		}
		//</t11>
	}
	printf("\n==========================\n");
	// CALCULAR SE OS NUMEROS DO VETOR SAO PARES OU IMPARES E PRIMOS
	for(i = 0;i < VET;i++){
		if(v[i]%2 == 0){
			printf("\nO valor %i corresponde a um numero PAR.",v[i]);
		}
		else{
			printf("\nO valor %i corresponde a um numero IMPAR.",v[i]);
		}
		soma=0;
		for(x = 1;x < VET;x++){
			if(v[i]% x ==0){
				soma++;
			}
		}
		if(soma==1){
			printf("E tambem e um numero PRIMO.");
		}
		else{
			soma=0;
			z= v[i];
			while(soma!=2){
				soma=0;
				z++;
				for(x = 1; x <= z; x++){
					if(z%x==0){
						soma++;
					}
				}
				if(soma==2){
					printf(" %i nao e primo. O proximo primo e %i \n",v[i],z);
				}
			}
		}
		printf("\n==========================\n");
	}
	return 0;
}
