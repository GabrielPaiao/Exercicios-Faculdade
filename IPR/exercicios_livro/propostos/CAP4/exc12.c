#include <stdio.h>

int main()
{
    float salario;

    printf("Insira o valor do seu salario: R$");
    scanf("%f", &salario);

    if (salario < 350)
    {
        salario += 100 - (salario * 0.07);
        printf("Seu salario recebeu uma gratificacao de R$100,00 e um desconto de 7 por cento.\nSeu salario: R$%.2f", salario);
    }
    else if (salario >= 350 && salario < 600)
    {
        salario += 75 - (salario * 0.07);
        printf("Seu salario recebeu uma gratificacao de R$75,00 e um desconto de 7 por cento.\nSeu salario: R$%.2f", salario);
    }
    else if (salario >= 600 && salario < 900)
    {
        salario += 50 - (salario * 0.07);
        printf("Seu salario recebeu uma gratificacao de R$50,00 e um desconto de 7 por cento.\nSeu salario: R$%.2f", salario);
    }
    else
    {
        salario += 35 - (salario * 0.07);
        printf("Seu salario recebeu uma gratificacao de R$35,00 e um desconto de 7 por cento.\nSeu salario: R$%.2f", salario);
    }

    return 0;
}