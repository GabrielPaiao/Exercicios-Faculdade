'''
Código por: Gabriel Pereira Paião, ADS, Banco de Dados

Como solicitado:
Implemente uma tabela Aluno com os atributos id, nome e idade;
Implemente a operação de inserção de dados e popule a tabela com 10 registros; e
Implemente a recuperação de informação por meio do id do aluno.
'''

class Aluno():
    def __init__(self):
        self.id = None
        self.nome = None
        self.idade = None

    def registrarAluno(self):
        self.id = int(input('Qual o id do aluno?(5 dígitos) '))
        self.nome = str(input('Qual o nome do aluno? '))
        self.idade = int(input('Qual a idade do aluno? '))

    def buscaPorId(self, lista_alunos):
        buscaId = int(input('\nQual ID você procura? '))
        for aluno in lista_alunos:
            if aluno.id == buscaId:
                print(f'Dados do aluno de id {aluno.id}:\nNOME: {aluno.nome}\nIDADE: {aluno.idade}')


#main
objAluno = Aluno()
bancoAlunos = []
escolha = 'S'
while escolha != 'N': #registrar quantos alunos quiser
    escolha = str(input('Gostaria de registrar um aluno?[S/N] ')).strip().upper()
    if escolha == 'S':
        objAluno.registrarAluno()
        bancoAlunos.append(objAluno)

#impressão da tabela
print('{:<10}{:<15}{:<5}'.format('ID', 'NOME', 'IDADE'))
for aluno in bancoAlunos:
    print('{:<10}{:<15}{:<5}'.format(aluno.id, aluno.nome, aluno.idade))

#busca por ID, ocorre uma vez, mas poderia facilmente ser adaptada para N vezes
objAluno.buscaPorId(bancoAlunos)

#fim
print('Obrigado por usar o programa :)')
