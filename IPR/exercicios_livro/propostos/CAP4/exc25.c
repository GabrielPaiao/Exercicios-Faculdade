#include <stdio.h>

int main()
{
    float horas_x, horas_f, minutos;

    printf("Horas extras trabalhadas: ");
    scanf("%f", &horas_x);
    printf("Horas faltadas: ");
    scanf("%f", &horas_f);

    minutos = (horas_x - (2 / 3 * horas_f)) * 60;

    if (minutos >= 2400)
        printf("Esse funcionario tem direito a R$500.00 de premio!");
    else if(minutos < 2400 && minutos >=1800)
        printf("Esse funcionario tem direito a R$400.00 de premio!");
    else if(minutos < 1800 && minutos >=1200)
        printf("Esse funcionario tem direito a R$300.00 de premio!");
    else if(minutos < 1200 && minutos >=600)
        printf("Esse funcionario tem direito a R$200.00 de premio!");
    else
        printf("Esse funcionario tem direito a R$100.00 de premio!");

    return 0;
}