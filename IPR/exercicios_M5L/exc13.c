/*Enunciado: Faça um programa que leia o ano de nascimento de uma pessoa e imprima se ela é
maior ou menor de idade. Declare o ano atual e o limite de maioridade como
constantes simbólicas.*/

#include <stdio.h>

#define ANO_ATUAL 2023
#define MAIORIDADE 18

int main()
{
    //VAR
    int ano;

    //INICIO
    printf("Insira seu ano de nascimento: "); scanf("%d", &ano);
    if (ANO_ATUAL - ano >= MAIORIDADE)
        printf("Parabens, Voce eh maior de idade! (%d anos de idade)", ANO_ATUAL - ano);
    else
        printf("Voce ainda eh de menor aos %d anos de idade :c", ANO_ATUAL - ano);

    //FIM
    return 0;
}