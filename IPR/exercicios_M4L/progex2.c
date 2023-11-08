//calcula a renda total da venda de 1264 produtos no valor R$0.68 e imprime essas informações:

#include <stdio.h>

int main()
{
    int vendidas = 1274;
    float valor = 0.68f, total = vendidas * valor;
    printf("Foram vendidas %d mercadorias no valor de %.2f!\nLucro das vendas: R$%.2f", vendidas, valor, total);
}

//variáveis de valor fixo, não recebe input do usuário/teclado.