#include <stdio.h>

int main()
{
    float n1, n2, media;
    int escolha;

    printf("ESCOLHA DOIS NUMEROS A SEREM OPERADOS\nNumero 1: ");
    scanf("%f", &n1);
    printf("Numero 2: ");
    scanf("%f", &n2);

    printf("\nPor favor, escolha uma das operacoes a serem executadas.\n[1] Media             [2]Subtracao\n[3] Multiplicacao     [4] Divisao (n1 /n2 != 0)\nSUA ESCOLHA: ");
    scanf("%d", &escolha);

    switch(escolha)
    {
        case 1:
            media = (n1 + n2) / 2;
            printf("A media dos numeros inserido eh: %.2f", media);
            break;
        case 2:
            printf("A diferenca entre os numeros inseridos eh de: %.1f", n1-n2);
            break;
        case 3:
            printf("O produto dos dois valores eh: %.2f", n1*n2);
            break;
        case 4:
            if (n2 != 0)
                printf("O valor da divisao de %.1f por %.1f eh: %.3f", n1, n2, n1/n2);
            else
                printf("Impossivel dividir um numero por 0 :c");
            break;
        default:
            printf("ERRO! Escolha invalida.");
    }

    return 0;
}