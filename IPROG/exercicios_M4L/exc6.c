/**Enunciado: Um aluno fez três provas, nas quais tirou 7.8, 5.5 e 6.7. Faça um programa que
armazene esses valores em variáveis, calcule e imprima a sua média.*/

#include <stdio.h>

int main()
{
    float prova1 = 7.8f, prova2 = 5.5f, prova3 = 6.7f, media = (prova1 + prova2 + prova3) / 3;
    printf("O aluno obteve apos a realizacao de 3 provas a media: %.2f", media);
}