//Enunciado: Faça um programa que receba três números, calcule e mostre a multiplicação desses números.

#include <stdio.h> //Importando biblioteca(s) necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float n1, n2, n3, multi; //Criando 4 variáveis de ponto flutuante, 3 para input, e 1 para a operação

    printf("MULTIPLICANDO 3 NUMEROS\nPor favor, digite o primeiro termo: "); /*Apresentando o programa ao usuario e
    solicitando entrada de teclado*/
    
    scanf("%f", &n1); //Input associando o valor digitado à variável n1

    printf("Agora o segundo: "); //Mais uma vez, agora com a variável n2
    scanf("%f", &n2);

    printf("E finalmente, o terceiro: "); //Outra vez, com a variável n3
    scanf("%f", &n3);

    multi = n1 * n2 * n3; //Realizando a operação

    printf("O resultado da multiplicacao dos valores %.1f, %.1f e %.1f eh: %.2f", n1, n2, n3, multi); /*Imprimindo
    os resultados formatados!*/
}