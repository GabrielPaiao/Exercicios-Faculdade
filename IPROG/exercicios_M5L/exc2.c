#include <stdio.h>

int main()
{
    int n;
    
    printf("Por favor, insira um numero inteiro: ");
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("Esse numero eh par!");
    else
        printf("Esse numero eh impar!");
    return 0;
}