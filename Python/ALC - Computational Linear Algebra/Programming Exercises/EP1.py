#!/usr/bin/env python
# coding: utf-8

# # Exercício de Programação 1
# 
# 2020.2 Álgebra Linear Computacional - DCC - UFMG

# **Nome do aluno:** Rodrigo Ferreira Araújo
# 
# **Matricula:** 2020006990

# ### Questão 1
# 
# Dadas as matrizes $A$, $B$ e o vetor $C$:
# 
# $$
# A = \begin{bmatrix}
#  2 & 1 & 3\\
#  3 & 1 & 4\\
#  5 & 7 & 12
# \end{bmatrix}_{3\times 3}
# \qquad
# B = \begin{bmatrix}
#  1 & 0 & 0\\
#  0 & 1 & 0\\
#  0 & 0 & 1
# \end{bmatrix}_{3\times 3}
# \qquad
# C = \begin{bmatrix}
#  3 \\
#  1 \\
#  2
# \end{bmatrix}_{3\times 1}
# $$
# 
# Gere as matrizes D, E e o vetor F tal que:
# 
# $$
# D = A B \\
# E = A^\top + B\\
# F = A  C
# $$
# 
# *Dicas:*
# * *Imprima ```A.shape, B.shape, C.shape``` e confira se as dimensões de suas matrizes batem com a descrição do enunciado.*
# * As operações de produto e transposição estão definidas na documentação da biblioteca ```numpy```.

# In[203]:


# Código para Exercício 1
import numpy as np
A = np.array([[2,1,3],[3,1,4],[5,7,12]])
B = np.array([[1,0,0],[0,1,0],[0,0,1]])
C = np.array([[3],[1],[2]])

D = np.matmul(A,B)
E = A.transpose() + B
F = np.matmul(A,C)

print(A.shape)
print(B.shape)
print(C.shape)
#print(A.transpose())

print(D)
print(E)
print(F)


# ### Questão 2
# 

# 
# #### Questão 2.1
# 
# Uma forma de representar um vetor no espaço é através de um ponto localizado na extremidade da "seta" do vetor. Essa representação é especialmente útil quando queremos vizualizar uma grande quantidade de vetores. Crie um array chamado `dados`, de tamanho $n \times 2$, em que cada linha represente um dos seguintes vetores de tamanho 2:
# 
# - $(\ 0.7,\ 0.7\ )$
# - $(\ 0.0,\ 1.0\ )$
# - $(\ -0.7,\ 0.7\ )$
# - $(\ -1.0,\ 0.0\ )$
# - $(\ -0.7,\ -0.7\ )$
# - $(\ 0.0,\ -1.0\ )$
# - $(\ 0.7,\ -0.7\ )$
# - $(\ 1.0,\ 0.0\ )$
# 
# 
# Você pode achar a documentação do [`np.array`](https://numpy.org/doc/stable/reference/generated/numpy.array.html) útil.

# In[204]:


# Código para Exercício 2.1
import numpy as np
#np.array([[0.7,0.7], [0.0,1.0], [-0.7,0.7], [-1.0,0.0], [-0.7,-0.7], [0,0,-1.0], [0.7,-0.7], [1.0,0.0]])
dados = np.array(np.mat('0.7 0.7; 0.0 1.0; -0.7 0.7; -1.0 0.0; -0.7 -0.7; 0.0 -1.0; 0.7 -0.7; 1.0 0.0'))
print(dados)


# #### Questão 2.2
# 
# Vamos agora visualizar esses pontos no espaço 2D. Para isso, podemos usar a biblioteca [`matplotlib`](https://matplotlib.org/). Agora, com as coordenadas $x$ e $y$ dos pontos do exercício anterior, crie um gráfico de dispersão que mostre cada ponto no plano. Voce pode achar a documentação de [`plt.scatter`](https://matplotlib.org/3.1.0/api/_as_gen/matplotlib.pyplot.scatter.html) útil, além da dica que para escolher a coluna $i$ de um array bi-dimensional usamos `x[:, i]` (consulte essa página sobre [indexing](https://numpy.org/doc/stable/reference/arrays.indexing.html) em `numpy.arrays` para mais detalhes).

# In[205]:


# Código para Exercício 2.2
import matplotlib.pyplot as plt
import numpy as np


