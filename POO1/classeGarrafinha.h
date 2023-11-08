#include <iostream>
#include <string>

using namespace std;

class InputUsuario
{
    public:
        string entradaString(string textoEntrada)
        {
            string texto;
            cout << textoEntrada;
            cin >> texto;
            return texto;
        }

        int entradaInt(string textoEntrada)
        {
            int valor;
            cout << textoEntrada;
            cin >> valor;
            return valor;
        }

        float entradaFloat(string textoEntrada)
        {
            float valor;
            cout << textoEntrada;
            cin >> valor;
            return valor;
        }
};

class Garrafinha
{
private:
    static string marca;
    static float capacidade;
    float valor;
    bool cheia;
    string cor;
    int *id;

public:
    Garrafinha();
    Garrafinha(string _marca, bool _cheia, float _capacidade, float _valor, string _cor, int _id);
    Garrafinha(Garrafinha* _garrafa); //CONSTRUTOR DE COPIA
    ~Garrafinha();
    static void definirMarca()
    {
        InputUsuario input;
        string aux;
        marca = input.entradaString("Marca: ");
        cout << "Marca alterada!\n";
    }

    static void definirCapacidade()
    {
        InputUsuario input;
        capacidade = input.entradaFloat("Capacidade: ");
        cout << "Capacidade alterada!\n";
    }

    void encherGarrafinha()
    {
        cheia = true;
    }

    void mudarValor()
    {
        InputUsuario input;
        valor = input.entradaFloat("Valor: R$");
        cout << "Valor alterado!\n";
    }

    void mudarValor_p(float _valor)
    {
        valor = _valor;
        cout << "Valor alterado!\n";
    }

    void mudarCor()
    {
        InputUsuario input;
        cor  = input.entradaString("Cor: ");
        cout << "Cor alterada!\n";
    }

    void mudarId()
    {
        InputUsuario input;
        *id = input.entradaInt("ID: ");
        cout << "ID alterada!\n";
    }

    string getMarca()
    { return marca; }

    float getCapacidade()
    { return capacidade; }

    float getValor()
    { return valor; }

    bool getCheia()
    { return cheia; }

    string getCor()
    { return cor; }

    int getId()
    { return *id; }

};
    //CONSTRUTORES
    Garrafinha::Garrafinha()
    {
        marca = "";
        cheia = false;
        capacidade = 0;
        valor = 0;
        cor = "";
        id = new int;
        *id = 0;
    }

    Garrafinha::Garrafinha(string _marca, bool _cheia, float _capacidade, float _valor, string _cor, int _id)
    {
        marca = _marca;
        cheia = _cheia;
        capacidade = _capacidade;
        valor = _valor;
        cor = _cor;
        *id = _id;
    }

    Garrafinha::Garrafinha(Garrafinha* _garrafa)
    {
        marca = _garrafa->marca;
        cheia = _garrafa->cheia;
        capacidade = _garrafa->capacidade;
        valor = _garrafa->valor;
        cor = _garrafa->cor;
        id = _garrafa->id;
    }

    Garrafinha::~Garrafinha()
    {
        delete id;
        cout << "Objeto destruido.\n";
    }

class Promo
{
    int *desconto; //porcentagem do desconto
    float static desconto_share;
    
    public:
    Promo()
    {
        desconto = new int;
        *desconto = 0;
        desconto_share = 0;
    }

    Promo(int _porcentagem)
    {
        desconto = new int;
        *desconto = _porcentagem;
        desconto_share = _porcentagem;
    }

    ~Promo()
    {
        delete desconto;
        cout << "Objeto PROMO destruido.\n";
    }

    void mudarDesconto()
    {
        InputUsuario input;
        *desconto = input.entradaInt("Novo Desconto (%): ");
        desconto_share = *desconto;
        cout << "Desconto alterado!\n";
    }

    float descontoValor(Garrafinha _garrafa)
    {
        float novo_valor;
        novo_valor = _garrafa.getValor() - (_garrafa.getValor() * (desconto_share / 100));
        return novo_valor;
    }

};