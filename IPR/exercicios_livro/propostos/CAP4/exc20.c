#include <stdio.h>

int main()
{
    int idade;
    
    printf("Por favor, insira sua idade: ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <=7)
        printf("Categoria na natacao: INFANTIL");
    else if (idade >= 8 && idade <= 10)
        printf("Categoria na natacao: JUVENIL");
    else if (idade >= 11 && idade <= 15)
        printf("Categoria na natacao: ADOLESCENTE");
    else if (idade >= 16 && idade <= 30)
    printf("Categoria na natacao: ADULTO");
    else if (idade >30)
        printf("Categoria na natacao: SENIOR");
    else
        printf("Voce nao possui categoria :c");

    return 0;
}