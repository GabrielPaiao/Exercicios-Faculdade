#include <stdio.h>

int main()
{
    float n1, n2 = 0, nm, media;

    printf("Insira a primeira nota: ");
    scanf("%f", &n1);

    n2 = 14 - n1;

    if (n2 > 3)
        printf("Voce precisa tirar %.1f na segunda prova a fim de ser aprovado!", n2);

    else
        printf("Voce foi reprovado e necessitará de um exame final!");
    
    return 0;
}