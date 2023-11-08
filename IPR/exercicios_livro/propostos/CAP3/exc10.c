/*Enunciado: Faça um programa que calcule e mostre a área de um quadrado.
Sabe-se que: A = lado * lado.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float area, lado; //Declarando duas variáveis float, uma recebe o input do usuário e outra para a operação mat.

    printf("Calculando a area do quadrado\nDigite o valor do(s) lado(s): "); /*Apresentando o programa e
    solicitando entrada de teclado do usuário*/
    scanf("%f", &lado); //Atribuindo o valor inserido à variável 'lado'

    area = lado * lado; //Calculando....

    printf("A area do quadrado eh: %.2f", area); //Imprimindo os resultados!
}