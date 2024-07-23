#include <iostream>
using namespace std;

// 1) Definindo a interface
class IAnimal //interface
{
    public: //TUDO em interfaces é público
        virtual void definirEspecie() const = 0;

        virtual ~IAnimal() = default; //destruidor 
};

// 2) Implementando a interface

class Gato : public IAnimal
{
    void definirEspecie() const override
    {
        cout << "Sphynx" << "\n";
    }
};

// 3) Usando no main....
int main()
{
    IAnimal* animal1 = new Gato();

    animal1->definirEspecie();

    delete animal1;

    return 0;
}