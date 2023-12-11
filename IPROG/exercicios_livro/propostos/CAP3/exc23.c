/*Enunciado: Faça um programa que receba a medida de dois ângulos de um triângulo, calcule e mostre
a medida do  terceiro ângulo. Sabe-se que a soma dos ângulos de um triângulo é 180 graus. */

#include <stdio.h> //Importando a(s) bibliotecas necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float a1, a2, a3; //Declarando 3 variáveis que vão receber as medidas dos angulos

    printf("Por favor, insira a medida de dois angulos de um triangulo:\nPrimeiro angulo: "); /* Solicitando
    entrada de teclado do usuário e assimilando os valores inseridos nas variáveis*/
    scanf("%f", &a1);
    printf("Segundo angulo: ");
    scanf("%f", &a2);

    a3 = 180 - (a1 + a2); //Calculo

    printf("O valor do terceiro angulo eh: %.1f", a3); //Imprimindo o resultado
}