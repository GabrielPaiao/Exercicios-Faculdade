#include <stdio.h>

int main()
{
    float altura, peso;
    char sexo;

    printf("Por favor, insira seu sexo[M]/[F]: ");
    scanf("%c", &sexo); 
    printf("Agora, insira sua altura(m): ");
    scanf("%f", &altura);

    if (sexo == 'M')
    {
        peso = (72.7 * altura) - 58;
        printf("Seu peso ideal, como pessoa do sexo MASCULINO, seria de: %.2fkg!", peso);
    }
    else
    {
        peso = (62.7 * altura) - 44.7;
        printf("Seu peso ideal, como pessoa do sexo FEMININO, seria de: %.2fkg!", peso);
    }
    return 0;
}