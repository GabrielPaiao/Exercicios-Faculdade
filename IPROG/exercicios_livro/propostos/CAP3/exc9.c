/*Enunciado: Faça um programa que calcule e mostre a área de um trapézio.
Sabe-se que: A = ((base maior + base menor) * altura)/2*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float area, bmaior, bmenor, altura; /*declarando 4 variáveis de ponto flutuante simples, 3 para input do usuário
    e outra para o cálculo*/

    printf("Calculando a area de um trapezio:\nDigite o valor da base maior: ");/* apresentando o programa e
    solicitando input de teclado*/
    scanf("%f", &bmaior); //armazena o valor digitado na variável 'bmaior'

    printf("Agora, da base menor: ");
    scanf("%f", &bmenor);

    printf("Por ultimo, a altura: ");
    scanf("%f", &altura);

    area = (bmaior + bmenor) * altura / 2; //Realizando o cálculo de área

    printf("A area, seguindo as medidas inseridas, desse trapezio equivale a: %.2f", area); //Imprimindo resultados
}