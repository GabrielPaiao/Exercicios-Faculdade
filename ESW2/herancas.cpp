#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Veiculo
{
    private:
    string nome;
    string cor;

    public:
    int velMax;
    int rodas;

    void setNome(string _nome)
    {
        this->nome = _nome;
    }

    const string getNome() //const pois nao modificam objetos
    {
        return this->nome;
    }

    void setCor(string _cor)
    {
        this->cor = _cor;
    }

    const string getCor() //const pois nao modificam objetos
    {
        return this->cor;
    }

    virtual void printVeiculo()
    {
        cout << "     Nome: " << this->nome << "\n";
        cout << "      Cor: " << this->cor << "\n";
        cout << "    Rodas: " << this->rodas << "\n";
        cout << "Vel. Max.: " << this->velMax << "\n" << endl;
    }
};

class Carro : public Veiculo //herdando
{
    public:
    Carro() //as propriedas nao foram definidas, mas estão aqui pq foram herdadas de veiculo
    {
        velMax = 160;
        rodas = 4;
        setNome("HB20");
        setCor("Branco");
    };
};

class Militar : public Veiculo
{
    public:
    int municao;
    bool possuiArmas;

    Militar (int _municao, bool _possuiArmas) : municao(_municao), possuiArmas(_possuiArmas)//atribui os valores antes de entrar no construtor
    {
        velMax = 100;
        rodas = 6;
        setNome("Tank");
        setCor("Verde");

        if (possuiArmas)
        {
            this->municao = _municao;
        }
        else
        {
            this->municao = 0;
        }
    };

    virtual void printVeiculo() override
    {
        cout << "     Nome: " << this->getNome() << "\n";
        cout << "      Cor: " << this->getCor() << "\n";
        cout << "    Rodas: " << this->rodas << "\n";
        cout << "Vel. Max.: " << this->velMax << "\n";
        cout << "Armamento: " << this->possuiArmas << "\n";
        cout << "  Municao: " << this->municao << "\n" << endl;
    }
};



int main()
{
    Carro c1;
    Militar m1(true, 1100);
    Militar m2(false, 0);

    c1.printVeiculo();
    m1.printVeiculo();
    m2.printVeiculo();

    return 0;
}