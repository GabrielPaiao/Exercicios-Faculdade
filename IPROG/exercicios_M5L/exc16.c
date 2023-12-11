/*Enunciado: Elabore um programa que dado o peso de um boxeador, informe à categoria a qual
pertence, seguindo a tabela abaixo.

Categoria Massa (Kg)
Palha < 50
Pluma < 59
Leve < 75
Pesado < 87
Super Pesado >= 87*/

#include <stdio.h>

int main()
{
    //VAR
    float peso;

    //INICIO
    do
    {
        printf("Insira o peso do lutador(kg): "); scanf("%f", &peso);
        if (peso < 0)
            printf("Entrada invalida!\n");
    } while (peso < 0);

    if (peso <= 50)
        printf("Categoria: PALHA");
    else if (peso > 50 && peso <= 59)
        printf("Categoria: PLUMA");
    else if (peso > 59 && peso <= 75)
        printf("Categoria: LEVE");
    else if (peso > 75 && peso < 87)
        printf("Categoria: PESADO");
    else if (peso >= 87 )
        printf("Categoria: SUPER PESADO");
    else
        printf("Categoria: Inexistente.");
    
    //FIM
    return 0;
}