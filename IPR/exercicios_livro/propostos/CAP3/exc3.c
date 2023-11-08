/*Enunciado: Faça um programa que receba dois números, calcule e mostre a divisão do primeiro número pelo  segundo.
Sabe-se que o segundo número não pode ser zero, portanto, não é necessário se preocupar com validações.*/

#include <stdio.h> //Importando biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float n1, n2, divisao; //Declarando 3 variáveis, duas para input do usuario e uma para a operação matemática
    
    printf("DIVIDINDO DOIS TERMOS\nPor favor, insira o DIVIDENDO: "); /*Apresentando o programa e solicitando 
    entrada de teclado ao usuário*/
    
    scanf("%f", &n1); //Input associando o valor a variável n1 (dividendo)

    printf("Agora digite o DIVISOR(!=0): "); //Mesmo processo, agora com a variável n2 (divisor)
    scanf("%f", &n2);

    divisao = n1 / n2; //Realizando a divisão

    printf("O resultado da divisao %.2f / %.2f eh: %.2f", n1, n2, divisao); //Imprimindo os resultados!
}