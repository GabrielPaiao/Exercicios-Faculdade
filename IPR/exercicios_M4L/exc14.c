/*Enunciado:Escreva um programa que, dados a distância entre duas cidades, o preço do
combustível e o consumo médio do automóvel, calcule o custo para fazer a viagem
entre essas duas cidades.*/

#include <stdio.h>

int main()
{
    float distancia, consumo, preco, gasto;
    printf("Calculando o custo para uma viagem entre duas cidades.\nQual a distancia entre as duas cidades(Km)? ");
    scanf("%f", &distancia);
    
    printf("\nQual o preco da gasolina hoje(l)? R$");
    scanf("%f", &preco);

    printf("\nE o consumo medio do automovel(Km/l)? ");
    scanf("%f", &consumo);

    gasto = (distancia / consumo) * preco;
    printf("Uma viagem dessas te custaria R$%.2f em gasolina!", gasto);
}