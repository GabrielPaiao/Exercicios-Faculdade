/*7. Uma empresa decide dar um aumento de 30% aos funcionários com salários inferiores a R$ 500,00.
Faça um  programa que receba o salário do funcionário e mostre o valor do salário reajustado ou uma mensagem,
caso  ele não tenha direito ao aumento.*/

#include <stdio.h>

#define AUMENTO 0.30
#define SAL_MIN 500.00

int main()
{
    float salario, salariot;
    
    printf("Por favor, insira o valor do seu salario: R$");
    scanf("%f", &salario);

    if (salario < SAL_MIN)
    {
        salariot = salario + salario * AUMENTO;
        printf("Seu salario recebeu 30 por cento de aumento, totalizando R$%.2f!", salariot);
    }
    else
        printf("Infelizmente, voce nao tem direito a aumento :c");

    return 0;
}