/*Enunciado: Faça um programa que calcule a nota que um aluno deve tirar na terceira prova para
obter média 7, quaisquer que sejam as notas das duas primeiras provas.*/

#include <stdio.h>

int main()
{
    float prova1, prova2, media, nota;
    printf("CALCULANDO A NOTA NECESSARIA PARA APROVACAO\nDigite a nota da primeira prova: ");
    scanf("%f", &prova1);

    printf("Agora, digite a nota da segunda prova: ");
    scanf("%f", &prova2);

    media = (prova1 + prova2) / 2;
    if (media < 7)
        {
            nota = 7 - media;
             printf("Para alcancar a media minima(7), o aluno precisa obter uma nota de %.2f na terceira prova.", nota);
        }
    else
        {
            printf("Parabens, a media %.2f ja eh o suficiente para ser aprovado(a)!", media);
        }
}