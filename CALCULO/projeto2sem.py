from math import pi, cbrt #exc. 8 - Gabriel Pereira Paião, ADS

def obter_inputs_usuario():
    """
    Função para obter inputs do usuário.

    Retorna:
        tuple: Tupla contendo (volume, tampa, custo_base, custo_lateral).
    """
    volume = 0
    tampa = 0
    custo_base = -1
    custo_lateral = -1

    while volume <= 0:
        volume = float(input("Informe o volume desejado (em ml): "))
        if volume <= 0:
            print('Por favor, insira um número > 0.')

    while True: #proteção diferente para funcionar com tipos invalidos
        try:
            tampa = int(input('[1] SEM TAMPA\n[2] COM TAMPA\nSua escolha: '))
        except ValueError:
            print('Por favor, digite 1 ou 0, apenas.')
            continue

        if tampa not in (1, 2):
            print('Por favor, digite 1 ou 0, apenas.')
            continue

        break

    while custo_base < 0:
        custo_base = float(input("Informe o custo do material da base (R$ por cm^2): "))
        if custo_base < 0:
            print('Por favor, insira um valor >= 0.')

    while custo_lateral < 0:
        custo_lateral = float(input("Informe o custo do material da lateral (R$ por cm^2): "))
        if custo_lateral < 0:
            print('Por favor, insira um valor >= 0.')

    return volume, tampa, custo_base, custo_lateral

#formulas e definições de relações / derivação
def raio(V, Cl, Cb, t):
    return cbrt((V * Cl) / (Cb * pi * t))

def altura(V, r):
    return V / (pi*r**2)

def custoBase(Cb, r, t):
    return (Cb * pi * r**2) * t

def custoLateral(Cl, r, h):
    return Cl * 2 * pi * r * h

def custoTotal(cb, cl):
    return cb + cl


# MAIN
# Obter inputs do usuário
inputUser = obter_inputs_usuario()
volume = inputUser[0]
tampa = inputUser[1]
custo_base = inputUser[2]
custo_lateral = inputUser[3]

# Otimizar custo
#Passagem de parâmetros e obtenção de valores
raio = raio(volume, custo_lateral, custo_base, tampa)
altura = altura(volume, raio)
custoB = custoBase(custo_base, raio, tampa)
custoL = custoLateral(custo_lateral, raio, altura)
custoT = custoTotal(custoB, custoL)

# Imprimir resultados
print(f"""RESULTADOS:
      Raio otimizado: {raio:.2f} cm
      Altura otimizada: {altura:.2f} cm
      Custo total da base otimizado: R${custoB:.2f}
      Custo total da lateral otimizado: R${custoL:.2f}
      Custo total otimizado: R${custoT:.2f}""")