x = dados[:, 0] #Armazena o array de valores da primeira coluna de M na coordenada x do gráfico
y = dados[:, 1] #Armazena o array de valores da segunda coluna de M na coordenada y do gráfico
print(x, y)

plt.plot(x, y, 'r.') #Cria o gráfico com pontos vermelhos em destaque referentes às coordenadas representadas pelas 8 linhas de M
plt.show() #Display no gráfico atual

plt.plot(x, y) #Cria o gráfico com pontos conectados por linhas azuis referentes às coordenadas representadas pelas 8 linhas de M
plt.show()


# #### Questão 2.3
# 
# Agora que temos como visualizar os vetores no plano, vamos fazer operação de adição de vetores. Crie um array que represente um vetor $\textbf{a}=(\ 6,\ 9\ )$ e adicione-o a todos os vetores no nosso array, criando um novo array chamado `novos_dados`.
# 
# **Dica**: Quando estamos tratando de matrizes, não podemos simplesmente adicionar uma matriz de tamanho $n \times 2$ por um vetor de tamanho $2$, ou $1 \times 2$. Porém, o `numpy` tem uma funcionalidade que é muito útil quando queremos fazer operações entre arrays que não possuem o mesmo tamanho, como é o nosso caso (podemos ver isso usando: `print(dados.shape, a.shape)`). Essa funcionalidade é o [broadcasting](https://numpy.org/doc/stable/user/basics.broadcasting.html), e ela nos ajuda a fazer operações entre arrays que não possuem o mesmo tamanho, mas algumas dimensões são compatíveis. 

# In[206]:


# Código para Exercício 2.3
a = np.array([6, 9])
print(a)
a = a[np.newaxis,:]
print(a)
print(dados)
print(a.shape, dados.shape)
# dados        (2d array):  8 x 2
# a            (1d array):      1
# novos_dados  (2d array):  8 x 2
print((dados + a).shape)
novos_dados = dados + a
print(novos_dados)
# novos_dados = dados[:, np.newaxis] + a
# novos_dados


# #### Questão 2.4
# 
# Note que para somar arrays de dimensões diferentes (nesse caso, dados é 2D e a é 1D), o broadcasting primeiro adiciona dimensões de tamanho 1 ao início do array com menos dimensões. Só depois ele expande as dimensões de tamanho 1 para que casem com os tamanhos das dimensões do outro array.
# 
# Portanto, devemos pensar no array ```a``` como um vetor coluna ou como um vetor linha?

# **Resposta:** *insira sua resposta aqui*
#   Como observado no código acima, a transformação do array 'a' em um vetor linha (1x2) por meio do comando "a = a[np.newaxis,:]" possibilita que os valores de a e a operação pretendida (soma) sejam transmitidos (broadcasted) através das linhas do array 2D 'dados', produzindo o array 'novos_dados' com as somas realizadas. Desse modo, 'a' deve ser pensado como um vetor linha.

# #### Questão 2.5
# 
# Agora podemos ver no espaço 2D nossos vetores originais e os vetores resultantes da soma. Para isso, podemos usar a mesma função que usamos para criar o gráfico de dispersão na **Questão 2.2**, porém agora queremos mostrar os pontos de 2 arrays, e não de apenas 1.

# In[207]:


# Código para Exercício 2.5
x = np.concatenate([dados[:,0], novos_dados[:,0]])
y = np.concatenate([dados[:,1], novos_dados[:,1]])
plt.plot(x, y, 'r.') 
plt.show()


# ### Questão 3
# 
# Como visto em aula, a multiplicação de uma matriz $G$ por um vetor $\mathbb{x}$ pode ser vista como uma combinação linear das colunas de $G$.
# 

# 
# #### Questão 3.1
# 
# Dado a matriz $G$ e o vetor $\mathbb{x}$:
# 
# $$
# G = \begin{bmatrix}
#  3 & 6 & 9\\
#  5 & 10 & 15
# \end{bmatrix}_{2\times 3}
# \qquad
# \mathbb{x} = \begin{bmatrix}
#  2 \\
#  1 \\
#  1
# \end{bmatrix}_{3\times 1}
# $$
# 
# Gere o vetor $\mathbb{y}$ tal que:
# $$
# \mathbb{y} = G \mathbb{x} \\
# $$
# 

# In[208]:


