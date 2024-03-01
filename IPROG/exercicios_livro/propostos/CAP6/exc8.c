/*Enunciado: Faça um programa que preencha um vetor com os nomes de sete alunos e carregue outro vetor com a média
final desses alunos. Calcule e mostre:  
■■ o nome do aluno com maior média (desconsiderar empates);  
■■ para cada aluno não aprovado, isto é, com média menor que 7, mostrar quanto esse aluno precisa tirar na prova de
exame final para ser aprovado. Considerar que a média para aprovação no exame é 5.*/

#include <stdio.h>

#define TAMANHO_VET 7 //Um a mais do que o 'necessario' por causa do valor 0 no inicio do vetor

int main()
{
    //VAR
    char nomes[TAMANHO_VET][40]; //nao tenho IDEIA de qual a função desse '[40]' sinto mto
    float media[TAMANHO_VET], maior_med=0;
    int cont, indice_mm;

    //INICIO
    for (cont = 0; cont < TAMANHO_VET - 1; cont++)
    {
        printf("\nALUNO %d\n", cont + 1);
        printf("Nome: "); //Essa parte do input de nome eu nao consegui fazer, pesquisei na internet e achei isso ai
        setbuf(stdin, NULL);
        gets(nomes[cont]);
        do
        {
            printf("Media final: "); scanf("%f", &media[cont]);
            if (media[cont] < 0 || media[cont] > 10)
                printf("Valor invalido. Insira novamente.\n");
        } while (media[cont] < 0 || media[cont] > 10);

        if (media[cont] > maior_med) //Filtrando a maior media
        {
            maior_med = media[cont];
            indice_mm = cont;
        }

        if (media[cont] < 7) //Se a media for insuficiente
            printf("Aluno com media insuficiente. Nota necessaria no exame final: %.2f\n", 7 - media[cont]);
    }

    //SAIDAS
    printf("\nO(a) aluno(a) %s teve a maior media entre os alunos listados! Media: %.1f", nomes[indice_mm], maior_med);

    //FIM
    return 0;
}