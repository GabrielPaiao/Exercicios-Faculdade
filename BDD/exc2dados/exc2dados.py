class Pessoa():
    def __init__(self, _idpessoa=None, _nome=None, _telefone=None, _email=None, _idcidade=None):
        self.idpessoa = _idpessoa
        self.nome = _nome
        self.telefone = _telefone
        self.email = _email
        self.idcidade = _idcidade

class Cidade():
    def __init__(self, _idcidade=None, _cidade=None, _estado=None):
        self.idcidade = _idcidade
        self.cidade = _cidade
        self.estado = _estado

def printPessoas(_listaPessoas):
    print('{:^65}\n{:<5}{:<15}{:<15}{:<25}{:<15}'.format('PESSOAS', 'ID', 'NOME', 'TELEFONE', 'E-MAIL', 'ID_CIDADE'))
    for pessoa in _listaPessoas:
        print('{:<5}{:<15}{:<15}{:<25}{:<15}'.format(pessoa.idpessoa, pessoa.nome, pessoa.telefone, pessoa.email, pessoa.idcidade))

#main
# Criando 5 cidades
listaCidades = [
    Cidade(1, 'São Paulo', 'SP'),
    Cidade(2, 'Rio de Janeiro', 'RJ'),
    Cidade(3, 'Belo Horizonte', 'MG'),
    Cidade(4, 'Brasília', 'DF'),
    Cidade(5, 'Salvador', 'BA')
]

# Criando 10 pessoas
listaPessoas = [
    Pessoa(1, 'João', '123456789', 'joao@email.com', 1),
    Pessoa(2, 'Maria', '987654321', 'maria@email.com', 2),
    Pessoa(3, 'Pedro', '555555555', 'pedro@email.com', 1),
    Pessoa(4, 'Ana', '999999999', 'ana@email.com', 3),
    Pessoa(5, 'Carlos', '111111111', 'carlos@email.com', 2),
    Pessoa(6, 'Julia', '222222222', 'julia@email.com', 1),
    Pessoa(7, 'Lucas', '333333333', 'lucas@email.com', 4),
    Pessoa(8, 'Mariana', '444444444', 'mariana@email.com', 3),
    Pessoa(9, 'Fernando', '666666666', 'fernando@email.com', 5),
    Pessoa(10, 'Patrícia', '777777777', 'patricia@email.com', 4)
]

printPessoas(listaPessoas)
