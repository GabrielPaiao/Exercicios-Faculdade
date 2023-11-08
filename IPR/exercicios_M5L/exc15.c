/*Enunciado: Faça um programa que lê um caracter do teclado e imprima se o caracter é uma letra.
Se for, deve imprimir se a letra em questão é maiúscula ou minúscula. Dica: use os
códigos ASCII das letras para resolver este problema*/

#include <stdio.h>

int main()
{
    //VAR
    char c;

    //INICIO
    printf("Insira UM caractere: "); scanf(" %c", &c); getchar();
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        if (c >= 'A' && c <= 'Z')
            printf("%c - LETRA, MAISCULA", c);
        else
            printf("%c - LETRA, MINUSCULA", c);  
    else
        printf("%c nao eh uma letra.", c);

    //FIM
    return 0;
}