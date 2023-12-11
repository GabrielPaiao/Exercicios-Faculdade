/*Enunciado: Elabore um programa que receba três valores quaisquer e imprima o menor valor dos
três lidos. O que acontece se o seu programa tiver lido dois ou mais números iguais
(Ex.: 1, 1, 3)?*/

#include <stdio.h>

int main()
{
    //VAR
    int numeros[3], cont, maior, menor;

    //INICIO
    printf("Insira um numero: "); scanf("%d", &numeros[0]);
    maior = numeros[0];
    menor = numeros[0];

    for (cont=1; cont <= 2; cont++)
    {
        printf("Insira um numero: "); scanf("%d", &numeros[cont]);
        if (numeros[cont] >= maior)
            maior = numeros[cont];
        else if (numeros[cont] <= menor)
            menor = numeros[cont];
    }
    printf("Maior numero: %d\nMenor numero: %d", maior, menor);

    //FIM
    return 0;
}