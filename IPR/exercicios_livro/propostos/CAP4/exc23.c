#include <stdio.h>

#define VALOR_MIN 250
#define VALOR_MAX 500

int main()
{
    int codigo, quantidade;
    float valor, desconto;

    printf("Por favor, insira o codigo do produto comprado (1-40): ");
    scanf("%d", &codigo);
    printf("Qual foi a quantidade adquirida? ");
    scanf("%d", &quantidade);

    if (codigo >= 1 && codigo <= 10)
    {
        valor = 10 * quantidade;
        printf("O produto selecionado custa R$10.00 a unidade;\nQuantidade comprada: %d/Total: R$%.2f", quantidade, valor);
        if (valor < VALOR_MIN)
        {
            desconto = valor * 0.05;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 5 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else if (valor >= VALOR_MIN && valor < VALOR_MAX)
        {
            desconto = valor * 0.10;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 10 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else
        {
            desconto = valor * 0.15;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 15 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
    }
    else if (codigo >= 11 && codigo <= 20)
    {
        valor = 15 * quantidade;
        printf("O produto selecionado custa R$15.00 a unidade;\nQuantidade comprada: %d/Total: R$%.2f", quantidade, valor);
        if (valor < VALOR_MIN)
        {
            desconto = valor * 0.05;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 5 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else if (valor >= VALOR_MIN && valor < VALOR_MAX)
        {
            desconto = valor * 0.10;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 10 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else
        {
            desconto = valor * 0.15;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 15 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
    }
    else if (codigo >= 21 && codigo <= 30)
    {
        valor = 20 * quantidade;
        printf("O produto selecionado custa R$20.00 a unidade;\nQuantidade comprada: %d/Total: R$%.2f", quantidade, valor);
        if (valor < VALOR_MIN)
        {
            desconto = valor * 0.05;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 5 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else if (valor >= VALOR_MIN && valor < VALOR_MAX)
        {
            desconto = valor * 0.10;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 10 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else
        {
            desconto = valor * 0.15;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 15 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
    }
    else
    {
        valor = 30 * quantidade;
        printf("O produto selecionado custa R$30.00 a unidade;\nQuantidade comprada: %d/Total: R$%.2f", quantidade, valor);
        if (valor < VALOR_MIN)
        {
            desconto = valor * 0.05;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 5 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else if (valor >= VALOR_MIN && valor < VALOR_MAX)
        {
            desconto = valor * 0.10;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 10 por cento(R$%.2f)! Total A PAGAR: R$%.2f", desconto, valor);
        }
        else
        {
            desconto = valor * 0.15;
            valor -= desconto;
            printf("\nSua compra teve um desconto de 15 por cento(R$%.2f)! Total A PAGAR: R&%.2f", desconto, valor);
        }
    }

    return 0;
}