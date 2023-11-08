/*Enunciado:  Faça um programa que preencha três vetores com dez posições cada um:

o primeiro vetor, com os nomes de  dez produtos; 
o segundo vetor, com os códigos dos dez produtos; 
e o terceiro vetor, com os preços dos produtos. 

Mostre um relatório apenas com o nome, o código, o preço e o novo preço dos produtos que sofrerão  aumento.
Sabe-se que os produtos que sofrerão aumento são aqueles que possuem código par ou preço superior a  R$ 1.000,00.
Sabe-se ainda que, para os produtos que satisfazem as duas condições anteriores, código e  preço, 
o aumento será de 20%; para aqueles que satisfazem apenas a condição de código, o aumento será  de 15%; 
e para aqueles que satisfazem apenas a condição de preço, o aumento será de 10%.*/

#include <stdio.h>
#define TAM_VETOR 10

int main()
{
    //VAR
    char nomes[TAM_VETOR][40]; //se nao tiver esse '40' o "gets" nao funciona
    int codigos[TAM_VETOR], cont, cont2;
    float precos[TAM_VETOR];


    //INICIO
    for (cont = 0; cont < TAM_VETOR; cont++)
    {
        //ENTRADAS
        printf("\nPRODUTO %d\n", cont + 1);
        printf("Insira o nome do produto: "); //NOME
        setbuf(stdin, NULL);
        gets(nomes[cont]);
        do //CODIGO
        {
            printf("Insira o codigo do produto (4 digitos int.): "); scanf("%d", &codigos[cont]);
            if (codigos[cont] < 0 || codigos[cont] > 9999)
                printf("Valor invalido.\n");
        } while (codigos[cont] < 0 || codigos[cont] > 9999);
        do //PREÇO
        {
            printf("Preco: R$"); scanf("%f", &precos[cont]);
            if (precos[cont] < 0 || precos[cont] > 10000)
                printf("Valor invalido.\n");
        } while (precos[cont] < 0 || precos[cont] > 10000);
        
        //ANALISES
        if (codigos[cont] % 2 == 0 && precos[cont] > 1000)
            precos[cont] += precos[cont] * 0.20;
        else if (codigos[cont] % 2 ==0)
            precos[cont] += precos[cont] * 0.15;
        else if (precos[cont] > 1000)
            precos[cont] += precos[cont] * 0.10;
    }

    //SAIDAS
    printf("\nRELATORIO\n");
    for (cont2 = 0; cont2 < TAM_VETOR; cont2++)
        printf("Produto: %s  ||Codigo: %d  || Preco Total: R$%.2f\n", nomes[cont2], codigos[cont2], precos[cont2]);


    //FIM
    return 0;
}