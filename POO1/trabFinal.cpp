//codigo por Lara Lima Silva e Gabriel Pereira Paião - IFSP, Jacareí - ADS

#include <string>
#include <iostream>

using namespace std;

// Interface para objetos que podem ser roubados
class IRoubo {
public:
    virtual void Roubar() = 0;
    virtual ~IRoubo() {}  // Adicionando um destrutor virtual para a interface
};

class Produto {
public:
    int qtnTemp;

protected:
    string categoria;
    string nome;
    float preco;
    int quantidade = 0;
    string tipoQuantidade;

    // [ ] Encapsulamento protegido
    void MostraInfo() {
        cout << "\nNome do produto: " << nome << "\nCategoria: " << categoria << "\nPreco: R$" << preco << "\nQuantidade: " << quantidade << " " << tipoQuantidade;
    }

    void FazerPedido(int qtn_pedido) {
        cout << "Fazendo pedido de " << qtn_pedido << " unidades de " << nome;
        quantidade = qtn_pedido;
        cout << "\nQuantidade atual: " << quantidade;
    }

public:
    // [ ] Ordem de construção
    Produto(string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade) : nome(Xnome), preco(Xpreco), quantidade(Xquantidade), tipoQuantidade(XtipoQuantidade) {}

    virtual void VerificaProduto() {
        if (quantidade == 0) {
            cout << "Produto indisponível";
            cout << "\nDigite quanto deseja pedir ao fornecedor: ";
            int x;
            cin >> x;
            FazerPedido(x);
        } else {
            cout << "Produto disponível\nQuantidade: " << quantidade;
        }
    }

    virtual ~Produto() {}  // Adicionando um destrutor virtual para a classe base
};

class Limpeza : public Produto {
private:
    string cheiro;

public:
    // [ ] Herança
    Limpeza(string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade, string Xcheiro) : Produto(Xnome, Xpreco, Xquantidade, XtipoQuantidade), cheiro(Xcheiro) {}

    void MostraInfoLimpeza() {
        // [ ] Reuso de código
        MostraInfo();
        cout << "\nCheiro: " << cheiro;
    }

    void VerificaProduto() override {
        Produto::VerificaProduto();
    }

    virtual ~Limpeza() {}  // Adicionando um destrutor virtual para a classe derivada
};

class Alimento : public Produto, public IRoubo {
private:
    string subcategoria;

public:
    // [ ] Herança
    Alimento(string Xnome, float Xpreco, int Xquantidade, string XtipoQuantidade, string Xsubcategoria) : Produto(Xnome, Xpreco, Xquantidade, XtipoQuantidade), subcategoria(Xsubcategoria) {}

    void MostraInfoAlimento() {
        // [ ] Reuso de código
        MostraInfo();
        cout << "\nSubcategoria: " << subcategoria;
    }

    // [ ] Interface
    // Implementação da interface IRoubo
    void Roubar() override {
        quantidade -= 1;

        cout << "\nRoubando o alimento " << nome << "...\nQuantidade após roubo: " << quantidade << " " << tipoQuantidade << "\nGerente não vai descobrir..." <<
            "\nDeseja comer o alimento agora? Digite 1 para sim e 2 para não\n";

        int ent = -1;
        while (ent == -1) {
            cin >> ent;
            if (ent == 1) {
                cout << "Comendo produto :)...";
                break;
            } else if (ent == 2) {
                cout << "Guardando alimento " << nome << " no bolso...";
                break;
            } else {
                cout << "DIGITE 1 OU 2\n";
            }
        }
    }

    // [ ] sobrescrita de métodos
    virtual ~Alimento() {}  // Adicionando um destrutor virtual para a classe derivada
};

int main() {
    cout << "\n------- GERENCIADOR DE ESTOQUE -------\n\n";

    // Criando um objeto de Alimento
    Alimento Cookies("Cookies", 5.56, 58, "unidades", "Doce");

    // Criando um ponteiro de Produto que aponta para o objeto de Alimento
    Produto* ponteiroBase = &Cookies;

    // Mostrando informações específicas de Alimento
    Cookies.MostraInfoAlimento();
    cout << "\n";

    // Criando um objeto de Limpeza
    Limpeza Cloro("Cloro", 58, 100, "caixas", "Piscina");

    // Mostrando informações específicas de Limpeza
    Cloro.MostraInfoLimpeza();
    cout << "\n";

    // [ ] uso de objetos derivados no lugar de objetos bases
    // Verificando a disponibilidade do produto de Limpeza
    Cloro.VerificaProduto();
    cout << "\n";

    // [ ] Ponteiro de classe base apontando para objeto de classe derivada
    // [ ] inclusão de método em tabela virtual
    // Chama o método Roubar diretamente, pois o ponteiroBase está apontando para um objeto de Alimento
    dynamic_cast<IRoubo*>(ponteiroBase)->Roubar();

    // Criando uma coleção de produtos (objetos de tipos diferentes) usando um array simples
    const int tamanhoEstoque = 2;
    Produto* estoque[tamanhoEstoque];

    // Alocando objetos e armazenando no array
    estoque[0] = new Alimento("Maçã", 2.5, 30, "unidades", "Fruta");
    estoque[1] = new Limpeza("Sabão em Pó", 12.99, 20, "pacotes", "Lavanderia");

    // Iterando sobre o array e chamando o método VerificaProduto
    for (int i = 0; i < tamanhoEstoque; ++i) {
        estoque[i]->VerificaProduto();
        cout << "\n";
    }

    // Liberando a memória alocada
    for (int i = 0; i < tamanhoEstoque; ++i) {
        delete estoque[i];
    }

    return 0;
}
