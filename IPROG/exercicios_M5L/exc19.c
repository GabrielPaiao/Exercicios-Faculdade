/*Enunciado: Construa um programa que receba três valores quaisquer e imprima-os em ordem
crescente. Como seu programa reage a valores de entrada iguais como no exercício
anterior?*/

#include <stdio.h>

int main()
{
    //VAR
    int n1, n2, n3;

    //INICIO
    printf("Insira um numeros: "); scanf("%d", &n1);
    printf("Insira um numeros: "); scanf("%d", &n2);
    printf("Insira um numeros: "); scanf("%d", &n3);


    if (n1 <= n2 && n1 <= n3)
    {
        printf(" %d;", n1);
        if (n2 <= n3)
            printf(" %d; %d;", n2, n3);
        else
            printf(" %d; %d;", n3, n2);
    }
    else if (n2 <= n1 && n2 <= n3)
    {
        printf(" %d;", n2);
        if (n1 <= n3)
            printf(" %d; %d;", n1, n3);
        else
            printf(" %d; %d;", n3, n1);
    }
    else
    {
      printf(" %d;", n3);
        if (n1 <= n2)
            printf(" %d; %d;", n1, n2);
        else
            printf(" %d; %d;", n2, n1);  
    }

    //FIM
    return 0;
}
