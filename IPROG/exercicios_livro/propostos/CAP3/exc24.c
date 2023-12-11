/*Enunciado:  Faça um programa que receba a quantidade de dinheiro em reais que uma pessoa que vai viajar possui.
Ela  vai passar por vários países e precisa converter seu dinheiro em dólares, marco alemão e libra esterlina.
Sabe-se que a cotação do dólar é de R$ 1,80; do marco alemão, de R$ 2,00; e da libra esterlina, de R$ 3,57. 
O programa deve fazer as conversões e mostrá-las. */

#include <stdio.h> //Importando a(s) bibliotecas necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float real, dol, marco, libra; //Uma variável float para armazenar o valor dado em cada moeda!

    printf("Quantos reais voce pretende usar na viagem? R$"); //Solicitando input do usuario
    scanf("%f", &real);

    dol = real / 1.80; //Conversões
    marco = real / 2;
    libra = real / 3.57;

    printf("Convesao para as moedas desejadas:\nDolar: U$%.2f\nMarco Alemao: M$%.2f\nLibras Esterlinas: L$%.2f", dol, marco, libra);
    //Imprimindo resultados
}