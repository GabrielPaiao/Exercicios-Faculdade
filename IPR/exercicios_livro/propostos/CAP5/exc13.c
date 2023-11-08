/*Enunciado: Faça um programa que receba a idade e o peso de quinze pessoas, e que calcule e mostre as médias
dos  pesos das pessoas da mesma faixa etária. 
As faixas etárias são: de 1 a 10 anos, de 11 a 20 anos, de 21 a  30 anos e de 31 anos para cima.*/

#include <stdio.h>

int main()
{
    //VAR
    int idade, cont, p1=0, p2=0, p3=0, p4=0;
    float peso, soma1=0, soma11=0, soma21=0, soma31=0;

    //INICIO
    for (cont=1;cont <= 15; cont++)
    {
        printf("Insira a idade da pessoa %d: ", cont); scanf("%d", &idade); //Input
        printf("Insira o peso: "); scanf("%f", &peso);
        printf("----------------------------\n"); //Linha bonitinha

        //Analisando Faixa etária
        if (idade > 0 && idade <= 10)
        {
            soma1 += peso;
            p1++;
        }
        else if (idade > 10 && idade <= 20)
        {
            soma11 += peso;
            p2++;
        }
        else if (idade > 20 && idade < 31)
        {
            soma21 += peso;
            p3++;
        }
        else
        {
            soma31 += peso;
            p4++;
        }
    }

    //SAIDAS
    printf("Media do peso das pessoas entre 1-10 anos: %.1fkg\n", soma1 / p1);
    printf("Media do peso das pessoas entre 11-20 anos: %.1fkg\n", soma11 / p2);
    printf("Media do peso das pessoas entre 21-30 anos: %.1fkg\n", soma21 / p3);
    printf("Media do peso das pessoas com mais de 31 anos: %.1fkg", soma31 / p4);

    //FIM
    return 0;
}