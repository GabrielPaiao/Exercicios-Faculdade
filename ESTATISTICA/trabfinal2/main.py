#Código por: Gabriel Pereira Paião

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Carregar o arquivo CSV com o novo caminho e delimitador
df = pd.read_csv(r'C:\coding\repositorios_git\Exercicios-Faculdade\ESTATISTICA\trabfinal2\ca-2004-01.csv', delimiter=';', skipinitialspace=True)

# Converter colunas de valores monetários para numérico
df['Valor de Venda'] = df['Valor de Venda'].str.replace(',', '.').astype(float)
df['Valor de Compra'] = df['Valor de Compra'].str.replace(',', '.').astype(float)

# Mostrar as primeiras linhas do DataFrame
print("Primeiras linhas do DataFrame:")
print(df.head())

# Resumo estatístico dos dados numéricos
print("\nResumo estatístico dos dados numéricos:")
df_num = df[['Valor de Venda', 'Valor de Compra']]
df_num_desc = df_num.describe()

# Formatar os valores com duas casas decimais
df_num_desc_formatted = df_num_desc.applymap(lambda x: f"{x:,.2f}")
print(df_num_desc_formatted)

# Resumo estatístico das colunas categóricas
print("\nResumo estatístico das colunas categóricas:")
for column in df.select_dtypes(include=['object']).columns:
    print(f"\n{column}:")
    print(df[column].value_counts())
    print("\n" + "="*40)

print("\nInformações sobre os dados:")
print(df.info())

# Tabelas de frequência para variáveis categóricas
def print_frequency(title, series):
    print("\n" + title + ":")
    print(series.to_frame().reset_index().rename(columns={'index': title.split()[0], title.split()[0]: 'Frequência'}))
    print("\n" + "="*40)

print_frequency("Frequência dos Produtos", df['Produto'].value_counts())
print_frequency("Frequência das Regiões", df['Regiao - Sigla'].value_counts())
print_frequency("Frequência dos Estados", df['Estado - Sigla'].value_counts())
print_frequency("Frequência das Bandeiras", df['Bandeira'].value_counts())

# Gráfico de barras para Produtos
plt.figure(figsize=(10,6))
sns.countplot(y='Produto', data=df, order=df['Produto'].value_counts().index)
plt.title('Distribuição dos Produtos')
plt.show()

# Gráfico de pizza para Regiões
plt.figure(figsize=(8,8))
df['Regiao - Sigla'].value_counts().plot.pie(autopct='%1.1f%%', startangle=140)
plt.title('Distribuição das Regiões')
plt.ylabel('')
plt.show()

# Gráfico de barras para Bandeiras
limite = 1000  # Exemplo: limite de 1000 ocorrências para serem consideradas como "Outros"
bandeira_counts = df['Bandeira'].value_counts()
df['Bandeira Agrupada'] = df['Bandeira'].apply(lambda x: x if bandeira_counts[x] > limite else 'Outros')

# Plotar o gráfico de barras
plt.figure(figsize=(14,8))
sns.countplot(x='Bandeira Agrupada', data=df, order=df['Bandeira Agrupada'].value_counts().index)
plt.xticks(rotation=45, ha='right')
plt.title('Distribuição das Bandeiras (Agrupadas)')
plt.tight_layout()
plt.show()

# Medidas de Tendência Central para os preços de venda e compra
print("\nMedidas de tendência central para os preços de venda e compra:")
print("\nMédia de Venda:")
print(f"{df['Valor de Venda'].mean():,.2f}")

print("\nMediana de Venda:")
print(f"{df['Valor de Venda'].median():,.2f}")

print("\nModa de Venda:")
print(f"{df['Valor de Venda'].mode()[0]:,.2f}")

print("\nDesvio Padrão de Venda:")
print(f"{df['Valor de Venda'].std():,.2f}")

print("\nMédia de Compra:")
print(f"{df['Valor de Compra'].mean():,.2f}")

print("\nMediana de Compra:")
print(f"{df['Valor de Compra'].median():,.2f}")

print("\nModa de Compra:")
print(f"{df['Valor de Compra'].mode()[0]:,.2f}")

print("\nDesvio Padrão de Compra:")
print(f"{df['Valor de Compra'].std():,.2f}")
