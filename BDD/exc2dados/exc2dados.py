class Pessoa():
    def __init__(self, _idpessoa=None, _nome=None, _idcontato=None, _idcidade=None):
        self.idpessoa = _idpessoa
        self.nome = _nome
        self.idcontato = _idcontato
        self.idcidade = _idcidade

class Cidade():
    def __init__(self, _idcidade=None, _cidade=None, _estado=None):
        self.idcidade = _idcidade
        self.cidade = _cidade
        self.estado = _estado

class Contato():
    def __init__(self, _idcontato=None, _email=None, _telefone=None):
        self.idcontato = _idcontato
        self.email = _email
        self.telefone = _telefone

def printPessoas(_listaPessoas):
    print('\n{:^40}\n{:<5}{:<15}{:<15}{:<15}'.format('PESSOAS', 'ID', 'NOME', 'ID_CONTATO', 'ID_CIDADE'))
    for pessoa in _listaPessoas:
        print('{:<5}{:<15}{:<15}{:<15}'.format(pessoa.idpessoa, pessoa.nome, pessoa.idcontato, pessoa.idcidade))

def printCidades(_listaCidades):
    print('\n{:^30}\n{:<5}{:<20}{:25}'.format('CIDADES', 'ID', 'CIDADE', 'ESTADO'))
    for cidade in _listaCidades:
        print('{:<5}{:<20}{:<25}'.format(cidade.idcidade, cidade.cidade, cidade.estado))

def printContatos(_listaContatos):
    print('\n{:^40}\n{:<5}{:<25}{:<30}'.format('CONTATOS', 'ID', 'E-MAIL', 'TELEFONE'))
    for contato in _listaContatos:
        print('{:<5}{:<25}{:<30}'.format(contato.idcontato, contato.email, contato.telefone))


#main
# Criando 5 cidades
listaCidades = [
    Cidade(1, 'São Paulo', 'SP'),
    Cidade(2, 'Rio de Janeiro', 'RJ'),
    Cidade(3, 'Belo Horizonte', 'MG'),
    Cidade(4, 'Brasília', 'DF'),
    Cidade(5, 'Salvador', 'BA')
]

listaContatos = [
    Contato(1, "joao@example.com", "123456789"),
    Contato(2, "maria@example.com", "987654321"),
    Contato(3, "pedro@example.com", "555555555"),
    Contato(4, "ana@example.com", "999999999"),
    Contato(5, "carlos@example.com", "111111111"),
    Contato(6, "julia@example.com", "222222222"),
    Contato(7, "lucas@example.com", "333333333"),
    Contato(8, "mariana@example.com", "444444444"),
    Contato(9, "fernando@example.com", "666666666"),
    Contato(10, "patricia@example.com", "777777777")
]

# Criando 10 pessoas
listaPessoas = [
    Pessoa(1, "João", 1, 1),
    Pessoa(2, "Maria", 2, 2),
    Pessoa(3, "Pedro", 3, 3),
    Pessoa(4, "Ana", 4, 4),
    Pessoa(5, "Carlos", 5, 5),
    Pessoa(6, "Julia", 6, 1),
    Pessoa(7, "Lucas", 7, 2),
    Pessoa(8, "Mariana", 8, 3),
    Pessoa(9, "Fernando", 9, 4),
    Pessoa(10, "Patrícia", 10, 5)
]

printContatos(listaContatos)
printCidades(listaCidades)
printPessoas(listaPessoas)
