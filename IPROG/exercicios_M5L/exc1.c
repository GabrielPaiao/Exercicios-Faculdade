#include <stdio.h>

int main()
{
    float x;

    printf("Calculando o inverso de um numero\nDigite um numero: ");
    scanf("%f", &x);

    if (x != 0)
    {
        printf("O inverso de %.1f eh: %.1f", x, 1 / x);
    }
    else
    {
        printf("O inverso de 0 nao existe!");
    }
    return 0;
}