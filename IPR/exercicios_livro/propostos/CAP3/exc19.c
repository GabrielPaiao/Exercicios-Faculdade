/*Enunciado: Sabe-se que, para iluminar de maneira correta os cômodos de uma casa, para cada m2,
deve-se usar 18 W  de potência. Faça um programa que receba as duas dimensões de um cômodo (em metros),
calcule e mostre  a sua área (em m2) e a potência de iluminação que deverá ser utilizada.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float d1, d2, area, potencia; /*Declarando 4 variáveis de ponto flutuante, duas recebem input do usuário
    e as outras duas armazenam o valor dos cálculos feitos*/

    printf("Por favor insira as duas dimensoes do comodo (em metros):\nDimensao 1: "); /*Solicitando a entrada de
    duas medidas ao usuário*/
    scanf("%f", &d1); //Armazenando o valor digitado na variável 'd1'
    printf("Dimensao 2: "); //Mesmo processo abaixo
    scanf("%f", &d2);

    area = d1 * d2; //Contas
    potencia = area * 18;

    printf("A area do comodo inserido eh de: %.3fm2\nE a potencia a ser utilizada na iluminacao eh de: %.2fW", area, potencia);
    //Imprimindo os resultados!
}