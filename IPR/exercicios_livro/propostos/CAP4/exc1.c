/*1. Fa√ßa um programa que receba quatro notas de um aluno, calcule e mostre a m√©dia aritm√©tica das notas
e a  mensagem de aprovado ou reprovado, considerando para aprova√ß√£o m√©dia 7.*/

#include <stdio.h> // Importando a biblioteca necess·ria

int main()
{
    float n1, n2, n3, n4, media; // Declarando 4 vari·veis do tipo float

    printf("Nota 1: "); // Iniciando o programa pedindo para o usu·rio digitar as notas do aluno
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);
    printf("Nota 3: ");
    scanf("%f", &n3);
    printf("Nota 4: ");
    scanf("%f", &n4);

    media = (n1+n2+n3+n4) / 4; // Calculando a mÈdia das notas

    if (media < 7) // Estrutura condicional afim de imprimir os resultados
        printf("REPROVADO!");
    else
        printf("APROVADO!");

    return 0;
}
/* Gabriel Pereira Pai„o, Lara Lima Silva */
