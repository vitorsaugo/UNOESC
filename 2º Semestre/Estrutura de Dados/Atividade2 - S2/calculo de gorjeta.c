#include <stdio.h>

void calculovalores(float vConsumo, float vGorjeta){

float taxagorjeta =  vConsumo * (vGorjeta / 100);
float valortotal = vConsumo + taxagorjeta;

printf("Valor consumido: %.2f\n", vConsumo);
printf("valor total da gorjeta: %.2f\n", taxagorjeta);
printf("taxa da gorjeta %.2f\n", vGorjeta);
printf("valor total: %.2f\n", valortotal );
}
int main () {
    float consumo, taxa;

    printf("consumido: ");
    scanf("%f", &consumo);

    printf("taxa: ");
    scanf("%f", &taxa);

    calculovalores(consumo, taxa);
}