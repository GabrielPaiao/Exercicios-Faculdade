#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void inverterString(char *str)
{
    int length = strlen(str), cont, cont2;
    char conso[20] = {'B', 'C', 'D', 'F', 'G', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};

    for (cont = 0, cont2 = length - 1; cont < cont2; cont++, cont2--)
    {
        char temp = str[cont]; // temp = primeiro caractere
        for (int cont3 = 0; cont3 < 20; cont3++)
        {
            if (conso[cont3] == toupper(temp))
            {
                temp = '#';
                break;
            }
        }
        str[cont] = str[cont2]; // primeiro carectere recebe ultimo caractere
        str[cont2] = temp; //ultimo caractere recebe o primeiro caractere
    }
}

int main()
{
    //VAR
    char msg[50];

    //INICIO
    setlocale(LC_ALL, "");
    printf("Qual a mensagem a ser criptografada?\n");
    fgets(msg, 50, stdin);
    fflush(stdin);
    inverterString(msg);
    
    printf("%s", msg);

    //FIM
    return 0;
}