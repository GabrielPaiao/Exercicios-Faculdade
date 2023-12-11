/*Enunciado: Faça um programa que receba a idade, a altura e o peso de cinco pessoas, calcule e mostre:  
■■ a quantidade de pessoas com idade superior a 50 anos;  
■■ a média das alturas das pessoas com idade entre 10 e 20 anos;  
■■ a porcentagem de pessoas com peso inferior a 40 kg entre todas as pessoas analisadas.*/

#include <stdio.h>

int main()
{
    //VAR
    int cont, cont50=0, cont_alt=0, idade;
    float peso, altura, media_alt=0, cont_p40=0;

    //INICIO
    for (cont=1; cont <= 5; cont++)
    {
        printf("\nPESSOA %d:\nIdade: ", cont); scanf("%d", &idade);
        printf("Altura: "); scanf("%f", &altura);
        printf("Peso: "); scanf("%f", &peso);

        if (idade > 50)
            cont50++;
        else if (idade >=10 && idade <=20)
        {
            media_alt += altura;
            cont_alt++;
        }

        if (peso < 40)
            cont_p40++;
    }
    media_alt /= cont_alt; //Media da altura

    //SAIDAS
    printf("\nQuantidade de pessoas com idade maior que 50 anos: %d\n", cont50);
    printf("Media da altura das pessoas com idade entre 10-20 anos: %.1f\n", media_alt);
    printf("Porcentagem de pessoas com peso inferior a 40kg entre as analisadas: %.0f%%", (cont_p40 / 5) *100);


    //FIM
    return 0;
}