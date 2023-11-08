/*Enunciado: Um microempresário tem por norma retirar mensalmente 40% do lucro de sua
empresa para os seus gastos pessoais se o lucro ultrapassar R$ 3.000,00 e retirar
apenas R$ 1.000,00 se o lucro for menor que isso. Faça um programa que leia do
teclado o faturamento mensal e o total das despesas para calcular o lucro (lucro =
faturamento - despesas) e imprima quanto o microempresário deve retirar neste mês.
Declare com constantes simbólicas o lucro mínimo, a retirada mínima e o limite da
retirada*/

#include <stdio.h>

#define RETIRADA 0.40
#define MARGEM_LUCRO 3000.00
#define MARGEM_MIN 1000.00

int main()
{
    //VAR
    float fat_mensal, despesas, lucro;

    //INICIO
    do
    {
        printf("Faturamento Mensal: R$"); scanf("%f", &fat_mensal);
        if (fat_mensal < 0)
            printf("Valor invalido!\n");
    } while (fat_mensal < 0);
    printf("Valor total das despesas: R$"); scanf("%f", &despesas);

    lucro = fat_mensal - despesas;

    if (lucro > MARGEM_LUCRO)
        printf("A sugestao de valor a ser retirado eh de: R$%.2f", lucro * RETIRADA);
    else
        printf("A sugestao de valor a ser retirado eh de: R$1000.00");

    //FIM
    return 0;
}