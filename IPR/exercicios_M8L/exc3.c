/*  ENUNCIADO
Faça um programa para corrigir uma prova de múltipla escolha de 10 questões, cujo
gabarito é b, c, d, a, a, e, b, d, a, c. Cada questão vale 1,0 ponto e a nota será de 0,0 a
10,0. O programa deve ler do teclado o número de matrícula de até 30 alunos em um
vetor e suas respectivas respostas em uma matriz (que devem obrigatoriamente estar
entre ‘a’ e ‘e’. 
A seguir, o programa deve calcular e imprimir:
a. Para cada aluno, seu número e nota.
b. A porcentagem de alunos aprovados, sendo a menor nota para aprovação
igual a 6,0.
*/

#include <stdio.h>

#define MAX_ALUNOS 30

int main()
{
    //VAR
    int alunos, matriculas[MAX_ALUNOS], notas[MAX_ALUNOS];
    char respostas[MAX_ALUNOS][10], gabarito[10] = {'b', 'c', 'd', 'a', 'a', 'e', 'b', 'd', 'a', 'c'};
    float aprovados = 0;

    //INICIO
    do //NUMERO DE ALUNOS
    {
        printf("Insira o numero de alunos: "); scanf("%d", &alunos);
        if (alunos < 0 || alunos > MAX_ALUNOS)
            printf("Entrada Invalida!\n");
    } while (alunos < 0 || alunos > MAX_ALUNOS);

    for (int cont=0; cont < alunos; cont++) //PARA CADA ALUNO (ENTRADA)
    {
        notas[cont] = 0; //reseta a nota para 0
        do //PERGUNTAR MATRICULA
        {
            printf("\nMATRICULA ALUNO %d: ", cont + 1); scanf("%d", &matriculas[cont]);
            if (matriculas[cont] < 0 || matriculas[cont] > 99999)
                printf("Entrada Invalida! obs: 5 digitos apenas\n");
        } while (matriculas[cont] < 0 || matriculas[cont] > 99999);
        
        printf("GABARITO ALUNO %d\n", cont + 1); //GABARITO DO ALUNO
        for (int cont2=0; cont2 <= 9; cont2++) //PARA CADA QUESTAO
        {
            printf("QUESTAO %d: ", cont2 + 1); scanf(" %c", &respostas[cont][cont2]);
            getchar();
            if (respostas[cont][cont2] == gabarito[cont2]) //Se acertou a questao +1 ponto
                notas[cont]++;
        }
        if (notas[cont] >= 6) //Se foi aprovado
            aprovados++;
    }

    //SAIDAS
    printf("\nRESULTADOS:\n");
    for (int cont=0; cont < alunos; cont++) //PARA CADA ALUNO (SAIDA)
        printf("ALUNO %d - NOTA: %d\n", matriculas[cont], notas[cont]);
    printf("Porcentagem de aprovados: %.1f%%", aprovados / alunos * 100); //PORCENTAGEM DE APROVADOS
    
    //FIM
    return 0;
}