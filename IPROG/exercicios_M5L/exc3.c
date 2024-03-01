#include <stdio.h>

int main()
{
    float n;

    printf("UTILIZE '.'(ponto final) NO LUGAR DE ','(virgula),POR FAVOR!\nDigite um numero real: ");
    scanf("%f", &n);

    if (n > 0)
        printf("Esse numero eh positivo!");
    else
        printf("Esse numero eh negativo!");

    return 0;
}