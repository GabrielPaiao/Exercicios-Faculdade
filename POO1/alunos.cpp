#include <iostream>
#include <string.h>

using namespace std;

struct Aluno
{
    string nome;
    string id;
    int idade;
    int* registro;

    Aluno(string oNome, string oId, int aIdade, int oRegistro)
    {
        nome = oNome;
        id = oId;
        idade = aIdade;
        registro = (int*)malloc(sizeof(int)); //alocando memoria
        //poderia ser "registro = new int;"
		*registro = oRegistro;
    }
    
    Aluno() //so usa this em metodos
    {
        nome = "";
        id = "";
        idade = 0;
		registro = new int; //alocando memoria
		*registro = 0000;
    }
    
    ~Aluno() //Destruidor desalocando memoria do registro
    {
        //free(this->registro);
        delete this->registro;
        cout << "Memoria liberada.\n";
    }

    void leDadosAluno()
    {
        cout << "\nRE-CADASTRO(nome, id, idade, registro): ";
        cin >> this->nome >> this->id >> this->idade >> *(this->registro);
    }

    void imprimeDados()
    {
        cout << "\nImprimindo Cadastro:\nNome: " << this->nome << "\nID: " << this->id << "\nIdade: " << this->idade << "\nRegistro: " << *(this->registro) << "\n"; 
    }

};

int main()
{
    //struct Aluno aluno1("Arshavin", "JC3027694", 32, 12345);
    struct Aluno aluno2;

    aluno2.imprimeDados();
    aluno2.leDadosAluno();
    aluno2.imprimeDados();

    return 0;
}