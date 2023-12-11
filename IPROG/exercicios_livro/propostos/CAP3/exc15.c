/*Enunciado: João recebeu seu salário e precisa pagar duas contas atrasadas. Em razão do atraso,
ele deverá pagar  multa de 2% sobre cada conta. Faça um programa que calcule e mostre
quanto restará do salário de  João.

OBS: Suõe-se que devemos solicitar entrada do usuário uma vez que o enunciado não apresentou
valores para o salário ou para as respectivas contas*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float salario, c1, c2, resto; /*Declarando 4 variáveis float, 3 recebem input do usuário e uma é responsável
    pelo cálculo do salário que sobrou*/

    printf("Qual o salario de Joao? R$"); //Solicitando entrada do usuário
    scanf("%f", &salario); //Assimilando o valor digitado à variável 'salario'

    printf("\nQual o valor da primeira conta? R$"); //Mesmo processo com a variável 'c1'
    scanf("%f", &c1);
    c1 = c1 + (c1 / 100 * 2);

    printf("E o da segunda? R$"); //Novamente
    scanf("%f", &c2);
    c2 = c2 + (c2 / 100 * 2);

    resto = salario - (c1 + c2); //Realizando os cálculos

    printf("Restara R$%.2f do salario de Joao apos a quitacao das contas informadas!", resto); //Imprimindo resultados
}