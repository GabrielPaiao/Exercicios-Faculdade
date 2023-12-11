/*Um shopping está fazendo uma promoção na qual o cliente que fizer compras de
valor até R$100,00 ganha um cupom para concorrer a um carro e se ele comprar
acima de R$100,00 ganha dois cupons e um vale-desconto no total de 10% da
compra. Faça um programa que leia do teclado o total de compras e imprima se o
cliente tem direito a 1 cupom, ou a 2 cupons e o vale-desconto (nesse caso, imprima
o valor do desconto). Declare como constantes simbólicas o limite e o percentual do
desconto.
*/

#include <stdio.h>

#define DESCONTO 0.10
#define VALOR_LIMITE 100.00

int main()
{
    float gasto, preco;

    printf("Valor total das compras: ");
    scanf("%f", &gasto);

    if (gasto <= VALOR_LIMITE)
        printf("Parabens, voce tem direito a um cupom para concorrer a um carro!");
    else
    {
        preco = gasto - (gasto * DESCONTO);
        printf("Parabens, voce tem direito a dois cupons para concorrer a um carro e ainda ganha 10 por cento de desconto (valor a pagar:  R$%.2f)", preco);
    }

    return 0;
}