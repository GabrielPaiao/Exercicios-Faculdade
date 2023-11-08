/*Enunciado: Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas. Faça um programa
que receba o salário fixo do funcionário e o valor de suas vendas, calcule e mostre a comissão e seu  salário final.*/

#include <stdio.h>//Importando a(s) biblioteca(s) necessária(s)

int main()//Criando função main(int) para o corpo do programa
{
    float salario, valor_vendas, salarioATT;/*Declarando tres variáveis de ponto flutuante simples para o programa,
    duas recebem entrada do usuario, e uma recebe o valor da variavel 'salario' e soma com 4% da variavel
    'valor_vendas'*/

    printf("Calculando salário + comissao!\nQual seu salario fixo? R$"); /*Apresentando o programa e solicitando 
    entrada de teclado ao usuário**/
    scanf("%f", &salario); // Armazena o valor digitado na variavel 'salario'

    printf("E quanto você vendeu? R$"); //Outro input
    scanf("%f", &valor_vendas); // Armazena o valor digitado na variavel 'valor_vendas'

    salarioATT = salario + (valor_vendas / 100 * 4); //Realiza a operação matematica e armazena o resultado

    printf("O seu salario, apos a comissao de 4 porcento dos valores de venda, eh de: R$%.2f ", salarioATT);
    //Imprime os resultados!
}