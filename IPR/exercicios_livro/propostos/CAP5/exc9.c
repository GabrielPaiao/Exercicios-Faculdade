/*Enunciado: Faça um programa que receba dez idades, pesos e alturas, calcule e mostre:  
■■ a média das idades das dez pessoas;  
■■ a quantidade de pessoas com peso superior a 90 kg e altura inferior a 1,50 metro; e 
■■ a porcentagem de pessoas com idade entre 10 e 30 anos entre as pessoas que medem mais de 1,90 m.*/

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //VAR
    int idade, contador, contador1=0;
    float peso, altura, media_id, contador2=0;

    //INICIO
    printf("ANALISANDO PERFIS\n");
    for (contador = 1; contador <= 10; contador++)
    {
        //Entradas
        printf("\nPESSOA %d\n", contador);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Peso: ");
        scanf("%f", &peso);
        printf("Altura: ");
        scanf("%f", &altura);

        //Somando as idades digitadas para o calculo da media
        media_id += idade;

        //Contador pessoas +90kg e altura < 1,50
        if (peso >= 90 && altura < 1.50)
            contador1++;

        //Contando o numero de pessoas com mais de 1,90m de altura e entre 10-30 anos
        if ((idade >= 10 && idade <= 30) && altura > 1.90)
            contador2++;
    }

    media_id /= 10; //Calculando a media das idades

    //SAÍDAS
    printf("\nA media das idades inseridas é de: %.2f\n", media_id);
    printf("A quantidade de pessoas com 90+kg e altura inferior a 1.50m é de: %d\n", contador1);
    printf("A porcentagem de pessoas entre 10-30anos com 1.90+m de altura é de: %.0f%%", 100 / 10 * contador2);

    //FIM
    return 0;
}