import math

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
        if volume <= 0:
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

def otimizar_custo(volume, custo_base, custo_lateral):
    # Converter volume para cm³
    volume_cm3 = volume

    # Inicializar valores otimizados
    r_otimizado = 0
    h_otimizado = 0
    custo_total_otimizado = float('inf')  # Inicializar com infinito

    # Testar diferentes valores de raio
    for r_candidate in range(1, 101):  # Testar r de 1 a 100 cm
        h_candidate = volume_cm3 / (math.pi * r_candidate**2)

        # Calcular área da base
        area_base = math.pi * r_candidate**2

        # Calcular área lateral
        area_lateral = 2 * math.pi * r_candidate * h_candidate

        # Calcular custo total da base
        custo_base_otimizado = custo_base * area_base

        # Calcular custo total da lateral
        custo_lateral_otimizado = custo_lateral * area_lateral

        # Calcular custo total
        custo_total_candidate = custo_base_otimizado + custo_lateral_otimizado

        # Atualizar valores otimizados se necessário
        if custo_total_candidate < custo_total_otimizado:
            r_otimizado = r_candidate
            h_otimizado = h_candidate
            custo_total_otimizado = custo_total_candidate

    # Recalcular as áreas e custos usando os valores otimizados
    area_base_otimizada = math.pi * r_otimizado**2
    area_lateral_otimizada = 2 * math.pi * r_otimizado * h_otimizado
    custo_base_otimizado = custo_base * area_base_otimizada
    custo_lateral_otimizado = custo_lateral * area_lateral_otimizada
    custo_total_otimizado = custo_base_otimizado + custo_lateral_otimizado

    return r_otimizado, h_otimizado, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado


# MAIN
# Obter inputs do usuário
inputUser = obter_inputs_usuario()
volume = inputUser[0]
tampa = inputUser[1]
custo_base = inputUser[2]
custo_lateral =  inputUser[3]

# Otimizar custo
r_otimizado, h_otimizado, custo_base_otimizado, custo_lateral_otimizado, custo_total_otimizado = otimizar_custo(volume, custo_base, custo_lateral)

# Imprimir resultados
print(f"""RESULTADOS:
      Raio otimizado: {r_otimizado:.2f} cm
      Altura otimizada: {h_otimizado:.2f} cm
      Custo total da base otimizado: R${custo_base_otimizado:.2f}
      Custo total da lateral otimizado: R${custo_lateral_otimizado:.2f}
      Custo total otimizado: R${custo_total_otimizado:.2f}""")
