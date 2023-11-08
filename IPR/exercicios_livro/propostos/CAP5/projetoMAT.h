//Projeto 1sem Matematica
#ifndef projetoMAT
#define projetoMAT

#include <stdio.h>

void imprimirSistema(int n, float sistema[][4]) //Funcao responsavel por imprimir o Sistema do usuario
{
    int i, j; //variaveis contador para matriz que armazena o sistema inserido pelo usuario

    for (i = 0; i < n; i++) {
        printf("{ ");

        for (j = 0; j < n; j++) {
            printf("%.2f(x%d)", sistema[i][j], j + 1);

            if (j != n - 1) {
                printf(" + ");
            }
        }

        printf(" = %.2f\n", sistema[i]);
    }
}

float calculoDeDeterminante(int n, float sistema[][4]) //Funcao de calculo da determinante
{
    float det;
    if (n == 2) 
        det = sistema[0][0] * sistema[1][1] - sistema[0][1] * sistema[1][0];
    else if (n == 3) 
    {
        det = sistema[0][0] * sistema[1][1] * sistema[2][2] +
              sistema[0][1] * sistema[1][2] * sistema[2][0] +
              sistema[0][2] * sistema[1][0] * sistema[2][1] -
              sistema[0][2] * sistema[1][1] * sistema[2][0] -
              sistema[0][0] * sistema[1][2] * sistema[2][1] -
              sistema[0][1] * sistema[1][0] * sistema[2][2];
    }
    else 
    {
        det = 0;
    }
    return det;
}

void resolverSistema(int n, float sistema[][4]) //Funcao para a resolucao do sistema (se possivel)
{
    float det = calculoDeDeterminante(n, sistema);
    
    if (det != 0) //Se possui solução
    {
        if (n == 2) //Se sistema de duas equações
        {
            float x = (sistema[0][2] * sistema[1][1] - sistema[0][1] * sistema[1][2]) / det;
            float y = (sistema[0][0] * sistema[1][2] - sistema[0][2] * sistema[1][0]) / det;
            printf("Solucao: x = %.2f, y = %.2f\n", x, y);
        } 
        else if (n == 3) //Se sistema de três equações
        {
            float x = (sistema[0][3] * (sistema[1][1] * sistema[2][2] - sistema[1][2] * sistema[2][1]) +
                       sistema[1][3] * (sistema[0][2] * sistema[2][1] - sistema[0][1] * sistema[2][2]) +
                       sistema[2][3] * (sistema[0][1] * sistema[1][2] - sistema[0][2] * sistema[1][1])) / det;
            
            float y = (sistema[0][0] * (sistema[1][2] * sistema[2][3] - sistema[1][3] * sistema[2][2]) +
                       sistema[1][0] * (sistema[0][3] * sistema[2][2] - sistema[0][2] * sistema[2][3]) +
                       sistema[2][0] * (sistema[0][2] * sistema[1][3] - sistema[0][3] * sistema[1][2])) / det;
            
            float z = (sistema[0][0] * (sistema[1][3] * sistema[2][1] - sistema[1][1] * sistema[2][3]) +
                       sistema[1][0] * (sistema[0][1] * sistema[2][3] - sistema[0][3] * sistema[2][1]) +
                       sistema[2][0] * (sistema[0][3] * sistema[1][1] - sistema[0][1] * sistema[1][3])) / det;

            printf("Solucao: x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
        }
    } 
    else
        printf("Sistema nao possui solucao\n");
}

#endif
