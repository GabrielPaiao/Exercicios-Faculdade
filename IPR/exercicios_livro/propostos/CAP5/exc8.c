/*Enunciado: Faça um programa que receba a idade, o peso, a altura, a cor dos olhos (A — azul; P — preto; V — verde; e
C — castanho) e a cor dos cabelos (P — preto; C — castanho; L — louro; e R — ruivo) de seis pessoas, e que
calcule e mostre:

■■ a quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 kg;
■■ a média das idades das pessoas com altura inferior a 1,50 m;  
■■ a porcentagem de pessoas com olhos azuis entre todas as pessoas analisadas; e 
■■ a quantidade de pessoas ruivas e que não possuem olhos azuis.*/

#include <stdio.h>

int main()
{
    //VAR
    int idade, qnt_idpes=0, cont, cont_med, ruivas=0;
    float altura, peso, media, azul;
    char cor_o, cor_c;

    //INICIO
    printf("ANALISANDO PERFIS\n");
    for (cont = 1; cont <= 6; cont++)
    {
        //INPUTS
        printf("\nPESSOA %d\n", cont);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Peso: ");
        scanf("%f", &peso);
        printf("Altura: "); //Se inserir com '.' no lugar da virgula o programa buga por algum motivo
        scanf("%f", &altura);
        printf("Cor dos Olhos [A | P | V | C]: ");
        scanf(" %c", &cor_o);
        printf("Cor dos Cabelos [P | C | L | R]: ");
        scanf(" %c", &cor_c);
        getchar(); //limpar entrada de dados

        if (idade >= 50 && peso < 60) //Calculo quantidade de pessoas 50+ anos pesando menos de 60kg
            qnt_idpes++;

        if (altura < 1.50) //Calculo media das idades de pessoas com menos de 1.50m de altura
            {
                media += idade;
                cont_med++;
            }

        if (cor_o == 'A' || cor_o == 'a') //Contador pessoas com olho azul
            azul++;

        if (cor_c == 'R' || (cor_c == 'r' && cor_o != 'A' && cor_o != 'a')) //Contador ruivas SEM olhos azuis
            ruivas++;
    }

    media /= cont_med; //Calculo media

    //SAIDAS
    printf("Quantidade de pessoas com 50+ anos pesando menos de 60kg: %d\n", qnt_idpes);
    printf("Média de idade entre pessoas com menos de 1.50m de altura: %.2f\n", media);
    printf("Porcentagem das pessoas com olho azul: %.0f%%\n", 100 / 6 * azul);
    printf("Quantidade de pessoas ruivas sem olhos azuis: %d", ruivas);

    //FIM
    return 0;
}