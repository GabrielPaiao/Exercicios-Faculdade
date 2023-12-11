#include <string>
#include <iostream>
#include <vector>

using namespace std;

class IModificavel {
public:
    virtual void Modificar() = 0;
};

class Produto : public IModificavel {
    public:
    int qtnTemp;

    protected:
    string categoria;
    string nome;
    float preco;
    int quantidade = 0;
    string tipoQuantidade;

    Produto (string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade) : nome(Xnome), preco(Xpreco), quantidade(Xquantidade), tipoQuantidade(XtipoQuantidade){} // Construtor

    void MostraInfo(){
        cout << "\nNome do produto: "<< nome << "\nCategoria: " << categoria << "\nPreco: R$" << preco << "\nQuantidade: "<< quantidade <<" "<< tipoQuantidade;
    }

    void FazerPedido(int qtn_pedido){
        cout << "Fazendo pedido de " << qtn_pedido << "unidades de "<< nome;    // Caso não haja produtos, será possivel fazer pedido de mais
        quantidade = qtn_pedido;
        cout << "\nQuantidade atual: " << quantidade;
    }

    public:
    virtual void Roubar(){
        quantidade -= 1;
        cout <<"\n\nRoubando " << nome << "...\nQuantidade atual: " << quantidade << "\nGerente não vai descobrir...";
    }    
    
    virtual void VerificaProduto() {      // Aqui ele verifica a quantidade do produto
        if (quantidade == 0){
            cout << "Produto indisponivel";
            cout << "\nDigite quanto deseja pedir ao fornecedor: ";
            int x;
            cin >> x;
            FazerPedido(x);
        }
        else {
            cout << "Produto disponivel\nQuantidade: " << quantidade;
        } 
    }

    void Modificar() override {
        Roubar();
    }

};


class Alimento : public Produto {
    private:
    string subcategoria;

    public:
    Alimento (string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade, string Xsubcategoria) : Produto(Xnome, Xpreco, Xquantidade, XtipoQuantidade), subcategoria(Xsubcategoria){}
    
    void MostraInfoAlimento(){  // Perguntei pro GPT e essa era uma forma de acessar membros ascendetes, ai como ALimento tem uma categoria que não é de produto, então tem que colocar por fora
        MostraInfo();
        cout << "\nSubcategoria: " << subcategoria;
    }

    int ent = -1;
    void Roubar() override{
        quantidade -= 1;
        
        cout <<"\nRoubando o alimento " << nome << "...\nQuantidade após roubo: " << quantidade <<" "<< tipoQuantidade << "\nGerente não vai descobrir..." <<
        "\nDeseja comer o alimento agora? Digite 1 para sim e 2 para nao\n";

        while (ent = -1){
            cin >> ent;
            if (ent == 1){
                cout << "Comendo produto :)...";
                break;
            }
            else if (ent == 2){
                cout << "Guardando alimento " << nome << " no bolso...";
                break;
            }
            else {
                cout << "DIGITE 1 OU 2\n";
            }
        }
    }

    void Modificar() override {
        Roubar();
    }
};

void ModificarObjetos(vector<IModificavel*>& objetos) {
    for (IModificavel* objeto : objetos) {
        objeto->Modificar();
    }
}

class Limpeza : public Produto {
    private:
    string cheiro;

    public:
    Limpeza (string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade, string Xcheiro) : Produto(Xnome, Xpreco, Xquantidade, XtipoQuantidade), cheiro(Xcheiro){}             

    void MostraInfoLimpeza(){
        MostraInfo();
        cout << "\nCheiro: " << cheiro;
    }
    void VerificaProduto() override {
        Produto::VerificaProduto();
    }

};


int main(){
    cout << "\n------- GERENCIADOR DE ESTOQUE -------\n\n";
    Alimento Cookies("Cookies", 5.56, 58, "unidades", "Doce");
    Produto *ponteiroBase = &Cookies;
    Cookies.MostraInfoAlimento();
    cout<<"\n";
    Limpeza Cloro("Cloro", 58, 100, "caixas", "Piscina"); // nao tava com criatividade perdoa
    Cloro.MostraInfoLimpeza();
    cout<<"\n";
    Cloro.VerificaProduto();
    cout<<"\n";
    ponteiroBase->Roubar();
}