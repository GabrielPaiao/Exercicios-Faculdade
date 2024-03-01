/*Enunciado: Faça um programa que preencha um vetor com dez números reais, calcule e mostre a quantidade de números
negativos e a soma dos números positivos desse vetor.*/

#include <stdio.h>

#define TAMANHO_N 9

int main()
{
    //VAR
    float n[TAMANHO_N], num, soma;
    int cont, cont_n=0;

    //INICIO
    for (cont = 0; cont < TAMANHO_N; cont++)
    {
        printf("Insira o %d numero: ", cont); scanf("%f", &num);
        n[cont] = num;

        if (num < 0)
         cont_n++;
        else
            soma += num;
    }

    //SAIDAS
    printf("Quantidade de negativos: %d\n", cont_n);
    printf("Soma dos positivos: %.2f", soma);

    //FIM
    return 0; 
}