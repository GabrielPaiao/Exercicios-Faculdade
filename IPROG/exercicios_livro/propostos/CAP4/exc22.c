#include <stdio.h>

#define IDADE_MIN 20
#define IDADE_MAX 50

int main()
{
    float peso;
    int idade;

    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);
    printf("Agora insira seu peso(kg): ");
    scanf("%f", &peso);

    if (idade < IDADE_MIN && peso < 60)
        printf("Grupo de Risco: 9");
    else if (idade < IDADE_MIN && peso >= 60 && peso < 90)
        printf("Grupo de Risco: 8");
    else if (idade < IDADE_MIN && peso >= 90)
        printf("Grupo de Risco: 7");
    else if (idade >= IDADE_MIN && idade < IDADE_MAX && peso < 60)
        printf("Grupo de Risco: 6");
    else if (idade >= IDADE_MIN && idade < IDADE_MAX && peso >= 60 && peso < 90)
        printf("Grupo de Risco: 5");
    else if (idade >= IDADE_MIN && idade < IDADE_MAX && peso >= 90)
        printf("Grupo de Risco: 4");
    else if (idade >= IDADE_MAX && peso < 60)
        printf("Grupo de Risco: 3");
    else if (idade >= IDADE_MAX && peso >= 60 && peso < 90)
        printf("Grupo de Risco: 2");
    else
        printf("Grupo de Risco: 1");

    return 0;
}