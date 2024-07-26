#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ivisao
{
    public:
    virtual void atualiza() = 0;

    virtual ~Ivisao() {};
};

class Modelo
{
    private:
    vector<Ivisao*> visoes;

    public:
    void addVisao(Ivisao* _visao)
    {
        this->visoes.push_back(_visao);
    }

    void removeVisao(int _indicevisao)
    {
        this->visoes.erase(visoes.begin() + _indicevisao); 
    }

    void notifica()
    {
        for (int i = 0; i < this->visoes.size(); i++) // Usar size_t como tipo do "i" para evitar o aviso
        {
            this->visoes[i]->atualiza();
        }
    }
};

class Dado : public Modelo
{
    private:
    string valor;

    public:
    Dado()
    {
        this->valor = " ";
    }

    const string getValor()
    {
        return this->valor;
    }

    void setValor(string _valor)
    {
        this->valor = _valor;
        this->notifica();
    }

    ~Dado() {};
};

class VisaoEspecifica : public Ivisao
{
    private:
    string situacao;
    Dado* dado;

    public:
    VisaoEspecifica(Dado* _dado)
    {
        this->situacao = " ";
        this->dado = _dado;
        dado->addVisao(this);
    }

    void printSituacao()
    {
        cout << "Situacao: " << this->situacao << "\n";
    }

    void atualiza() override
    {
        this->situacao = dado->getValor();
    }

    ~VisaoEspecifica() {};
};

class VisaoGeral : public Ivisao
{
    private:
    string estado;
    Dado* dado;

    public:
    VisaoGeral(Dado* _dado)
    {
        this->estado = " ";
        this->dado = _dado;
        dado->addVisao(this);
    }

    void printEstado()
    {
        cout << "Estado: " << this->estado << "\n";
    }

    void atualiza() override
    {
        this->estado = dado->getValor();
    };

    ~VisaoGeral() {};
};


int main()
{
    Dado* dado1 = new Dado();
    VisaoEspecifica* ve1 = new VisaoEspecifica(dado1);
    VisaoGeral* vg1 = new VisaoGeral(dado1);

    dado1->setValor("novo valor de teste\n");

    ve1->printSituacao();
    vg1->printEstado();

    delete dado1;
    delete ve1;
    delete vg1;

    return 0;
}