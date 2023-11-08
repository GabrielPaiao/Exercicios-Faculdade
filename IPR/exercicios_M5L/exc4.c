#include <stdio.h>

int main()
{
    float n1, n2;

    printf("Por favor, insira dois numeros:\nPrimeiro numero: ");
    scanf("%f", &n1);
    printf("Segundo numero: ");
    scanf("%f", &n2);

    if (n1 > n2)
        printf("O numero %.0f eh maior que %.0f!", n1, n2);
    else
        printf("O numero %.0f eh menor que %.0f!", n1, n2);

    return 0;
}