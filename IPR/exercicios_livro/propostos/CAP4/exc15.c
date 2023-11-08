#include <stdio.h>

int main()
{
    float investimento;
    int escolha;

    printf("Insira a quantia a ser investida: R$");
    scanf("%f", &investimento);
    printf("Por favor, insira seu tipo de investimento:\n[1] POUPANCA - Rendimento Mensal de 3 por cento.\n[2] Fundos de renda fixa - Rendimento mensal de 4 por cento.\nSUA ESCOLHA: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        investimento += investimento * 0.03;
        printf("Apos um mes de investimento em poupanca, o seu saldo seria de R$%.2f", investimento);
    }
    else if (escolha == 2)
    {
        investimento += investimento * 0.04;
        printf("Apos um mes de investimento em renda fixa, o seu saldo seria de R$%.2f", investimento);
    }
    else
        printf("Entrada invalida :c");

    return 0;
}
