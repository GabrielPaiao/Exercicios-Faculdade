/*Escreva um programa para calcular o consumo médio de um automóvel (km/l) dados
a distância percorrida e o volume de combustível consumido.*/

#include <stdio.h>

int main()
{
    float distancia, consumo, consumoM;
    printf("Calculando o consumo medio do seu veiculo\nQual a distancia percorrida(km)? ");
    scanf("%f", &distancia);

    printf("E quanto combustivel foi consumido(l)? \n");
    scanf("%f", &consumo);

    consumoM = distancia / consumo;
    printf("O consumo medio de seu veiculo eh de: %.2fKm/l!", consumoM);
}