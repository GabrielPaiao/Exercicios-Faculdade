/*Enunciado: Faça um programa que leia um vetor com dez posições para números inteiros e mostre somente os números
positivos.*/
#include <stdio.h>

#define TAM_VETOR 10

int main()
{
    //VAR
    int vetor[TAM_VETOR], cont;

    //INICIO
    for (cont=0; cont < TAM_VETOR; cont++)
    {
        printf("Insira o termo %d: ", cont); scanf("%d", &vetor[cont]);
    }
    
    //SAIDA
    printf("\nNumeros positivos inseridos: \n");
    for (cont=0; cont < TAM_VETOR; cont++)
    {
        if (vetor[cont] >= 0)
            printf("| %d ", vetor[cont]);
    }
    //FIM
    return 0;
}