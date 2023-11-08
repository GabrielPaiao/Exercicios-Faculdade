#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de x: ");
    scanf("%f", &x);

    resultado = cos(x) + tan(x);
    printf("O resultado da soma do cosseno e tangente de x eh: %.6f", resultado);
}