/*Enunciado:  Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, calcule e mostre:  
a) a idade dessa pessoa em anos;  
b) a idade dessa pessoa em meses;  
c) a idade dessa pessoa em dias;  
d) a idade dessa pessoa em semanas.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    int ano, ano_nasc, idade; /*Declarando 3 variáveis de tipo inteiro, duas para input e uma para os cálculos
    e resultados apresentados*/

    printf("CALCULANDO IDADE\nPor favor, insira o ANO do seu nascimento: "); /*Apresenta a ideia do programa e
    solicita entrada do usuário*/
    scanf("%d", &ano_nasc); //Assimila o valor digitado à variável 'ano_nasc'

    printf("Em qual ano voce esta usando esse programa? "); //Mesmo processo
    scanf("%d", &ano);

    idade = ano - ano_nasc; //Calculando a idade em ANOS

    /*Daqui abaixo segue-se uma sequência de impressões que convertem o valor da variável IDADE para
    cada caso solicitado até o fim do programa*/

    printf("Sua idade em ANOS eh: %d", idade);
    printf("\nSua idade em MESES eh: %d", idade * 12);
    printf("\nSua idade em DIAS eh: %d", idade * 365);
    printf("\nSua idade em SEMANAS eh: %d", idade * 51);
}