#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    resultado = 3.14 * pow(2.71, 2 * pow(x,2));
    printf("O resultado eh: %f", resultado);
}