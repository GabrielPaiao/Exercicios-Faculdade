#include <stdio.h>

#define PRECO_MIN 30
#define PRECO_MAX 100

int main()
{
    float preco;
    int codigo;

    printf("LISTA DE PRODUTOS E SEUS CODIGOS\nBANANA - 1023\nTODDYNHO - 1101\nBOLINHO ANA MARIA - 2233\nFANTA MARACUJA 2L - 1044\n\nPOR FAVOR, INSIRA O CODIGO DO PRODUTO ESCOLHIDO: ");
    scanf("%d", &codigo);

    printf("Agora, por favor, insira o preco atual do produto selecionado: R$");
    scanf("%f", &preco);

    if (preco < PRECO_MIN)
    {
        printf("Seu produto nao recebe desconto.\nTotal a pagar: R$%.2f", preco);
    }
    else if (preco >= PRECO_MIN && preco < PRECO_MAX)
    {
        preco -= preco * 0.10;
        printf("Seu produto recebe desconto de 10 por cento.\nTotal a pagar: R$%.2f", preco);
    }
    else
    {
        preco -= preco * 0.15;
        printf("Seu produto recebe desconto de 15 por cento.\nTotal a pagar: R$%.2f", preco);
    }

    return 0;
}