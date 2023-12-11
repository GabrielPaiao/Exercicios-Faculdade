#include <stdio.h>

int main()
{
    //VAR
    float preco, aumento, imposto;
    int categoria;
    char situacao;

    //Entradas
    printf("Por favor, insira o preco do produto: R$");
    scanf("%f", &preco);
    printf("[1] LIMPEZA - [2] ALIMENTACAO - [3] VESTUARIO\nQual a categoria? ");
    scanf("%d", &categoria);
    printf("Necessita de refrigeracao [R/N]? ");
    scanf(" %c", &situacao); /*É necessário esse espaço antes do %c devido a quebra de linha em linhas passadas
    durante o código*/

    //Analise preço e valor do aumento seguindo a tabela
    if (preco <= 25)
    {
        if (categoria == 1)
        {
            aumento = preco * 0.05;
            preco += aumento;
        }
        else if (categoria == 2)
        {
            aumento = preco * 0.08;
            preco += aumento;
        }
        else
        {
            aumento = preco * 0.10;
            preco += aumento;
        }
    }
    else
    {
        if (categoria == 1)
        {
            aumento = preco * 0.12;
            preco += aumento;
        }
        else if (categoria == 2)
        {
            aumento = preco * 0.15;
            preco += aumento;
        }
        else
        {
            aumento = preco * 0.18;
            preco += aumento;
        }
    }

    //Calculo imposto
    if (categoria == 2 && situacao == 'R')
    {
        imposto = 0.05 * preco;
        preco += imposto;
    }
    else
    {
        imposto = 0.08 * preco;
        preco += imposto;
    }

    //Impressoes
    printf("Valor do aumento: R$%.2f\n", aumento);
    printf("Acrescimo do imposto: R$%.2f\n", imposto);
    printf("Preco total: R$%.2f\n", preco);
    if (preco <= 50)
        printf("CLASSIFICACAO: BARATO");
    else if (preco > 50 && preco < 120)
        printf("CLASSIFICACAO: NORMAL");
    else
        printf("CLASSIFICACAO: CARO");

    //Fim
    return 0;
}