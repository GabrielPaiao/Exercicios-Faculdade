#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    resultado = pow(8 * x - 3, 1.0/5.0);
    printf("O Resultado eh: %.6f", resultado);
}