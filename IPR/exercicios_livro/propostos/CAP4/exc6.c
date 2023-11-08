/*6. Faça um programa que receba dois números e execute uma das operações listadas a seguir, de acordo com
a  escolha do usuário. Se for digitada uma opção inválida, mostre mensagem de erro e termine a execução do  programa.
As opções são:  
a) O primeiro número elevado ao segundo número. 
b) Raiz quadrada de cada um dos números.  
c) Raiz cúbica de cada um dos números.*/

#include <stdio.h>
#include <math.h>

int main()
{
    float n1, n2;
    int escolha;

    printf("Escolha dois numeros a serem operados:\nNumero 1: ");
    scanf("%f", &n1);
    printf("Numero 2: ");
    scanf("%f", &n2);

    printf("Por favor, escolha uma operacao:\n[1] O primeiro termo elevado ao segundo\n[2] Raiz quadrada de ambos\n[3] Raiz cubica de ambos\nSUA ESCOLHA: ");
    scanf("%d", &escolha);
    switch(escolha)
    {
        case 1:
            printf("O resultado de %.0f^%.0f eh: %.2f!", n1, n2, pow(n1, n2));
            break;
        case 2:
            printf("Raiz quadrada de %.2f = %.3f\nRaiz quadrada de %.2f = %.3f", n1, sqrt(n1), n2, sqrt(n2));
            break;
        case 3:
            printf("Raiz quadrada de %2f = %.3f\nRaiz quadrada de %.2f = %.3f", n1, cbrt(n1), n2, cbrt(n2));
            break;
        default:
            printf("Opcao invalida! :c");
    }

    return 0;
}