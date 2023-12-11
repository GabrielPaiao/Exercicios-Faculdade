/*Enunciado: Uma companhia aérea mantém uma lista de voos previstos, identificados pelo
número de voo e outra para a quantidade de lugares ainda disponíveis em cada voo.
Cada avião leva um total de até 345 passageiros. Faça um programa que:

a. Inicialize a lista de voos para os valores 727, 442, 331, 447, 221, 291, inicialize a
lista de lugares disponíveis para o valor máximo,
b. Mostre um menu com as seguintes opções: listar voos previstos, fazer
reserva, cancelar reserva e sair do programa.
c. Faça reservas, indicando se ainda existem lugares disponíveis no voo citado.
Se houver, o programa deve perguntar se o usuário quer confirmar a reserva.
Se quiser, o número de lugares disponíveis para aquele voo deve ser
decrementado.
d. Desfaça reservas, incrementado o número de lugares disponíveis no voo
correspondente.*/

#include <stdio.h>

#define LUGARES 345

int main()
{
    //VAR
    int voos[6]= {727, 442, 331, 447, 221, 291}, assentos[6] = {LUGARES, LUGARES, LUGARES, LUGARES, LUGARES, LUGARES}, escolha, voo;
    char confirm, confirm_c;

    //INICIO
    do
    {
        printf("\nBem vindo ao menu! O que deseja?\nMENU DE OPCOES:\n"
                "[1] LISTAR VOOS PREVISTOS\n"
                "[2] FAZER RESERVA\n"
                "[3] CANCELAR RESERVA\n"
                "[4] SAIR DO PROGRAMA\nSUA ESCOLHA: "); scanf("%d", &escolha);

        switch (escolha)
        {
            case 1: //LISTAR VOOS PREVISTOS
                printf("\nEsses sao os voos previstos: ");
                for (int cont=0; cont < 6; cont++)
                    printf("%d; ", voos[cont]);
                break;
            case 2: //FAZER RESERVA
                do
                {
                    printf("Voce deseja um assento em qual voo?\nESCOLHA: "); scanf("%d", &voo);
                    if (voo != 727 && voo != 442 && ((voo != 331 && voo != 291) && (voo != 447 && voo != 221)))
                        printf("Esse voo nao existe!\n");
                } while (voo != 727 && voo != 442 && ((voo != 331 && voo != 291) && (voo != 447 && voo != 221)));

                for (int cont=0; cont < 6; cont++)
                    if (voos[cont] == voo)
                    {
                        if (assentos[cont] > 0)
                        {
                            printf("Esse voo possui um assento disponivel\nConfirmar Reserva[S/N]? ");
                            scanf(" %c", &confirm);
                            if (confirm == 'S' || confirm == 's')
                            {
                                printf("RESERVA CONFIRMADA!\n");
                                --assentos[cont];
                            }
                            else
                                printf("RESERVA CANCELADA!\n");
                        }
                        else
                            printf("Infelizmente nao existem mais assentos disponiveis nesse voo! :c\n");
                    }
                break;
            case 3: //CANCELAR RESERVA
                printf("Tem certeza de que deseja cancelar uma reserva[S/N]? ");
                scanf(" %c", &confirm_c);
                if (confirm_c == 's' || confirm_c == 'S')
                {
                    do
                    {
                        printf("Para qual voo?\nESCOLHA: "); scanf("%d", &voo);
                        if (voo != 727 && voo != 442 && ((voo != 331 && voo != 291) && (voo != 447 && voo != 221)))
                            printf("Esse voo nao existe!\n");
                    } while (voo != 727 && voo != 442 && ((voo != 331 && voo != 291) && (voo != 447 && voo != 221)));
                    
                    for (int cont=0; cont <= 6; cont++)
                    if (voos[cont] == voo)
                    {
                        if (assentos[cont] < LUGARES)
                        {
                            printf("RESERVA CANCELADA!\n");
                            ++assentos[cont];
                        }
                        else
                            printf("Esse voo nao possui uma reserva a ser cancelada!\n");
                    }
                }
                break;
            case 4: //SAIR DO PROGRAMA
                printf("Obrigado por utilizar esse sistema!\n");
                break;
            default:
                printf("Escolha Invalida!\n");
        }
    } while (escolha != 4);


    //FIM
    return 0;
}