/*Enunciado: Faça um programa que receba o valor de um carro e mostre uma tabela com os seguintes dados:
preço  final, quantidade de parcelas e valor da parcela. Considere o seguinte:  
■■ o preço final para compra à vista tem desconto de 20%; 
■■ os percentuais de acréscimo encontram-se na tabela a seguir.

QNT. PARCELAS / % ACRESCIMO
6                3%
12               6%
18               9%
24              12%
30              15%
36              18%
42              21%
48              24%
54              27%
60              30%*/

#include <stdio.h>
#include <locale.h>

int main()
{
    //VAR
    float valor;
    int escolha, contador=6;

    //INICIO
    setlocale(LC_ALL, "Portuguese");

    printf("Insira o valor do carro: R$"); scanf("%f", &valor); //INPUT valor do carro

    //MENU DE ESCOLHA (A VISTA - PARCELADO)
    printf("FORMA DE PAGAMENTO:\n[1] A VISTA\n[2]PARCELADO");

    do
    {
        printf("\nSua escolha: "); scanf("%d", &escolha);
        if (escolha < 1 || escolha > 2)
            printf("Por favor, insira uma opção válida.");
    }while (escolha < 1 || escolha > 2);

    //ESCOLHEU A VISTA
    if (escolha == 1)
        printf("Valor a ser pago: R$%.2f", valor - valor * 0.20); //desconto 20%

    //ESCOLHEU PARCELADO
    else
    {
       //mostrar preço final, qnt. parcelas e valor das parcelas em uma tabela
       printf("VALOR FINAL | QNT. PARCELAS | VALOR PARCELAS\n");
       while (contador <= 60)
       {
        printf("R$%.2f  | %d            | R$%.2f\n", valor, contador, valor / contador);
        contador += 6;
       }
    }

    //FIM
    return 0;
}