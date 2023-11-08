#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    resultado = sin(2 * 3.14 - x);
    printf("O Resultado é: %.6f", resultado);
}