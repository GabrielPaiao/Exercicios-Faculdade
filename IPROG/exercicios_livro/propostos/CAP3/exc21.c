/*Enunciado: Faça um programa que receba o número de horas trabalhadas, o valor do salário mínimo e
o número  de horas extras trabalhadas, calcule e mostre o salário a receber, de acordo com as regras a seguir:
a) a hora trabalhada vale 1/8 do salário mínimo; 
c) o salário bruto equivale ao número de horas trabalhadas multiplicado pelo valor da hora trabalhada;  
d) a quantia a receber pelas horas extras equivale ao número de horas extras trabalhadas multiplicado pelo
valor da hora extra;  
e) o salário a receber equivale ao salário bruto mais a quantia a receber pelas horas extras.*/

#include <stdio.h> //Importando a(s) bibliotecas necessária(s)

int main() //Criando função main(int) para o corpo do programa
{
    float sal_min, horas, extras, receber; /*Declarando 4 variáveis de tipo float, 3 para entrada do usuário e 
    uma para definir através dos cálculos necessário o salário final a ser recebido*/

    printf("Por favor, insira o valor do salario minimo: R$"); //Solicitando diversas entradas do usuário
    scanf("%f", &sal_min);
    printf("Agora, a quantidade de horas trabalhadas: ");
    scanf("%f", &horas);
    printf("Mais as horas extras: ");
    scanf("%f", &extras);

    receber = horas * sal_min / 8; //Cálculo do SALÁRIO BRUTO
    receber += extras * sal_min / 4; /*O salário bruto é somado aos adicionais de horas extras trabalhadas*/


    printf("O salario a ser recebido eh de: R$%.2f", receber);
}
