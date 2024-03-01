/*Enunciado:  Faça um programa que apresente o menu de opções a seguir:  

Menu de opções:
1.  Média aritmética  
2.  Média ponderada  
3.  Sair  
Digite a opção desejada.

Na opção 1: receber duas notas, calcular e mostrar a média aritmética.
Na opção 2: receber três notas e seus respectivos pesos, calcular e mostrar a média ponderada.  
Na opção 3: sair do programa.

Verifique a possibilidade de opção inválida. Nesse caso, o programa deverá mostrar uma mensagem.*/

#include <stdio.h>

int main()
{
    //VAR
    int escolha;
    float n1, n2, n3, p1, p2, p3;

    //INICIO
    do
    {
        printf("\nMENU DE OPCOES\n"
                "1. Media Aritmetica\n"
                "2. Media Ponderada\n"
                "3. SAIR\n");

        do //INPUT ESCOLHA
        {
            printf("Sua escolha: "); scanf("%d", &escolha);
            if (escolha < 1 || escolha > 3)
                printf("Escolha invalida.");
        } while (escolha < 1 || escolha > 3);

        if (escolha == 1) //MEDIA ARITMETICA
        {
            printf("\nVoce escolheu: Media Aritimetica!\n"
                "Primeiro numero: ");
            scanf("%f", &n1);
            printf("Segundo numero: "); scanf("%f", &n2);

            printf("A media aritmetica dos numeros inseridos eh de: %.1f\n", (n1 + n2) / 2);
        }

        else if (escolha == 2) //MEDIA PONDERADA
        {
            printf("\nVoce escolheu: Media Ponderada!\n"
                "Primeiro numero: ");
            scanf("%f", &n1);
            printf("Peso: "); scanf("%f", &p1);
            printf("Segundo numero: "); scanf("%f", &n2);
            printf("Peso: "); scanf("%f", &p2);
            printf("Terceiro numero: "); scanf("%f", &n3);
            printf("Peso: "); scanf("%f", &p3);

            printf("A media ponderada dos numeros inseridos eh de: %.1f\n", (n1 * p1 + n2 * p2 + n3 * p3) / (p1 + p2 + p3));
        }

    }while (escolha != 3);

    printf("Voce escolheu sair do programa :c");

    //FIM
    return 0;
}