/* O preço ao consumidor de um carro novo é a soma do custo de fábrica com a porcentagem do distribuidor
e dos impostos, ambos aplicados ao custo de fábrica. As porcentagens encontram-se na tabela a  seguir.
Faça um programa que receba o custo de fábrica de um carro e mostre o preço ao consumidor.*/

#include <stdio.h>

#define MINIMO 12000.00
#define MAXIMO 25000.00

int main()
{
    float custo;

    printf("Por favor, insira o valor do carro: ");
    scanf("%f", &custo);

    if (custo < MINIMO)
    {
        custo+= custo * 0.05;
        printf("O preco a ser pago eh de: R$%.2f", custo);
    }
    else if (custo >= MINIMO && custo < MAXIMO)
    {
        custo += custo * 0.10 + custo * 0.15;
        printf("O preco a ser pago eh de: R$%.2f", custo);
    }
    else
    {
        custo += custo * 0.15 + custo * 0.20;
        printf("O preco a ser pago eh de: R$%.2f", custo);
    }

    return 0;
}