#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IInvestors
{
public:
    virtual void update() = 0;

    virtual ~IInvestors() // Torne o destrutor virtual
    {
        cout << "CLASS IINVESTORS - Destructor called\n\n";
    }
};

class Shares // Não herda de IInvestors
{
private:
    vector<IInvestors*> investors;

public:
    void addInvestor(IInvestors* _investor)
    {
        this->investors.push_back(_investor);
        cout << "CLASS SHARES - Adding '" << _investor << "' investor\n\n";
    }

    void removeInvestor(int _index)
    {
        if (_index >= 0 && _index < investors.size())
        {
            IInvestors* investorToRemove = this->investors[_index];
            this->investors.erase(this->investors.begin() + _index);
            cout << "CLASS SHARES - Removing '" << investorToRemove << "'(index: " << _index << ") investor\n\n";
        }
        else
        {
            cout << "Index out of range.\n\n";
        }
    }

    void notify()
    {
        for (IInvestors* investor : this->investors)
        {
            investor->update();
            cout << "CLASS SHARES - Updating " << investor << " object\n\n";
        }
    }
};

class Data : public Shares
{
private:
    float share;

public:
    Data()
    {
        this->share = 0.0;
        cout << "CLASS DATA - Constructor called\n\n";
    }

    const float getShare()
    {
        return this->share;
    }

    void setShare(float _value)
    {
        this->share = _value;
        this->notify();
        cout << "CLASS DATA - Updating 'share' attribute and notifying investors\n\n";
    }

    ~Data()
    {
        cout << "CLASS DATA - Destructor called\n\n";
    }
};

class Investor : public IInvestors
{
private:
    float shareValue;
    Data* data;

public:
    Investor(Data* _data)
    {
        this->data = _data;
        this->shareValue = 0.0;
        _data->addInvestor(this);
        cout << "CLASS INVESTOR - Constructor called\n\n";
    }

    void update() override
    {
        this->shareValue = data->getShare();
        cout << "CLASS INVESTOR - Updating shareValue value\n\n";
    }

    const void printShareValue()
    {
        cout << "CLASS INVESTOR - shareValue: " << this->shareValue << "\n\n";
    }

    ~Investor()
    {
        cout << "CLASS INVESTOR - Destructor called\n\n";
    }
};

class Consultor : public IInvestors
{
private:
    float shareValue;
    Data* data;

public:
    Consultor(Data* _data)
    {
        this->data = _data;
        this->shareValue = 0.0;
        _data->addInvestor(this);
        cout << "CLASS CONSULTOR - Constructor called\n\n";
    }

    void update() override
    {
        this->shareValue = data->getShare();
        cout << "CLASS CONSULTOR - Updating shareValue value\n\n";
    }

    const void printShareValue()
    {
        cout << "CLASS CONSULTOR - shareValue: " << this->shareValue << "\n\n";
    }

    ~Consultor()
    {
        cout << "CLASS CONSULTOR - Destructor called\n\n";
    }
};

int main()
{
    Data* dataBase = new Data();
    Investor* investor1 = new Investor(dataBase);
    Consultor* consultor1 = new Consultor(dataBase);

    dataBase->setShare(10.15);

    investor1->printShareValue();
    consultor1->printShareValue();

    delete dataBase;
    delete investor1;
    delete consultor1;

    return 0;
}
