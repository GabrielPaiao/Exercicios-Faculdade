/* Faça um programa que receba dois números e mostre o menor.*/

#include <stdio.h>

int main()
{
    float n1, n2;

    printf("Insira um numero: ");
    scanf("%f", &n1);
    printf("Insira outro numero: ");
    scanf("%f", &n2);

    if (n1<n2)
        printf("%.1f eh menor que %.1f!", n1, n2);
    else
        printf("%.1f eh menor que %.1f!", n2, n1);

    return 0;
}