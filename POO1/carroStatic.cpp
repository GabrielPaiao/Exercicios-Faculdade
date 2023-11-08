//aprendendo sobre metodos e atributos estaticos com codigo elaborado em aulas passadas
#include <iostream>
#include <string>
using namespace std;

struct InteracaoUsuario
{
		static string texto;

    static float interage_usuario() //nao vai criar objeto nem interagir com um (logo n funciona com nada q tenha this->)
    {
        float nova_posicao;
        std::cin>>nova_posicao;
        return nova_posicao;
    }
};

struct Carro
{
    std::string marca;
    std::string cor;
    bool tipo_transmissao;
    std::string modelo;
    float posicao;
   
    void defini_posicao()
    {
        InteracaoUsuario objIU;
        this->posicao = objIU.interage_usuario();
    }
   
    Carro(float posicao_temp)
    {
        //InteracaoUsuario objIU;
        //this->posicao = objIU.interage_usuario();
        this->posicao = posicao_temp;
    }
   
    void andar(float deslocamento)
    {
        //posicao_inicial + deslocamento
        //this->posicao = this->posicao + deslocamento;
        this->posicao += deslocamento;
    }
   
    void pintar()
    {
        this->cor = "vermelho";
    }
   
    void frear();
};

int main()
{
    InteracaoUsuario objIU;
    //float posicao_temp = objIU.interage_usuario();
    float posicao_temp = objIU.interage_usuario(); //'.' ou '::'
   
    std::cout<<"Posicao: ";
    Carro c1(posicao_temp);
    //c1.defini_posicao();
    std::cout<<"andar() 1: c1.posicao = "<<c1.posicao<<"\n";
   
    c1.andar(3.0f);
    std::cout<<"andar() 2: c1.posicao = "<<c1.posicao;
   
    c1.pintar();
   
    posicao_temp = objIU.interage_usuario();
    Carro c2(posicao_temp);

	//string InteracaoUsuario::texto = "exemplo\n"; //texto é um atributo estatico, que pode ser alterado dessas duas formas:
	objIU.texto = "mudei pq eu posso rs";

    return 0;
}