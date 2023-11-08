/*Enunciado: Faça um programa que receba o raio, calcule e mostre:  
a) o comprimento de uma esfera; sabe-se que C = 2 * pi R;  
b) a área de uma esfera; sabe-se que A = pi R**2;  
c) o volume de uma esfera; sabe-se que V = ¾ * pi R**3.*/

#include <stdio.h>//Importando a(s) biblioteca(s) necessária(s)
#include <math.h>

int main() //Criando função main(int) para o corpo do programa
{
    float raio, comprimento, area, volume; /*Declarando 4 variáveis de ponto flutuante, uma receberá input do
    usuário e as outras farão as contas necessárias*/

    printf("CALCULANDO AS MEDIDAS DE UMA ESFERA\nPor favor, insira a medida do raio: "); /*Apresentando o 
    programa e solicitando entrada de teclado*/
    scanf("%f", &raio); //Armazenando o valor digitado na variável 'raio'

    comprimento = 2 * 3.14 * raio; //Contas e fórmulas
    area = 3.14 * pow(raio, 2);
    volume = 4 * 3.14 * pow(raio, 3) / 3;

    printf("AS MEDIDAS APRESENTADAS NESSA ESFERA SAO:\nComprimento: %.3f\nArea: %.3f\nVolume: %.3f", comprimento, area, volume);
    //Imprimindo os resultados!
}
