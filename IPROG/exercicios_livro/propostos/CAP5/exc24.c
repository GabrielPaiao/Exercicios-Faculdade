/*Enunciado: Faça um programa que receba um conjunto de valores inteiros e positivos, calcule e mostre o maior
e o  menor valor do conjunto. Considere que:

■■ para encerrar a entrada de dados, deve ser digitado o valor zero;  
■■ para valores negativos, deve ser enviada uma mensagem;  
■■ os valores negativos ou iguais a zero não entrarão nos cálculos.*/

#include <stdio.h>

int main()
{
    //VAR
    int valor, maior, menor;

    //INICIO FORA DO LOOP
    printf("Insira um numero (0 para encerrar): "); scanf("%d", &valor);

    while (valor < 0 && valor != 0) //Enquanto o primeiro input for negativo
    {
        printf("Insira outro numero (negativos nao valem): "); 
        scanf("%d", &valor);
    }

    if (valor == 0) //Se o usuario colocar 0 de primeira
        printf("Programa encerrado sem um valor valido inserido :c");

    else //Se ele colocar um numero valido para o programa;
    {
        maior = valor; //'maior' e 'menor' recebem o valor do primeiro input como padrão
        menor = valor;
        do
        {
            printf("Insira um numero (0 para encerrar): "); scanf("%d", &valor);
            if (valor < 0)
            {
                printf("Insira outro numero (negativos nao valem): "); scanf("%d", &valor);
            }
            else if (valor > maior)
            {
                maior = valor;
            }
            else if (valor < menor && valor > 0)
                menor = valor;
        } while (valor != 0);

        //SAIDA FINAL
        printf("O maior valor inserido foi: %d\nE o menor: %d", maior, menor);
    }

    //FIM
    return 0;
}