#include <stdio.h>

int main()
{
    float n1, n2, n3;

    printf("Por favor, insira a nota da primeira prova: ");
    scanf("%f", &n1);
    printf("Agora da segunda: ");
    scanf("%f", &n2);
    printf("Por ultimo, da terceira: ");
    scanf("%f", &n3);

    if ((n1 + n2 + n3) / 3 < 7)
        printf("Esse aluno foi reprovado!\nSera necessaria uma prova final.");
    else
        printf("Esse aluno foi aprovado!");
    
    return 0;
}