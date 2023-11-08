/*ENUNCIADO: Faça um programa que preencha um vetor com dez números inteiros e um segundo vetor com cinco números
inteiros, calcule e mostre dois vetores resultantes. O primeiro vetor resultante será composto pela soma
de cada número par do primeiro vetor somado a todos os números do segundo vetor. O segundo vetor resultante será 
composto pela quantidade de divisores que cada numero impar do primeiro vetor tem no segundo vetor.*/

#include <stdio.h>
#define TAM_VETOR1 10
#define TAM_VETOR2 5

int main()
{
    //VAR
    int vetor1[TAM_VETOR1], vetor2[TAM_VETOR2], vetorR1[TAM_VETOR1], vetorR2[TAM_VETOR1], cont1, cont2, cont, contador, cont_par, cont_impar, cont_impar2=0;
    //quantos contadores deus do ceu alguem me ajuda

    //INICIO
    printf("PREENCHENDO VETOR 1:\n");
    for (cont1 = 0; cont1 < TAM_VETOR1; cont1++) //ENTRADAS VETOR 1
    {
        printf("Insira um numero inteiro: ");
        scanf("%d", &vetor1[cont1]);
    }

    printf("\nPREENCHENDO VETOR 2:\n");
    for (cont2 = 0; cont2 < TAM_VETOR2; cont2++) //ENTRADAS VETOR 2
    {
        printf("Insira um numero inteiro: ");
        scanf("%d", &vetor2[cont2]);
    }

    //R1 "cada número par do primeiro vetor + todos os números do segundo vetor(?confuso)"
    for (cont_par=0; cont_par < TAM_VETOR1; cont_par++)
    {
        if (vetor1[cont_par] % 2 == 0)
            vetorR1[cont_par] = vetor1[cont_par] + vetor2[0] + vetor2[1] + vetor2[2] + vetor2[3] + vetor2[4];
        else
            vetorR1[cont_par] = 0;
    }

    //R2 "quantidade de divisores que cada numero impar do primeiro vetor tem no segundo vetor."
    for (cont_impar=0; cont_impar < TAM_VETOR1; cont_impar++)
    {
        vetorR2[cont_impar] = 0;
        if (vetor1[cont_impar] % 2 != 0)
            while (cont_impar2 < TAM_VETOR2)
            {
                if (vetor1[cont_impar] % vetor2[cont_impar2] == 0)
                    vetorR2[cont_impar]++;
                cont_impar2++;
            }
        if (cont_impar2 == 5)
            cont_impar2 = 0;
    }

    //SAIDAS
    printf("\nVETOR R1:\n");
    for (cont = 0; cont < TAM_VETOR1; cont++) //VETOR R1
    {
        printf("| %d", vetorR1[cont]);
    }
    printf("\nVETOR R2:\n");
    for (contador = 0; contador < TAM_VETOR1; contador++) //VETOR R2
    {
        printf("| %d", vetorR2[contador]);
    }

    //FIM
    return 0;
}