#include <stdio.h>

#define MAIORIDADE 18

int main()
{
    int idade;

    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);

    if (idade < MAIORIDADE)
        printf("Voce ainda eh de menor!)");
    else
        printf("Parabens, voce eh de maior, ja pode ser preso!");

    return 0;
}