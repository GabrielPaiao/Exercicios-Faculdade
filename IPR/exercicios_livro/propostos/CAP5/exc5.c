/*Enunciado: Faça um programa que mostre as tabuadas dos números de 1 a 10.*/

#include <stdio.h>

int main()
{
    //VAR
        int n=1, cont;

    //INICIO
    printf("TABUADA");
    while (n <= 10)
    {
        printf("\nTabuada do %d\n", n);
        for (cont = 1; cont <= 10; cont++)
            {
            printf("%d x %d = %d\n", n, cont, n * cont);
            }
        n++;
    }

    //FIM
    return 0;
}