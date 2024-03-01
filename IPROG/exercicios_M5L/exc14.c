/*Enunciado: . O que acontece no programa anterior se a pessoa nasceu há 18 anos, mas ainda não
fez aniversário? Melhore o programa para que, neste caso, o programa pergunte se a
pessoa já fez aniversário ou não antes de imprimir o resultado. 
*/

#include <stdio.h>

#define ANO_ATUAL 2023
#define MAIORIDADE 18

int main()
{
    //VAR
    int ano, idade;
    char aniversario;

    //INICIO
    do
    {
        printf("Insira seu ano de nascimento: "); scanf("%d", &ano);
        if (ano <= 1900 || ano > ANO_ATUAL)
            printf("Entrada Invalida :c\n");
    } while (ano <= 1900 || ano > ANO_ATUAL);

    idade = ANO_ATUAL - ano;

    do
    {
        printf("Ja fez aniversario? [S/N]: "); scanf(" %c", &aniversario);
        if (aniversario != 'S' && aniversario != 's' && (aniversario != 'N' && aniversario != 'n'))
            printf("Entrada Invalida :c\n");
        else if (aniversario == 'N' || aniversario == 'n')
            idade--;
    } while (aniversario != 'S' && aniversario != 's' && (aniversario != 'N' && aniversario != 'n'));
    
    if (idade >= MAIORIDADE)
        printf("Parabens, Voce eh maior de idade! (%d anos de idade)", idade);
    else
        printf("Voce ainda eh de menor aos %d anos de idade :c", idade);

    //FIM
    return 0;
}