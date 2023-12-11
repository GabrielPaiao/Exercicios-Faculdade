/*Faça um programa para calcular e mostrar o salário reajustado de um funcionário. O percentual de aumento
encontra-se na tabela a seguir.*/

#include <stdio.h>

#define LIMITE 300.00

int main()
{
    float salario, salariot;
    
    printf("Por favor, insira seu salario: R$");
    scanf("%f", &salario);

    if (salario < LIMITE)
    {
        salariot = salario + salario * 0.35;
        printf("O seu salario sofreu um reajuste de 35 por cento, aumentando para R$%.2f", salariot);
    }
    else
    {
        salariot = salario + salario * 0.15;
        printf("O seu salario sofreu um reajuste de 15 por cento, aumentando para R$%.2f", salariot);
    }
    
    return 0;
}