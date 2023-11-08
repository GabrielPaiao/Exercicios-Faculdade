/*Enunciado: Um armazém trabalha com um determinado número de mercadorias diferentes (um
máximo de 100 itens). Faça um programa que leia e armazene em vetores os preços
de cada mercadoria e a quantidade vendida no mês e, além disso, calcule e imprima:

a. O faturamento mensal do armazém.
b. A mercadoria mais vendida e a menos vendida.
c. O preço da mercadoria menos vendida.
d. Quantas mercadorias têm seu preço mais alto que o preço da mercadoria
menos vendida.*/

#include <stdio.h>

int main()
{
    //VAR
    int n_merch, cont, exp_merch=0, qntd[100], most_sold=0, less_sold=0;
    float faturamento, precos[100];

    //INICIO
    //PERGUNTANDO A QUANTIDADE DE PRODUTOS A SEREM ANALISADOS
    do
    {
        printf("Quantas mercadorias diferentes serao analisadas (max. 100): "); scanf("%d", &n_merch);
        if (n_merch <= 0 || n_merch > 100)
            printf("Numero invalido!\n");
    } while (n_merch <= 0 || n_merch > 100);

    for (cont=0; cont < n_merch; cont++)
    {
        //LEITURA DOS PRODUTOS VENDIDOS
        printf("\nPRODUTO %d:\n", cont);
        do
        {
            printf("Preco: R$"); scanf("%f", &precos[cont]);
            if (precos[cont] < 0)
                printf("ENTRADA INVALIDA!\n");
        } while (precos[cont] < 0);
        do
        {
            printf("Quantidade Vendida: "); scanf("%d", &qntd[cont]);
            if (qntd[cont] <= 0)
                printf("ENTRADA INVALIDA!\n");
        } while (qntd[cont] <= 0);

        //CALCULO FATURAMENTO
        faturamento += precos[cont] * qntd[cont];
    }

    //ANALISANDO MAIS E MENOS VENDIDOS
    for (cont=0; cont < n_merch; cont++)
    {
        if (qntd[cont] > qntd[most_sold])
        {
            most_sold = cont;
        }
        if (qntd[cont] < qntd[less_sold])
        {
            less_sold = cont;
        }
    }

    //QUANTAS MERCADORIAS TEM UM PREÇO MAIS CARO QUE A MENOS VENDIDA
    for (cont=0; cont < n_merch; cont++)
    {
        if (precos[cont] > precos[less_sold])
            exp_merch++;
    }

    //SAIDAS
    printf("\nFaturamento mensal: R$%.2f\n", faturamento);
    printf("A mercadoria mais vendida: PRODUTO %d \n", most_sold);
    printf("A mercadoria menos vendida: PRODUTO %d\n", less_sold);
    printf("Valor mercadoria menos vendida: R$%.2f\n", precos[less_sold]);
    printf("Quantidade de mercadorias que sao mais caras que a mercadoria menos vendida: %d", exp_merch);

    //FIM
    return 0;
}
