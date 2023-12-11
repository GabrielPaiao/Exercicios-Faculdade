#include <stdio.h>

int main()
{
    float salario;
    
    printf("Por favor, insira seu salario: R$");
    scanf("%f", &salario);
    
    if (salario < 300)
    {
        salario += salario * 0.15;
        printf("O seu salario sofreu um reajuste de 15 por cento: R$%.2f", salario);
    }
    else if (salario >= 300 && salario < 600)
    {
        salario += salario * 0.10;
        printf("O seu salario sofreu um reajuste de 10 por cento: R$%.2f", salario);
    }
    else if (salario >=600 && salario < 900)
    {
        salario += salario * 0.05;
        printf("O seu salario sofreu um reajuste de 5 por cento: R$%.2f", salario);
    }
    else
    {
        printf("Voce nao esta elegivel a um aumento :c");
    }

    return 0;
}