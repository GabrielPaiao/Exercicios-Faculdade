/*Enunciado: Outro aluno fez apenas duas provas, tirando 5.5 e 7.9. Faça um programa que
armazene esses valores em variável, calcule e imprima a nota que ele precisa tirar
para ficar com média 7. */

#include <stdio.h>

int main()
{
    float prova1 = 5.5f, prova2 = 7.9f, media = (prova1 + prova2) / 2;
    if (media < 7)
        {
            float nota = 7 - media;
            printf("Para atingir a media minima de 7 esse aluno precisa tirar uma nota minima de %.2f", nota);
        }
}
