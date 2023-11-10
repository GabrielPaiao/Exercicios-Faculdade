#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class InputUser
{
    public:

    string inputString(string textoInput)
    {
        string aux;
        cout << textoInput;
        cin >> aux;
        return aux;
    }

    int inputInt(string textoInput)
    {
        int aux;
        cout << textoInput;
        cin >> aux;
        return aux;
    }

    float inputFloat(string textoInput)
    {
        float aux;
        cout << textoInput;
        cin >> aux;
        return aux;
    }
};

class Celular
{
    string nome;
    static string marca;
    int memoriaRAM;
    int memoria;
    int* bateria;
    float* valor;
    bool ligar;

    public:
    // CONSTRUTORES
    Celular();
    Celular(string _nome, string _marca, int _ram, int _memoria, int _bateria, float _valor, bool _ligar);
    Celular(Celular* _celular);
    ~Celular();

    void carregarBateria()
    {
        if (*bateria == 100)
            cout << "A bateria ja esta carregada.\n";
        else
        {
            *bateria = 100;
            cout << "Bateria carregada!\n";
        }
    }

    void setNome()
    {
        InputUser aux;
        this->nome = aux.inputString("Insira um novo nome para o aparelho: ");
    }

    void setMarca()
    {
        InputUser aux;
        marca = aux.inputString("Insira uma nova marca: ");
    }

    void setRAM()
    {
        InputUser aux;
        this->memoriaRAM = aux.inputInt("Insira um novo valor para memoria RAM: ");
    }

    void setMemoria()
    {
        InputUser aux;
        this->memoria = aux.inputInt("Insira um novo valor para memoria: ");
    }

    void setValor()
    {
        InputUser aux;
        *valor = aux.inputFloat("Insira um novo valor: R$");
    }

    void setValorParametro(float _valor)
    {
        *valor = _valor;
    }

    string getNome()
    { return nome;}

    string getMarca()
    { return marca;}
    
    int getRAM()
    { return memoriaRAM;}

    int getMemoria()
    { return memoria;}

    int getBateria()
    { return *bateria;}

    float getValor()
    { return *valor;}

    bool getLigar()
    { return ligar;}

};

Celular::Celular()
{
    this->nome = "";
    marca = "";
    this->memoriaRAM = 0;
    this->memoria = 0;
    bateria = new int(0);
    valor = new float(0.0);
    this->ligar = false;
}

Celular::Celular(string _nome, string _marca, int _ram, int _memoria, int _bateria, float _valor, bool _ligar)
{
    this->nome = _nome;
    marca = _marca;
    this->memoriaRAM = _ram;
    this->memoria = _memoria;
    bateria = new int;
    valor = new float;
    *bateria = _bateria;
    *valor = _valor;
    this->ligar = _ligar;
}

Celular::Celular(Celular* _celular) //esse construtor ta bugado por algum motivo AINDA VOU ARRUMAR
{
    this->nome = _celular->getNome();
    marca = _celular->getMarca();
    this->memoriaRAM = _celular->getRAM();
    this->memoria = _celular->getMemoria();
    bateria = new int;
    valor = new float;
    *bateria = _celular->getBateria();
    *valor = _celular->getValor();
    this->ligar = _celular->getLigar();
}

Celular::~Celular()
{
    delete bateria;
    delete valor;
    cout << "\n'BATERIA' e 'VALOR' foi deletada da memoria.\n";
}

class Promo
{
    static int desconto;

    public:
    void descontoCelular(Celular* _celular)
    {
        float descontoCel = _celular->getValor();
        
        if (desconto >= 0 && desconto <= 100)
        {
            descontoCel -= descontoCel * (desconto / 100.0);
            _celular->setValorParametro(descontoCel);
        }
        else
            cout << "Desconto inválido.\n";
    }

    void setDesconto()
    {
        InputUser aux;
        desconto = aux.inputInt("Novo desconto(%): ");
    }
};

class OutputAux
{
    int num_celulares = 0;

    public:
    void printCelular(Celular _celular)
    {
        cout << "\nCELULAR " << num_celulares + 1 << ":\n";
        cout << "Nome: " << _celular.getNome() << "\n";
        cout << "Marca: " << _celular.getMarca() << "\n";
        cout << "RAM: " << _celular.getRAM() << "\n";
        cout << "Memoria(GB): " << _celular.getMemoria() << "\n";
        cout << "Bateria: " << _celular.getBateria() << "\n";
        cout << "Ligado: " << _celular.getLigar() << "\n";
        cout << std::fixed << std::setprecision(2) << "VALOR: R$" << _celular.getValor() << "\n";
        num_celulares += 1;
    }
};