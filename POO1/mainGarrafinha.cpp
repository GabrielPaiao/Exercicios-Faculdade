#include <iostream>
#include <string>
#include "classeGarrafinha.h"
using namespace std;

string Garrafinha::marca = "";
float Garrafinha::capacidade = 0;
float Promo::desconto_share = 0;

class OutputClasse
{
    public:
    static void imprimeGarrafinha(string _marca, float _capacidade, float _valor, bool _cheia, string _cor, int _id)
    {
        cout << "GARRAFINHA: \n";
        cout << "MARCA: " << _marca << "\nCAPACIDADE: " << _capacidade << "\nVALOR: R$" << _valor << "\nCHEIA? " << _cheia << "\nCOR: " << _cor << "\nID: " << _id << "\n";
    }
};

int main()
{
    Garrafinha garrafa1;
    OutputClasse aux_output;
    Promo promocao;

    aux_output.imprimeGarrafinha(garrafa1.getMarca(), garrafa1.getCapacidade(), garrafa1.getValor(), garrafa1.getCheia(), garrafa1.getCor(), garrafa1.getId());
    Garrafinha::definirMarca(); //Para chamar metodos estaticos, vc chama a classe, nao um objeto
    Garrafinha::definirCapacidade();
    garrafa1.encherGarrafinha();
    garrafa1.mudarValor();
    garrafa1.mudarCor();
    garrafa1.mudarId();
    aux_output.imprimeGarrafinha(garrafa1.getMarca(), garrafa1.getCapacidade(), garrafa1.getValor(), garrafa1.getCheia(), garrafa1.getCor(), garrafa1.getId());
    
    promocao.mudarDesconto();
    garrafa1.mudarValor_p(promocao.descontoValor(garrafa1));
    cout << "\nNovo valor garrafa1: " << garrafa1.getValor() << "\n";

    Garrafinha garrafa2(&garrafa1);
    cout << "COPIA GARRAFA 1:\n";
    aux_output.imprimeGarrafinha(garrafa2.getMarca(), garrafa2.getCapacidade(), garrafa2.getValor(), garrafa2.getCheia(), garrafa2.getCor(), garrafa2.getId());

    return 0;
}