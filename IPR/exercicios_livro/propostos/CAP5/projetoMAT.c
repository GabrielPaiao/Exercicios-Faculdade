/*
TAREFA: Desenvolvam um sistema que resolva um sistema de 2 e 3 variáveis, realizando as seguintes etapas:
1) usuário digita as equações de entrada;
2) o sistema é exibido;
3) calcula-se o determinante da matriz;
4) Classifica-se o sistema de acordo com o determinante;
5) Aplicam-se os métodos de resolução estudados;
6) Exibe-se a solução, caso possua.
obs:  O aluno deve prever situações em que o usuário digita algo errado e o programa deve retornar para ele
com a orientação adequada.

Código por: Gabriel Pereira Paião, 1ADS
*/

#include <stdio.h>
#include "projetoMAT.h" //Chamando a biblioteca com as funções criadas para o programa

int main() //CORPO DO PROGRAMA
{
    //VAR
    int n, i, j;
    float sistema[3][4];

    //INICIO
    printf("Bem vindo, usuario! Esse programa te auxilia no calculo de sistemas lineares, vamos comecar!\n\n");

    //ENTRADAS
    do //Numero de variáveis (ENTRADA PROTEGIDA)
    {
        printf("Digite o numero de variaveis (2 ou 3): ");
        scanf("%d", &n);
        if (n != 2 && n != 3) 
            printf("Numero de variaveis invalido, por favor, tente novamente.\n");
    }while (n != 2 && n != 3);
    
    printf("Digite as equacoes de entrada:\n"); //Entrada das equações (ENTRADA PROTEGIDA)
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n + 1; j++) 
        {
            printf("Digite o coeficiente a[%d][%d]: ", i, j);
            while (scanf("%f", &sistema[i][j]) != 1) //Enquanto a resposta nao for válida...
            {
                printf("Entrada invalida. Digite um numero real.\n");
                while (getchar() != '\n'); // Limpa o buffer de entrada
                printf("Digite o coeficiente [%d][%d]: ", i, j);
            }
        }
    }
    
    //SAÍDAS
    printf("\nSistema de equacoes:\n"); //Chamando a função de imprimir o sistema inserido
    imprimirSistema(n, sistema);

    //Imprimindo a determinante através da funcao que criei
    printf("\nDeterminante: %.2f\n", calculoDeDeterminante(n, sistema));
    
    if (calculoDeDeterminante(n, sistema) != 0) //Verificando se o sistema é possível e imprimindo na tela
        printf("\nClassificacao do sistema: Sistema POSSIVEL e DETERMINADO\n");
    else 
        printf("\nClassificacao do sistema: Sistema IMPOSSIVEL e/ou INDETERMINADO\n");
    
    printf("\nResolvendo o sistema...\n"); //Resolução do Sistema
    resolverSistema(n, sistema);
    
    //FIM
    return 0;
}