#include <stdio.h>


float realfordolar(float real, float cotacao) {
	return (real / cotacao);
}

float dolarforreal(float dolar, float cotacao){
		return (dolar * cotacao);
}

int main () {
	   float valor, cotacao, resultado;
	   int opcao;
	   
	   cotacao = 5.11;

	   printf("TABELA DE CONVERSaO\n");
	   printf("1 - converter valor para real:\n\n");
	   printf("2 - converter valor para dolar: \n\n");
	   printf("opçao: \n\n");
	   scanf("%d", &opcao);

	   printf("valor: ");
	   scanf("%f", &valor);
	   
	   switch(opcao){
	   	
	   case 1:
		   resultado = dolarforreal(valor, cotacao);
		   printf("valor em dolar: %.2f\n ", resultado);
		   break;
	   case 2:
	   	resultado = realfordolar(valor, cotacao);
	   	printf("valor em real %.2f\n", resultado);
	   	break;
	   default:
	   	printf("opção invalida", resultado);
	   }
	   return 0;
	   
}