# Código para Exercício 3.1
# G(2x3) . x(3x1) = y(2x1)
G = np.array([[3, 6, 9], [5, 10, 15]]) 
print(G.shape)                          # Criação de G
print(G,'\n')

x = (np.array([2, 1, 1])).reshape(3,1)
print(x.shape)                          # Criação de x
print(x,'\n')

y = np.matmul(G, x)
print(y.shape)                          # Produzindo y = Gx por meio do comando matmul
print(y,'\n')

y = np.zeros((G.shape[0], x.shape[1]), dtype=int)
print(y.shape)                                    # Limpando y com zeros
print(y,'\n')

for i in range(G.shape[0]):           # Produzindo y = Gx por meio de algoritmo de multplicação de matrizes
  for j in range(G.shape[1]): # Ou x.shape[0]
    y[i,0] += G[i][j] * x[j,0]
print(y.shape)
print(y,'\n')

y = np.zeros((G.shape[0], x.shape[1]), dtype=int)
#print(G[:,0].reshape(2,1), x[0])

for i in range(G.shape[1]):           # Produzindo y = Gx por meio da combiação linear das colunas de G usando os coeficientes do vetor coluna x
  y += G[:,i].reshape(2,1) * x[i]
print(y.shape)
print(y,'\n')


# #### Questão 3.2
# 
# O espaço de colunas de uma matriz pode ser interpretado como o espaço formado por todas as combinações lineares das colunas da matriz. Então, vamos simular a representação do espaço de colunas da matriz $G$ criada anteriormente fazendo várias combinações lineares de suas colunas. Para isso, podemos criar vários vetores-coluna $x$ aleatórios, calcular a operação $y = Gx$ para cada um deles, e mostrar onde cada vetor $y$ está localizado no espaço. Portanto, faça os seguintes passos:
# 
# 1. Crie um vetor-coluna $x \in \mathbb{R}^{3 \times 1}$ com valores aleatórios entre $-10$ e $10$.
# 1. Calcule $y = Gx$. Esse passo pode ser feito da mesma forma que a **Questão 3.1**.
# 1. Plote no plano 2D um ponto com as coordenadas do $y$ resultante.
# 
# Repita esses passos 10 vezes. **Dica:** para a criação dos valores $x$ aleatórios, voce pode escolher os números você mesmo ou usar a função [`np.random.randint`](https://numpy.org/doc/stable/reference/random/generated/numpy.random.randint.html). Para a  visualização, utilize a biblioteca [`matplotlib`](https://matplotlib.org/), e deixe para usar `plt.show()` apenas depois de ter plotado todos os vetores $y$, para que todos apareçam no mesmo gráfico.

# In[209]:


# Código para Exercício 3.2
for vezes in range(10):
  x = np.random.randint(-10, 11, (3, 1))
  #print(x)
  y = np.matmul(G, x)
  #print(y)
  _x = y[0]
  #print(_x)
  _y = y[1]
  #print(_y)
  plt.plot(_x, _y, 'g.') 
plt.show()




# #### Questão 3.3
# 
# No item anterior, você deve ter obtido uma reta ao visualizar o gráfico resultante. Por que isso acontece no caso dessa matriz $G$ em específico?

# **Resposta:** *insira sua resposta aqui*
# No caso da matriz G, percebe-se claramente que duas de suas colunas podem ser escritas como combinação linear de apenas uma coluna, ou seja, o posto de G é igual a 1. Portanto, os vetores coluna x aleatórios irão produzir vetores coluna y que também podem ser representados como combinação linear de apenas uma das colunas de G, o que gera, então, pontos no gráfico cujas coordenadas variam linearmente. Desse modo, ao plotar os pontos no gráfico, obtemos uma reta.

# #### Questão 3.4
# 
# Agora que sabemos que o espaço coluna da matriz $G$ é uma reta, encontre dois pontos no espaço coluna $C(G)$ e use o comando ```plt.plot()``` para traçá-la.

# In[210]:


# Código para Exercício 3.4
x = np.random.randint(-10, 11, (3, 1))
y = np.matmul(G, x)
x = np.random.randint(-10, 11, (3, 1))
y2 = np.matmul(G, x)
_x = np.array([y[0], y2[0]])
_y = np.array([y[1], y2[1]])
plt.plot(_x, _y, '-', linewidth=3)
plt.show()

