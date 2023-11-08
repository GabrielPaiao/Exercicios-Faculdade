/*Enunciado: Faça um programa que leia dois vetores de dez posições e faça a multiplicação dos elementos de mesmo
índice, colocando o resultado em um terceiro vetor. Mostre o vetor resultante.*/

#include <stdio.h>

#define TAM_VETOR 10

int main()
{
    //VAR
    int vetor1[TAM_VETOR], vetor2[TAM_VETOR], resultado[TAM_VETOR], cont;

    //INICIO
    printf("VETOR 1\n");
    for (cont=0; cont < TAM_VETOR; cont++)
    {
        printf("Elemento %d: ", cont); scanf("%d", &vetor1[cont]);
    }
    
    printf("\nVETOR 2\n");
    for (cont=0; cont < TAM_VETOR; cont++)
    {
        printf("Elemento %d: ", cont); scanf("%d", &vetor2[cont]);
        resultado[cont] = vetor1[cont] * vetor2[cont]; //Multiplicacao
    }
    
    //SAIDAS
    printf("\nVetor Resultante: \n|");
    for (cont=0; cont < TAM_VETOR; cont++)
        printf("%d |", resultado[cont]);

    //FIM
    return 0;
}