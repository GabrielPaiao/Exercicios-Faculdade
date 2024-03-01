#include <stdio.h>

#define PRECO_MIN 50.00
#define PRECO_MAX 100.00

int main()
{
    float preco;

    printf("Digite o preco do seu produto: R$");
    scanf("%f", &preco);

    if (preco < PRECO_MIN)
        preco += preco * 0.05;
    else if (preco >= PRECO_MIN && preco < PRECO_MAX)
        preco += preco * 0.10;
    else
        preco += preco * 0.15;

    if (preco < 80)
        printf("O produto de valor R$%.2f esta classificado como barato!", preco);
    else if (preco >= 80 && preco < 120)
        printf("O produto de valor R$%.2f esta classificado como normal!", preco);
    else if (preco >= 120 && preco < 200)
        printf("O produto de valor R$%.2f esta classificado como caro!", preco);
    else
        printf("O produto de valor R$%.2f esta classificado como muito caro!", preco);

    return 0;
}