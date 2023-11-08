/*Enunciado: Escreva um programa que leia um número real x, a ordem do polinômio n (no máximo
20), os coeficientes ai e calcule o resultado. Imprima o polinômio lido e o valor
calculado.*/

#include <stdio.h>
#include <math.h>

int main()
{
    //VAR
    float x, a, resultado=0;
    int p[20], n, cont;

    //INICIO
    printf("Insira o valor de X: "); scanf("%f", &x);
    do
    {
        printf("Insira a ordem do polinomio(Max.20): "); scanf("%d", &n);
        if (n < 0 || n > 20)
            printf("ENTRADA INVALIDA!\n");
    } while (n < 0 || n > 20);
    printf("Insira o valor do coficiente a: ");scanf("%f", &a);

    printf("P(%.1f) =", x);
    for (cont=n - 1; cont >= 0; cont--)
    {
        p[cont] = pow(a, cont) * pow(x, cont);
        resultado += p[cont];
        printf(" (%.1f^%d * %.1f^%d) +", a, cont, x, cont);
    }

    printf("\nResultado: %.2f", resultado);
    
    //FIM
    return 0;
}