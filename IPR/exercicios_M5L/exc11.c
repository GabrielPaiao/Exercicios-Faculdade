/*Enunciado: Um programa didático para crianças consiste em pedir dois números inteiros
quaisquer para a criança e depois perguntar a soma desses dois números. Se a
resposta estiver certa, o programa imprime uma mensagem de incentivo. Se não, o
programa imprime o valor correto da soma. Implemente esse programa. */

#include <stdio.h>

int main()
{
    //VAR
    int n1, n2, soma;

    //INICIO
    printf("Bem vindo!!!\nDigite um numero para comecarmos: "); scanf("%d", &n1);
    printf("Agora insira outro numero: "); scanf("%d", &n2);
    do
    {
        printf("Agora, quanto voce acha que vale a soma desses dois numeros? "); scanf("%d", &soma);
        if (soma == n1 + n2)
            printf("Parabens, voce acertou!! Continue assim :D");
        else
            printf("Essa nao eh a resposta certa, por que nao tenta de novo?\n");
    } while (soma != n1 + n2);

    //FIM
    return 0;
}