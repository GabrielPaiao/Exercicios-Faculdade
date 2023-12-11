#include <stdio.h>
#include <math.h>

int main()
{
    float x, resultado;
    printf("Digite o valor de 'x': \n");
    scanf("%f", &x);

    resultado = pow(x,2) - 9 * x + 7;
    printf("O resultado dessa expressão eh: %.6f", resultado);
}