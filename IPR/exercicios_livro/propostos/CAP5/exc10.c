/*Enunciado: Faça um programa que receba dez números, calcule e mostre a soma dos números pares e a
soma dos  números primos.*/

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //VAR
    float soma_par, soma_pri;
    int cont, cont2, n, eh_primo;

    //INICIO
    printf("Analisando numeros primos e pares.\n");
    for (cont = 1; cont <=10; cont++)
    {
        printf("Insira o %d numero: ", cont);
        scanf("%d", &n);

        //Verificando se é par
        if (n % 2 == 0)
            soma_par += n;

        //VERIFICANDO SE O NUMERO É PRIMO
        //VARIAVEL 'eh_primo' se == 1, o numero é primo, se == 0, não é.
        eh_primo = 1; //começa como primo

        if (n < 2) //Se o numero for menor que 2, não é primo, nao existe primo menor que 2
            eh_primo = 0;

        for (cont2 = 2; cont2 < n; cont2++) /*Realizando diversas divisoes com o divisor começando em 2 e indo até
        o valor do numero inserido, se alguma dessas divisões der resto 0, o numero não é primo.*/
        {
            if (n % cont2 == 0)
                eh_primo = 0;
        }
        if (eh_primo) //Se o valor da variável 'eh_primo' == 1, o numero é primo e será somado com os outros
            soma_pri += n;
    }

    //SAÍDAS
    printf("A soma dos números PARES inseridos foi de: %.2f\n", soma_par);
    printf("A soma dos números PRIMOS inseridos foi de: %.2f", soma_pri);

    //FIM
    return 0;
}