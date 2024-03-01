/*Enunciado: Uma equação do segundo grau é descrita genericamente por ax^2 + bx + c = 0.
Escrever um programa que leia os valores de a, b e c e resolva a equação do segundo
grau correspondente, imprimindo as raízes reais quando existirem ou avisando que
não existem raízes.*/

#include <stdio.h>
#include <math.h>

int main()
{
    //VAR
    float a, b, c, delta, x1, x2;

    //INICIO
    printf("Insira o valor de a: "); scanf("%f", &a);
    printf("Insira o valor de b: "); scanf("%f", &b);
    printf("Insira o valor de c: "); scanf("%f", &c);

    //VALOR DE DELTA
    delta = b * b - 4 * a * c;

    if (delta < 0)
        printf("Nao existem raizes reais.\n");
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        printf("Existe uma raiz real: %.3f", x1);
    }
    else //BASKHARA
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Raizes reais: {%.3f ; %.3f}", x1, x2);
    }

    //FIM
    return 0;
}