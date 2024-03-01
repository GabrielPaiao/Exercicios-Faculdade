/*Enunciado: Faça um programa que calcule o valor total da venda de uma mercadoria, qualquer
que seja o número de unidades vendidas e o valor da mercadoria*/

#include <stdio.h>

int main()
{
    int vendidas;
    float valor;

    printf("CALCULANDO LUCRO DA VENDA DE MERCADORIAS\nDigite o numero de mercadoria(s) vendida(s): ");
    scanf("%d", &vendidas);

    printf("Digite o valor unitario: R$");
    scanf("%f", &valor);

    float total = vendidas * valor;
    printf("Com %d mercadorias vendidas no valor de R$%.2f, a renda total foi de: R$%.2f", vendidas, valor, total);
}