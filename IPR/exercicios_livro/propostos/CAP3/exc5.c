/*Enunciado:  Faça um programa que receba o preço de um produto, calcule e mostre o novo preço,
 sabendo-se  que este sofreu um desconto de 10%.*/

 #include <stdio.h> //Importando a(s) biblioteca(s) necessária(s)

 int main() //Criando função main(int) para o corpo do programa
 {
    float preco, preco_d; //Declarando duas variáveis de ponto flutuante simples para o programa

    printf("CALCULANDO DESCONTO\n Por favor, insira o valor do produto: R$"); /*Apresentando o programa e solicitando 
    entrada de teclado ao usuário*/
    
    scanf("%f", &preco); //Recebe input do usuário e associa o valor digitado à variável preço

    preco_d = preco - (preco / 100 * 10); //Calculando o desconto de 10%

    printf("O produto de valor R$%.2f recebeu um desconto de 10 porcento, passando a custar R$%.2f;", preco, preco_d);
    //Imprimindo resultados!
 }