#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    resultado = pow(x - 5, 1.0/3.0);
    printf("O resultado eh: %.6f", resultado);
}