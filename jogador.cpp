#include <iostream>
#include <string>
using namespace std;

struct InteracaoUser
{
	static string cabecalho;
	
    static string entrada_nome()
    {
        string oNome;
        cin >> oNome;
        return oNome;
    }

    static void saida_nome(string oNome)
    {
        cout << oNome << endl;
    }

    static void saidaEentradaNome()
    {
        string nome;
        nome = entrada_nome();
        saida_nome(nome);
    }
};

struct Jogador
{
    string nome;
    string clube;
    int idade;

    Jogador()
    {
        this->nome = "";
        this->clube = "";
        this->idade = 0;
    }

    Jogador(string oNome, string oClube, int aIdade)
    {
        this->nome = oNome;
        this->clube = oClube;
        this->idade = aIdade;
    }

    void imprimeDadosJogador()
    {
        cout << "Nome: " << this->nome << "\nClube: " << this->clube << "\nIdade: " << this->idade << endl;
    }
};

string InteracaoUser::cabecalho = "\n#### ISSO EH UM PROGRAMA ###\n";

int main()
{
    Jogador j1(InteracaoUser::entrada_nome(), InteracaoUser::entrada_nome(), 18);

    cout << InteracaoUser::cabecalho;

    j1.imprimeDadosJogador();

    return 0;
}