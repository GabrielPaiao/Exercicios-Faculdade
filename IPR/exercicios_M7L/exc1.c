/*Enunciado: Faça um programa para calcular a média de um conjunto de 15 valores dados pelo
usuário e armazenados em um vetor. Ao final, imprima a média e todos os valores
digitados que ficaram abaixo da média.*/

#include <stdio.h>

#define TAMANHO 15

int main()
{
    //VAR
    int cont, cont2;
    float valores[TAMANHO], media;

    //INICIO
    for (cont=0; cont < TAMANHO; cont++)
    {
        printf("Insira o %d termo: ", cont); scanf("%f", &valores[cont]);
        media += valores[cont];
    }
    media /= TAMANHO;

    printf("INSERIDOS abaixo da media: ");
    for (cont2=0; cont2 < TAMANHO; cont2++)
    {
        if (valores[cont2] < media)
            printf("%.1f; ", valores[cont2]);
    }
    //FIM
    return 0;
}