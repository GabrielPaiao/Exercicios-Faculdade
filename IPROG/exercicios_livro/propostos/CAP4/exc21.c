#include <stdio.h>

int main()
{
    float preco;
    int codigo;

    printf("Insira o valor do produto R$");
    scanf("%f", &preco);
    printf("Por favor, insira o codigo de origem do produto (1-30): ");
    scanf("%d", &codigo);

    switch (codigo)
    {
    case 1:
        printf("O produto de valor R$%.2f tem o SUL como sua origem.", preco);
        break;
    case 2:
        printf("O produto de valor R$%.2f tem o NORTE como sua origem.", preco);
        break;
    case 3:
        printf("O produto de valor R$%.2f tem o LESTE como sua origem.", preco);
        break;
    case 4:
        printf("O produto de valor R$%.2f tem o OESTE como sua origem.", preco);
        break;
    case 5:
        printf("O produto de valor R$%.2f tem o NORDESTE como sua origem.", preco);
        break;
    case 6:
        printf("O produto de valor R$%.2f tem o NORDESTE como sua origem.", preco);
        break;
    default:
        if (codigo >= 7 && codigo < 10)
            printf("O produto de valor R$%.2f tem o SUDESTE como sua origem.", preco);
        else if (codigo >= 10 && codigo <21)
            printf("O produto de valor R$%.2f tem o CENTRO-OESTE como sua origem.", preco);
        else if (codigo >= 21 && codigo < 31)
            printf("O produto de valor R$%.2f tem o NORDESTE como sua origem.", preco);
        else
            printf("Nao foi possivel localizar a procedencia do seu produto :c");
        break;
    }

    return 0;

}