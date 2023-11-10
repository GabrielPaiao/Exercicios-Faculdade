#include <iostream>
#include <string>
#include "classeCelular.h"
using namespace std;

string Celular::marca = "";
int Promo::desconto = 0;

int main()
{
    Celular celular1;
    Celular celular2("Galaxy M52", "Samsung", 8, 148, 100, 2500, true);
    Celular celular3(celular2);
    Promo aux_promo;
    OutputAux aux_out;

    aux_out.printCelular(celular1);
    aux_out.printCelular(celular2);
    aux_out.printCelular(celular3);

    cout << "Redefinindo celular1....\n";
    celular1.setNome();
    celular1.setMarca();
    celular1.setRAM();
    celular1.setMemoria();
    celular1.setValor();
    celular1.carregarBateria(); // Carregar a bateria depois de definir o valor

    aux_out.printCelular(celular1);
    cout << "Marca celular2: " << celular2.getMarca() << "\n";

    aux_promo.setDesconto();

    aux_promo.descontoCelular(&celular3); // Aplica desconto no celular 3
    aux_out.printCelular(celular3); // Imprime o celular 3 com desconto aplicado

    aux_promo.descontoCelular(&celular1); // Aplica desconto no celular 1
    aux_out.printCelular(celular1); // Imprime o celular 1 com desconto aplicado

    return 0;
}