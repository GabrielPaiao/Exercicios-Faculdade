#include <stdio.h>

#define SENHA 4531

int main()
{
    int senha;

    printf("Por favor, insira a senha requisitada: ");
    scanf("%d", &senha);

    if (senha != SENHA)
        printf("Senha invalida!");
    else
        printf("Senha correta!");

    return 0;
}