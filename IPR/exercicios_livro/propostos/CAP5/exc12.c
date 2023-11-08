/*Enunciado: Faça um programa que receba dez números inteiros e mostre a quantidade de numeros primos inseridos*/

#include <stdio.h>

int main()
{
    //VAR
    int n, cont, cont2, primo, n_primo=0;

    //INICIO
    for (cont = 1; cont <=10; cont++)
    {
        printf("Por favor, insira o %d numero: ", cont); scanf("%d", &n);

        //Verificando se é primo
        primo = 1;
        if (n < 2) // Caso menor que 2, não é primo.
            primo = 0;
        for (cont2 = 2; cont2 < n; cont2++) //Testando divisões inteiras até o divisor == o numero inseridos
        {
            if (n % cont2 == 0) //Se o resto de alguma das divisões for 0, o numero nao é primo
                primo = 0;
        }
        if (primo) //Caso o numero seja primo, o contador de numeros primos tera um acrescido ao seu valor
            n_primo++;
    }

    //SAIDA
    printf("O numero de numeros primos inseridos foi de: %d", n_primo);

    //FIM
    return 0;
}