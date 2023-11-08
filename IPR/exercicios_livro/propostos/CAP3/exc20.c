/*Enunciado: Faça um programa que receba a medida do ângulo formado por uma escada apoiada no chão e
a distância em que a escada está da parede, calcule e mostre a medida da escada para que se possa 
alcançar sua ponta.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)
#include <math.h>

int main() //Criando função main(int) para o corpo do programa
{
    float angulo, c1, h; /*c1 = distancia = cateto1; 'angulo' e 'c1' receberao os valores por input do usuario, h
    é o resultado final(hipotenusa)*/

    printf("Medida do angulo formado pela escala: ");/*Solicitando input do usuário e armazenando valores nas 
    variáveis*/
    scanf("%f", &angulo);
    printf("Distancia para a parede: ");
    scanf("%f", &c1);

    angulo = angulo * 3.14 / 180; //Conversão do angulo para radianos

    h = c1 / cos(angulo); //Calculando a hipotenusa

    printf("A medida da escada afim de alcançar sua ponta eh equivalente a: %.2f", h); //Printando resultados!

}