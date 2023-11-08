/*Enunciado: Faça um programa que calcule e mostre a área de um losango. 
Sabe-se que: A = (diagonal maior * diagonal menor)/2.*/

#include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float dmaior, dmenor, area; //Declarando 3 variaveis float, 2 para input e uma para a operação

    printf("CALCULANDO A AREA DO LOSANGO\nInsira a medida da diagonal maior: "); /*Apresentando o programa e
    solicitando entrada de teclado do usuário*/
    scanf("%f", &dmaior); //Atribuindo o valor inserido à variável 'lado'

    printf("Agora, insira a medida da diagonal menor: "); //Mesmo processo
    scanf("%f", &dmenor);

    area = (dmaior * dmenor) / 2; //Realizando a operação

    printf("A area desse losango eh: %.2f", area); //Imprimindo os resultados
}