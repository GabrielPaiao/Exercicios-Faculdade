/*Enunciado: Faça um programa que receba duas notas, calcule e mostre a média ponderada dessas notas,
considerando peso 2 para a primeira e peso 3 para a segunda. */

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float n1, n2, mediaP; //Declarando 3 variáveis float, 2 para input do usuário e uma para operação
    
    printf("CALCULANDO MEDIA PONDERADA\nDigite a primeira nota: "); /*Apresentando o programa e solicitando 
    entrada de teclado ao usuário*/
    
    scanf("%f", &n1); //Input associando o valor a variável n1

    printf("\nDigite a segunda nota: "); //O processo se repete com a variável n2
    scanf("%f", &n2);

    mediaP = n1 * 2 + n2 * 3 / 2 + 3; //Calculando a média ponderada!
    
    printf("A media ponderada das notas inseridas eh: %.2f", mediaP); //Imprimindo os resultados!
}