/*
Foi realizada uma pesquisa entre 15 habitantes de uma região. Os dados coletados de cada habitante foram: 
idade, sexo, salário e número de filhos.
Faça uma sub-rotina que leia esses dados armazenando-os em vetores. 
Depois, crie sub-rotinas que  recebam esses vetores como parâmetro e retornem a média de salário entre os habitantes,
a menor e a  maior idade do grupo e a quantidade de mulheres com três filhos que recebem até R$ 500,00 
(utilize  uma sub-rotina para cada cálculo).
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define HABITANTES 15

struct perfil
{
    int idade, nfilhos;
    char sexo;
    float salario;
};
typedef struct perfil perfil; //RENOMEIA A STRUCT AFIM DE CHAMADOS

//VAR GLOBAL, aparece em todas as funções
perfil lista[HABITANTES];

void LeituraDePerfil(perfil lista[HABITANTES])
{
    for (int cont=0; cont < HABITANTES; cont++)
    {
        printf("\nPERFIL PESSOA %d:\n", cont + 1);
        do
        {
            printf("Idade: "); scanf("%d", &lista[cont].idade);
            if (lista[cont].idade < 0 || lista[cont].idade > 120)
                printf("ENTRADA INVALIDA! Por favor, insira novamente.\n");
        } while (lista[cont].idade < 0 || lista[cont].idade > 120);
        
        do
        {
            printf("Sexo: "); scanf(" %c", &lista[cont].sexo);
            if (lista[cont].sexo != 'm' && lista[cont].sexo != 'M' && (lista[cont].sexo != 'F' && lista[cont].sexo != 'f'))
                printf("ENTRADA INVALIDA! Por favor, insira novamente.\n");
        } while (lista[cont].sexo != 'm' && lista[cont].sexo != 'M' && (lista[cont].sexo != 'F' && lista[cont].sexo != 'f'));
        
        do
        {
            printf("Salario: "), scanf("%f", &lista[cont].salario);
            if (lista[cont].salario < 0)
                printf("ENTRADA INVALIDA! Por favor, insira novamente.\n");
        } while (lista[cont].salario < 0);
        
        do
        {
            printf("Numero de fihos: "); scanf("%d", &lista[cont].nfilhos);
            if (lista[cont].nfilhos < 0 || lista[cont].nfilhos > 15)
                printf("ENTRADA INVALIDA! Por favor, insira novamente.\n");
        } while (lista[cont].nfilhos < 0 || lista[cont].nfilhos > 15);
    }
}

float MediaSalarial(perfil lista[HABITANTES])
{
    float medias = 0;

    for (int cont=0; cont < HABITANTES; cont++)
        medias += lista[cont].salario;
    medias /= HABITANTES;
    return medias;
}

int MaiorEntreAsIdades(perfil lista[HABITANTES])
{
    int maior = 0;

    for (int cont=0; cont < HABITANTES; cont++)
    {
        if (lista[cont].idade > maior)
            maior = lista[cont].idade;
    }
    return maior;
}

int MenorEntreAsIdades(perfil lista[HABITANTES])
{
    int menor = lista[0].idade;

    for (int cont=0; cont < HABITANTES; cont++)
    {
        if (lista[cont].idade < menor)
            menor = lista[cont].idade;
    }
    return menor;
}

int QNTMulheres3filhosMenos500(perfil lista[HABITANTES])
{
    int c = 0;
    for (int cont=0; cont < HABITANTES; cont++)
    {
        if ((lista[cont].sexo == 'f' || lista[cont].sexo == 'F') && lista[cont].nfilhos == 3 && lista[cont].salario <= 500)
            c++;
    }
    return c;
}

int main()
{
    //INICIO
    setlocale(LC_ALL, "Portuguese");

    printf("BEM VINDO!\nNesse programa vamos analisar o perfil de 15 habitantes de uma cidade.\n\n");
    LeituraDePerfil(lista);
    
    printf("\nANÁLISE COMPLETA!!\n");
    printf("Media salarial dos habitantes: R$%.2f\n", MediaSalarial(lista));
    printf("Mulheres com 3 filhos que recebem até R$500: %d\n", QNTMulheres3filhosMenos500(lista));
    printf("Obrigado por utilizar esse sistema!");

    //FIM
    return 0;
}
