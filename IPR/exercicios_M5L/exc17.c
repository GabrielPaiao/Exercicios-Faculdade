/*Enunciado: Uma empresa decidiu dar um bônus de Natal aos seus funcionários, cujo valor é
definido do seguinte modo:

a. Funcionários do sexo masculino com tempo de casa superior à 15 anos terão
direito à um bônus de 15% do seu salário.

b. Funcionárias com tempo de casa superior à 10 anos terão direito a um bônus
de 25% do seu salário.

c. Demais funcionários receberão um bônus de R$ 500,00

Elabore um programa que leia os dados necessários e calcule o bônus à que tem
direito o empregado.*/

#include <stdio.h>

int main()
{
    //VAR
    int tempo;
    char sexo;
    float salario;

    //INICIO
    //ENTRADAS
    do
    {
        printf("Qual o seu tempo de casa(anos)? "); scanf("%d", &tempo);
        if (tempo < 0 || tempo > 70)
            printf("Entrada invalida!\n");
    } while (tempo < 0 || tempo > 70);

    do
    {
        printf("Insira seu salario: R$"); scanf("%f", &salario);
        if (salario < 0 || salario > 100000)
            printf("Entrada invalida!\n");
    } while (salario < 0 || salario > 100000);

    do
    {
        printf("Qual seu sexo[F/M]? "); scanf(" %c", &sexo); getchar();
        if ((sexo != 'M' && sexo != 'm') && (sexo != 'F' && sexo != 'f'))
            printf("Entrada invalida!\n");
    } while ((sexo != 'M' && sexo != 'm') && (sexo != 'F' && sexo != 'f'));

    //SITUACOES
    if ((sexo == 'm' || sexo == 'M') && tempo > 15)
        printf("Voce tem dinheiro a um bonus de 15%% do seu salario!\nBonus: R$%.2f", salario * 0.15);
    else if ((sexo == 'f' || sexo == 'F') && tempo > 10)
        printf("Voce tem dinheiro a um bonus de 25%% do seu salario!\nBonus: R$%.2f", salario * 0.25);
    else
        printf("Voce tem dinheiro a um bonus de R$500 no seu salario!");

    //FIM
    return 0;
}