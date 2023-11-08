/*Enunciado: Faca um programa que receba o valor do salario minimo e o valor do salario de um funcionario,
calcule e mostre a quantidade de salarios minimos que esse funcionario ganha.*/

#include <stdio.h> //Importando a biblioteca <stdio.h> para obter as funcoes basicas

int main() //Criando funcao main(int) para o corpo do programa
{
    float sal_min, salario, quantidade; //Declarando 3 variaveis que receberao valores monetarios, 2 por input do usuario

    printf("Qual o valor do salario minimo? R$"); //Solicita entrada de teclado do usuario
    scanf("%f", &sal_min); //Atribui o valor digitado a variavel 'sal-min'

    printf("Qual o salario recebido pelo funcionario? R$"); //Mesmo processo
    scanf("%f", &salario);

    quantidade = salario / sal_min; //Calcula a quantidade de salario(s) minimo(s)
    
    printf("Esse funcionario recebe aproximadamente %.1f", quantidade); //Imprimindo os resultados
}
// Feito por: Gabriel P. Paiao e Lara Lima Silva;
