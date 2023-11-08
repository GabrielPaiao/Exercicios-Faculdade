/*Enunciado: Faça um programa que receba uma temperatura em Celsius, calcule e mostre essa temperatura
em  Fahrenheit. Sabe-se que F = 180*(C + 32)/100.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float c, f; //Variável celsius recebe input do usuário, e f para a coonversão
    
    printf("CONVERSAO CELSIUS>FAHRENHEIT\nPor favor, insira a temperatura: C"); /*Apresentando o programa e
    solicitando entrada do usuário*/
    scanf("%f", &c); //Armazena o valor digitado na variável 'c'

    f = (c * 9 / 5) + 32; //Conversão

    printf("A temperatura C%.1f, quando convertida para a escala Fahrenheit eh de: F%.1f", c, f);
    //Imprimindo os resultados
}