#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IDispositivosDeExibicao //interface das visões, no caso do exemplo, dispositivos
{
    public:
    virtual void atualiza() = 0;
    virtual ~IDispositivosDeExibicao() {};
};

class Temperatura //basciamente guarda os objetos(dispositivos) criados, no caso, os objetos de TermometroAnalogico e TermometroDigital
{
    private:
    vector<IDispositivosDeExibicao*> dispositivos;
    
    public:
    void addDispositivo(IDispositivosDeExibicao* _dispositivo)
    {
        this->dispositivos.push_back(_dispositivo);
    };
    
    void removeDispositivo(int _indiceDispositivo)
    {
        this->dispositivos.erase(this->dispositivos.begin() + _indiceDispositivo);
    };
    
    void notifica() //funcao responsavel por atualizar o valor em todos os dispositivos/visões
    {
        for (int dispositivo = 0; dispositivo < this->dispositivos.size(); dispositivo++)
        {
            this->dispositivos[dispositivo]->atualiza();
        }
    };
};

class Dados : public Temperatura //formato das visões/dispositivos, os sets dessa classe vão chamar a função "notifica", para que possamos atualizar o valor de todas as demais visões
{
    private:
    float temperaturaCelsius;
    float temperaturaFahrenheit;
    
    public:
    Dados() //construtor
    {
        this->temperaturaCelsius = 0.0;
        this->temperaturaFahrenheit = 0.0;
    }
    
    ~Dados() {} //destrutor
    
    const float getTemperaturaCelsius() { return this->temperaturaCelsius; }
    const float getTemperaturaFahrenheit() { return this->temperaturaFahrenheit; }
    
    void setTemperaturaCelsius(float _valor)
    {
        this->temperaturaCelsius = _valor;
        this->notifica();
    }
    
    void setTemperaturaFahrenheit(float _valor)
    {
        this->temperaturaFahrenheit = _valor;
        this->notifica();
    }
};

class TermometroDigital : public IDispositivosDeExibicao //Nossa primeira visão/dispositivo;
{
    private:
    vector<float> temperatura; //vao receber a temperatura em F e C
    Dados* fonteDados;
    
    public:
    TermometroDigital(Dados* _dado)
    {
        this->fonteDados = _dado;
        fonteDados->addDispositivo(this);
    }
    
    ~TermometroDigital() {};
    
    void const printTemperatura()
    {
      cout << "Temperatura no termo. Digital: " << this->temperatura[0] << "C /" << this->temperatura[1] << "F" <<"\n\n"; 
    }
    
    void atualiza() override
    {
        this->temperatura.clear();
        this->temperatura.push_back(fonteDados->getTemperaturaCelsius());
        this->temperatura.push_back(fonteDados->getTemperaturaFahrenheit());
    }
};

class TermometroAnalogico : public IDispositivosDeExibicao //Segunda e última visão/dispositivo
{
    private:
    float temperatura;
    Dados* fonteDados;
    
    public:
    TermometroAnalogico(Dados* _dado)
    {
        this->fonteDados = _dado;
        fonteDados->addDispositivo(this);
    }
    
    ~TermometroAnalogico() {}
    
    const void printTemperatura()
    {
        cout << "Temperatura analogica: " << this->temperatura << "C\n\n";
    }
    
    void atualiza() override
    {
        this->temperatura = fonteDados->getTemperaturaCelsius();
    }
};


int main()
{
    Dados* dado1 = new Dados();
    TermometroDigital* termometro1 = new TermometroDigital(dado1);
    TermometroAnalogico* termometro2 = new TermometroAnalogico(dado1);
    
    dado1->setTemperaturaFahrenheit(62.0);
    dado1->setTemperaturaCelsius(17.0);
    
    termometro1->printTemperatura();
    termometro2->printTemperatura();

    return 0;
}