/*. O índice de massa corporal (IMC) é uma medida que indica se a pessoa está dentro
de uma faixa de peso aceitável, e é calculado da seguinte forma: IMC = PESO / ALTURA * ALTURA. Para 
ser considerada normal, uma pessoa deve ter o IMC entre 20 e 25. Faça um programa
que leia a altura de uma pessoa e informe a faixa de peso ideal dela.*/

#include <stdio.h>

int main()
{
    float pesoIDealMin, PesoIdealMax, altura;
    printf("Calcundo seu IMC\nPor favor, insira sua altura(cm/m): ");
    scanf("%f", &altura);

    pesoIDealMin = 20 * (altura * altura);
    PesoIdealMax = 25 * (altura * altura);

    printf("Para obter um IMC entre 20/25, voce deve pesar entre %.2f-%.2fKg!", pesoIDealMin, PesoIdealMax);
}