#include <stdio.h>

int main()
{
    float salario;

    printf("Por favor, insira seu salario: R$");
    scanf("%f", &salario);

    if (salario < 300)
    {
        salario += salario * 0.5;
        printf("Seu salario recebeu um ajuste de 50 por cento!\nNovo Salario: R$%.2f", salario);
    }
    else if (salario >= 300 && salario < 500)
    {
        salario += salario * 0.4;
        printf("Seu salario recebeu um ajuste de 40 por cento!\nNovo Salario: R$%.2f", salario);
    }
    else if (salario >= 500 && salario < 700)
    {
        salario += salario * 0.3;
        printf("Seu salario recebeu um ajuste de 30 por cento!\nNovo Salario: R$%.2f", salario);
    }
    else if (salario >= 700 && salario < 800)
    {
        salario += salario * 0.2;
        printf("Seu salario recebeu um ajuste de 20 por cento!\nNovo Salario: R$%.2f", salario);
    }
    else if (salario >= 800 && salario < 1000)
    {
        salario += salario * 0.1;
        printf("Seu salario recebeu um ajuste de 10 por cento!\nNovo Salario: R$%.2f", salario);
    }
    else
    {
        salario += salario * 0.05;
        printf("Seu salario recebeu um ajuste de 5 por cento!\nNovo Salario: R$%.2f", salario);
    }
    
    return 0;
}