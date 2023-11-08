/*Enunciado: Faça um programa que receba uma hora (uma variável para hora e outra para minutos), calcule e  mostre:  
a) a hora digitada convertida em minutos;  
b) o total dos minutos, ou seja, os minutos digitados mais a conversão anterior;  
c) o total dos minutos convertidos em segundos.*/

#include <stdio.h> //Importando a(s) bibliotecas necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    int h, min, seg; //Declarando variáveis para horas, minutos e segundos.

    printf("Por favor, insira (um a um), as horas e os minutos:\nHora: "); //Solicitando entrada de usuário
    scanf("%d", &h);
    printf("Minutos: ");
    scanf("%d", &min);

    h *= 60; //CÁLCULOS: hora > minutos / Hora em minutos + minutos / Transformando tudo em segundos.
    min += h;
    seg = min * 60;

    printf("\nHora > Minutos: %d\nTotal de Minutos: %d\nSegundos: %d", h, min, seg);
    //Imprimindo os resultados!
}