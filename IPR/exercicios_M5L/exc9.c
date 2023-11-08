/*Em um determinado país, deve declarar imposto de renda todo cidadão com renda
anual superior à $ 23.750,00. A renda anual é a renda mensal multiplicada por 13 (12
meses mais a o 13º salário). A alíquota para quem paga é de 20%. Faça um programa
que leia do teclado a renda mensal do usuário e imprima se ele está isento ou se ele
deve fazer a declaração de renda e qual o imposto devido. Declare como constantes
simbólicas o limite para imposto: 23750; o fator de multiplicação: 13; e a alíquota:
20%. */

#include <stdio.h>

#define RENDA 23750.00
#define ALIQUOTA 0.20
#define MESES 13

int main()
{
    //VAR
    float renda_mes, renda_ano;

    //INICIO
    do
    {
        printf("Insira sua renda mensal: R$"); scanf("%f", &renda_mes);
        if (renda_mes < 0)
            printf("Valor invalido!\n");
    } while (renda_mes < 0);

    renda_ano = renda_mes * MESES;
    if (renda_ano > RENDA)
    {
        printf("Voce deve realizar a declaracao do imposto de renda.\n");
        printf("Imposto devido: R$%.2f", renda_ano * ALIQUOTA);
    }
    else
        printf("Voce esta isento! :D");

    //FIM
    return 0;
}
