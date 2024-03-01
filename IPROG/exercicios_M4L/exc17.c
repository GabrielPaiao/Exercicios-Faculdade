#include <stdio.h>
#include <math.h>

int main()
{
    float raio, resultado;
    printf("Digite o raio da circunferencia: ");
    scanf("%f", &raio);

    resultado = 4 / 3 * 3,14 * pow(raio, 3);
    printf("O resultado eh: %f", resultado);
}