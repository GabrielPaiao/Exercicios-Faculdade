/*Enunciado:Faça um programa que calcule a média de um aluno, quaisquer que sejam as suas
duas notas.*/

#include <stdio.h>

int main()
{
    float nota1, nota2, media;
    printf("CALCULANDO A MEDIA ENTRE DUAS NOTAS\nNota da primeira prova: ");
    scanf("%f", &nota1);

    printf("Nota da segunda prova: ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;
    printf("Com as notas %.2f e %.2f, a media desse aluno eh de: %.2f", nota1, nota2, media);
}