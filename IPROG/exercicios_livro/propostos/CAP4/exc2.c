/*Faça um programa que receba duas notas, calcule e mostre a média aritmética e a mensagem que se encontra
na tabela a seguir*/

#include <stdio.h>

#define REPROVADO 3.0
#define APROVADO 7.0

int main()
{
    float n1, n2, media;

    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);

    media = (n1+n2) / 2;

    if (media < REPROVADO)
        printf("Reprovado!");
    else if (media >= REPROVADO && media < APROVADO)
        printf("Exame!");
    else
        printf("Aprovado!");

    return 0;
}