/*Enunciado: Faça um programa que receba o valor dos catetos de um triângulo, calcule e mostre o valor da hipotenusa.
LEMBRANDO: hipotenusa = raíz da soma dos quadrados dos catetos*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)
#include <math.h>

int main() //Criando função main(int) para o corpo do programa
{
    float c1, c2, hip; /*Duas variáveis para os catetos recebem input do usuário, e uma para a hipotenusa
    a ser calculada*/

    printf("CALCULANDO A HIPOTENUSA\nQual o valor do primeiro cateto? "); /*Apresentando o programa ao usuário
    e solicitando entrada de teclada*/
    scanf("%f", &c1); //Assimila o valor digitado à variável 'c1' (do primeiro cateto)

    printf("\nQual o valor do segundo cateto? "); //Mesmo processo
    scanf("%f", &c2);

    hip = sqrt(sqr(c1)+sqr(c2)); //Calculando a hipotenusa com comandos da biblioteca 'math'

    printf("A hipotenusa eh: %f", hip); //Imprimindo o resultado!
}

//CURIOSIDADE: Catetos são uma espécie de porcos do mato!!!!