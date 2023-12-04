from scipy.optimize import minimize
import math

def custo_material(dimensoes, custo_base, custo_lateral):
    """
    Função que calcula o custo total com base nas dimensões fornecidas.

    Parametros:
        dimensoes (list): Lista com as dimensões [raio, altura].
        custo_base (float): Custo do material da base em R$ por cm^2.
        custo_lateral (float): Custo do material da lateral em R$ por cm^2.

    Retorna:
        float: Custo total do material.
    """
    raio, altura = dimensoes
    area_base = math.pi * raio**2
    area_lateral = 2 * math.pi * raio * altura

    custo_total_base = custo_base * area_base
    custo_total_lateral = custo_lateral * area_lateral
    custo_total = custo_total_base + custo_total_lateral

    return custo_total

def volume_restricao(dimensoes, volume):
    """
    Função de restrição para garantir que o volume seja alcançado.

    Parametros:
        dimensoes (list): Lista com as dimensões [raio, altura].
        volume (float): Volume desejado em ml.

    Retorna:
        float: Diferença entre o volume calculado e o desejado.
    """
    raio, altura = dimensoes
    return math.pi * raio**2 * altura - volume

def obter_inputs_usuario():
    """
    Função para obter inputs do usuário.

    Retorna:
        tuple: Tupla contendo (volume, tampa, custo_base, custo_lateral).
    """
    volume = 0
    tampa = ""
    custo_base = -1
    custo_lateral = -1

    while volume <= 0:
        volume = float(input("Informe o volume desejado (em ml): "))
        if volume <=0:
            print('Por favor, insira um número > 0.')

    while tampa.upper() != 'S' and tampa.upper() != 'N':
        tampa = str(input("A embalagem terá tampa? (S ou N): ")).strip()
        if tampa.upper() != 'S' and tampa.upper() != 'N':
            print('Por favor, insira uma entrada válida. [S/N]')

    while custo_base < 0:
        custo_base = float(input("Informe o custo do material da base (R$ por cm^2): "))
        if custo_base < 0:
            print('Por favor, insira um valor >= 0.')
    
    while custo_lateral < 0:
        custo_lateral = float(input("Informe o custo do material da lateral (R$ por cm^2): "))
        if custo_lateral < 0:
            print('Por favor, insira um valor >= 0.')

    return volume, tampa, custo_base, custo_lateral

# Função de minimização
def otimizar_custo(volume, tampa, custo_base, custo_lateral):
    """
    Função que otimiza as dimensões para minimizar o custo total.

    Parametros:
        volume (float): Volume desejado em ml.
        tampa (bool): Indica se a embalagem terá tampa.
        custo_base (float): Custo do material da base em R$ por cm^2.
        custo_lateral (float): Custo do material da lateral em R$ por cm^2.

    Retorna:
        tuple: Tupla contendo (dimensoes_otimizadas, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado).
    """
    if tampa:
        restricao_volume = {'type': 'eq', 'fun': volume_restricao, 'args': (volume - 375 * math.pi,)}
    else:
        restricao_volume = {'type': 'eq', 'fun': volume_restricao, 'args': (volume,)}

    resultado = minimize(custo_material, [1, 1], args=(custo_base, custo_lateral),
                         constraints=restricao_volume)

    dimensoes_otimizadas = resultado.x
    custo_base_otimizado = custo_base * math.pi * dimensoes_otimizadas[0]**2
    custo_lateral_otimizado = custo_lateral * 2 * math.pi * dimensoes_otimizadas[0] * dimensoes_otimizadas[1]
    custo_total_otimizado = custo_base_otimizado + custo_lateral_otimizado

    return dimensoes_otimizadas, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado


#MAIN
# Obter inputs do usuário
volume, tampa, custo_base, custo_lateral = obter_inputs_usuario()

# Calcular dimensões otimizadas e custos
dimensoes_otimizadas, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado = otimizar_custo(volume, tampa, custo_base, custo_lateral)

# Imprimir resultados
print("""RESULTADOS:
      Dimensões Otimizadas: {}
      Custo total da base otimizado: {}
      Cuso total da lateral otimizado: {}
      Custo total otimizado: {}""" .format(dimensoes_otimizadas, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado))
