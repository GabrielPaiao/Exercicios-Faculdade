/*Enunciado: Faça um programa que calcule e mostre a tabuada de um número digitado pelo usuário.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    int x,contador, conta; /*Declarando variáveis de tipo inteiro, uma receba entrada do usuário, uma para controle
    da estrutura de repetição 'for', e outra para realizar os cálculos da tabuada*/

    printf("Tabuada do: ");
    scanf("%d", &x); // Recebe um valor inteiro digitado pelo usuário, definido a tabuada a ser feita

    for (contador = 1; contador < 11; contador++) //Estruta de repetição, mostrará uma tabuada até o 10
    {
        conta = x * contador; //Operação
        printf("%d x %d = %d\n", x, contador, conta);//Imprimindo as contas
    } 
}