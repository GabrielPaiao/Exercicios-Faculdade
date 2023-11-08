/*Enunciado: Uma loja utiliza o código V para transação à vista e P para transação a prazo. Faça um programa
que receba  o código e o valor de quinze transações, calcule e mostre:  

■■ o valor total das compras à vista;  
■■ o valor total das compras a prazo;  
■■ o valor total das compras efetuadas; e 
■■ o valor da primeira prestação das compras a prazo juntas, sabendo-se que serão pagas em três vezes. */

#include <stdio.h>
#include <locale.h>

int main()
{
    //VAR
    char codigo;
    float total_v, total_p, total, valor;
    int cont;

    //INICIO
    setlocale(LC_ALL, "Portuguese");

    for (cont = 1; cont <= 15; cont++)
    {
        printf("Valor da transação %d: R$", cont); scanf("%f", &valor);
        printf("Compra a vista [V] ou parcelada [P]? "); scanf(" %c", &codigo);
        
        if (codigo == 'V' || codigo == 'v') //Total a vista
            total_v += valor;
        else //Total parcelado
            total_p += valor;
        
        total += valor; //Total do total
    }

    //SAIDAS
    printf("\nValor total: R$%.2f\n", total);
    printf("Valor total (A Vista): R$%.2f\n", total_v);
    printf("Valor total (Parcelada): R$%.2f\n", total_p);
    printf("Valor parcelado em 3x (sem juros) de: R$%.2f", total_p / 3);

    //FIM
    return 0;
}