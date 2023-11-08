/*Enunciado: Faça um programa que receba o peso de uma pessoa, calcule e mostre:
a) o novo peso, se a pessoa engordar 15% sobre o peso digitado;
b) o novo peso, se a pessoa emagrecer 20% sobre o peso digitado.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float peso, pesoG, pesoP; /*Declarando 3 variáveis float, uma para input e duas para armazenar os valores
    das operações a serem feitas*/

    printf("Por favor, digite o seu peso(kg): "); //solicitando entrada de teclado ao usuário
    scanf("%f", &peso); //Armazena o valor digitado na variável 'peso'

    pesoG = peso + (peso / 100 * 15); //Realizando as operações matemáticas
    pesoP = peso - (peso / 100 * 20);

    printf("Esses seria seu peso se:\nEngordasse 15 porcento de seu peso atual: %.2f\nEmagracesse 20 porcento de seu peso atual: %.2f",pesoG, pesoP);
    //Imprimindo os resultados!
}