//Enunciado: Faça um programa que receba dois números, calcule e mostre a subtração do primeiro número pelo  segundo.

#include <stdio.h> //Importando biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float num1, num2, subtracao; //Criando 3 variáveis de ponto flutuante, duas para input, e uma para a operação

    printf("SUBTRAINDO DOIS NUMEROS\nPor favor, digite um numero: "); /*Apresenta a ideia do programa e solicita
    entrada do usuário*/
    
    scanf("%f", &num1); //Input do usuário, associando o valor digitado á variável num1;

    printf("Agora mais um: "); //Mesma ideia, agora com a variável num2
    scanf("%f", &num2);

    subtracao = num1 - num2; //Realiza a subtração

    printf("O resultado da subtracao de %.1f por %.1f eh: %.2f", num1, num2, subtracao); //Imprime os resultados
}