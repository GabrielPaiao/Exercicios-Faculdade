/*Enunciado: Faça um programa que receba o número de lados de um polígono convexo, calcule e mostre o número
de diagonais desse polígono. Sabe-se que ND = N * (N − 3)/2, em que N é o número de lados do polígono.*/

#include <stdio.h> //Importando a(s) bibliotecas necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    int n, nd; /*Declarando 2 variáveis de tipo inteiro, N = numero de lados(input do usuario) e 
    nd = numero de diagonais(a ser calculado)*/

    printf("Por favor, insira o numero de lados do poligono: "); //Solicitando entrada de teclado
    scanf("%d", &n);

    nd = n * (n -3) / 2; //Utilizando a fórmula dada

    printf("Esse poligono possui %d diagionais!", nd); //Imprimindo o resultado!
}