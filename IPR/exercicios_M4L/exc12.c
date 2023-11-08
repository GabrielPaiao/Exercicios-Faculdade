/*Enunciado: Escreva um programa que calcule a idade de uma pessoa, dado o ano de seu nascimento.*/

#include <stdio.h>

int main()
{
    int ano, idade;
    printf("Digite seu ano de nascimento: ");
    scanf("%d", &ano);

    idade = 2023 - ano;
    printf("Voce tem aproximadamente %d anos!", idade);
}
