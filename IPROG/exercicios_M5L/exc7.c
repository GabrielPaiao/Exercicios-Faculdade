/*Em um Estado, os comerciantes com faturamento anual de até R$100.000,00 pagam
10% de ICMS sobre o faturamento e aqueles com faturamento superior pagam 15%.
Faça um programa que leia o faturamento de um comerciante e imprima o valor do
ICMS devido. Declare como constantes simbólicas o limite e os percentuais de
imposto.*/

#include <stdio.h>

#define LIMITE_FAT 100000.00
#define ALIQUOTA_DEZ 0.10
#define ALIQUOTA_QUINZE 0.15

int main()
{
    float faturamento, icms;

    printf("Qual seu faturamento anual? ");
    scanf("%f", &faturamento);

    if (faturamento <= LIMITE_FAT)
    {
        icms = faturamento * ALIQUOTA_DEZ;
        printf("O valor do seu ICMS eh de: R$%.2f", icms);
    }
    else
    {
        icms = faturamento * ALIQUOTA_QUINZE;
        printf("O valor do seu ICMS eh de: R$%.2f", icms);
    }

    return 0;
}