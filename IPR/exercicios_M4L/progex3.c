/*Enunciado:Fazer um programa que calcule a média entre dois números quaisquer.*/

#include <stdio.h>

int main()
{
    float n1, n2, media;
    printf("CALCULANDO MEDIA DE DOIS NUMEROS\nDigite o primeiro numero: ");
    scanf("%f", &n1);

    printf("\nDigite um segundo numero: ");
    scanf("%f", &n2);

    media = (n1 + n2) / 2;
    printf("\nA media entre os numeros %.2f e %.2f eh: %.2f", n1, n2, media);
}