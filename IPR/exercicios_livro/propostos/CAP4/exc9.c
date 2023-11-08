/*Um banco concederá um crédito especial aos seus clientes, de acordo com o saldo médio no último ano.
Faça  um programa que receba o saldo médio de um cliente e calcule o valor do crédito, 
de acordo com a tabela a  seguir. Mostre o saldo médio e o valor do crédito.*/

#include <stdio.h>

int main()
{
    float saldom, credito;

    printf("Por favor, insira seu saldo medio do ano passado: ");
    scanf("%f", &saldom);

    if (saldom <200)
    {
        credito = saldom * 0.10;
        printf("Voce tem direito a um credito de R$%.2f", credito);
    }
    else if (saldom >=200 && saldom< 300)
    {
        credito = saldom * 0.20;
        printf("Voce tem direito a um credito de R$%.2f", credito);
    }
    else if (saldom >=300 && saldom < 400)
    {
        credito = saldom * 0.25;
        printf("Voce tem direito a um credito de R$%.2f", credito);
    }
    else
    {
        credito = saldom * 0.30;
        printf("Voce tem direito a um credito de R$%.2f", credito);
    }

    return 0;
}