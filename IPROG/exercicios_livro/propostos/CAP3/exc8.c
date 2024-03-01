/*Enunciado:Faça um programa que receba o peso de uma pessoa em quilos, calcule e mostre esse peso em gramas.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float pesoq, pesog; /*declarando duas variáveis de ponto flutuante simples, uma para input do usuário
    e outra para a conversão*/

    printf("CONVERSOR: Kg > g\nPor favor, insira seu peso em quilogramas(kg): "); /* apresentando o programa e
    solicitando input de teclado*/
    scanf("%f", &pesoq); //armazena o valor digitado na variável 'pesoq'

    pesog = pesoq * 1000; //a variável 'pesog' recebe o valor da conversão kg > g

    printf("Essa pessoa pesa: %.2fkg/%.2fg", pesoq, pesog); //Imprime os resultados
}