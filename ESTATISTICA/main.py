#CÓDIGO POR: GABRIEL PEREIRA PAIÃO;

import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

# Parâmetros da distribuição normal
mu = 10    # Média
sigma = 1  # Desvio padrão

# Função representativa da distribuição normal
def normal_distribution(x, mu, sigma):
    return norm.pdf(x, mu, sigma)

# Cálculo da probabilidade para o intervalo [a, b]
def calculate_probability(a, b, mu, sigma):
    prob = norm.cdf(b, mu, sigma) - norm.cdf(a, mu, sigma)
    return prob

# Intervalos definidos pelo usuário
a = float(input("Digite o valor inicial do intervalo (a): "))
b = float(input("Digite o valor final do intervalo (b): "))

# Cálculo da probabilidade
probability = calculate_probability(a, b, mu, sigma)
print(f"A probabilidade de que X esteja entre {a} e {b} é {probability:.4f}")

# Desenhar a distribuição normal e a área da probabilidade
x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)
y = normal_distribution(x, mu, sigma)

# Gráfico da distribuição normal
plt.plot(x, y, label='Distribuição Normal')

# Área de probabilidade
x_fill = np.linspace(a, b, 1000)
y_fill = normal_distribution(x_fill, mu, sigma)
plt.fill_between(x_fill, y_fill, color='skyblue', alpha=0.5, label=f'Área entre {a} e {b}')

# Configurações do gráfico
plt.title('Distribuição Normal')
plt.xlabel('Valor')
plt.ylabel('Densidade de Probabilidade')
plt.legend()
plt.show()
