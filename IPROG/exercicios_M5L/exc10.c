/*Enunciado: Em uma loja de eletroeletrônicos, um vendedor que consiga vender mais de R$
3.000,00 por mês recebe como comissão 5% do valor vendido. Abaixo disso, ele não
recebe nenhuma comissão. Faça um programa que leia do teclado o total de vendas
mensais de um vendedor e imprima se ele tem direito a comissão e, se tiver, de
quanto.*/

#include <stdio.h>

#define META 3000.00
#define COMISSAO 0.05

int main()
{
    //VAR
    float total_vendas;

    //INICIO
    do
    {
        printf("Total vendido: R$"); scanf("%f", &total_vendas);
        if (total_vendas < 0)
            printf("Valor invalido! :C\n");
    } while (total_vendas < 0);

    if (total_vendas >= META)
        printf("Voce recebeu uma comissao de 5%%!! Valor da comissao: R$%.2f", total_vendas * COMISSAO);
    else
        printf("Voce nao possui direito a comissao...");
    

    //FIM
    return 0;    
}