## Projeção

Representação de 3 dimensões em meios 2D.

## No início

## Aprimoramentos

## Projeções
Se comparado com o processo de visualização bidimensional, visto até o momento, a visualização de objetos tridimensionais é bastante mais complexa.
Esta complexidade deve-se, basicamente, ao fato de que os dispositivos gráficos existentes são adequados à apresentação de imagens planas, bidimensionais. Da mesma maneira que um desenhista, quando quer representar no papel a imagem de um objeto tridimensional, no computador também é preciso gerar uma prejeção do objeto que se deseja exibir.
Uma projeção nada mais é do que uma representação bidimensional de um objeto tridimensional. Existem várias 
técnicas e tipos de projeção, cada uma delas adequada a uma tipo de aplicação. A mais importante dela é a projeção 
Perspectiva pois ela simula a projeção feita pelo olho humano quando este capta a imagem de um objeto.
Uma outra projeção importante é a Paralela

Perspectiva vs Paralela
Perspectiva
+ tamanho varia inversamente à distância: realista
- Distância e ângulos (em geral) não preservados
- Linhas paralelas (em geral) não permaneem paralelas

Paralela
+ Boa para medições precisas
+ Linhas paralelas permanecem paralelas
- Ângulos (em geral) não são preservados
- Aparência menos realista

Projeções Paralela e Perspectiva

As técnicas utilizadas em projeção perspectiva são derivadas daquelas utilizadas pelos artistas e desenhistas profissionais. Pode-se dizer que o olho do observador coloca-se no centro de projeção. Dois segmentos de reta que saem do centro de projeção e atingem o objeto no plano de projeção, são chamadas de projetantes.

Na projeção paralela as projetantes são paralelas.

Projeção paralela
Centro de projeção no infinito
- Direção de projeção (DOP) é a mesma para todos os pontos.

Transformação perspectiva

* Descoberta por Donatello, Brunelleschi, e DaVinci durante o Renascimento.
* Objetos mais próximos parecem maiores
* Linhas paralelas convergem em um único ponto.

Projeção de um cubo
A esfera B é bem maior que a esera A, porém ambas aparecem com o mesmo tamanho quando projetadas no plano de visão.


Desenvolvimento matemático para projeções perspectivas
* A modelagem matemática da projeção perspectiva baseia-se nas seguintes noções básicas:
* toma-se um plano PI, paralelo ao plano XY, ao qual dá-se o nome de plano de projeção;
* toma-se, sobre o eixo Z, um ponto de coordenadas (0, 0, -d), ao qual chama-se de centro de projeção (CP).

As coordenadas (xp'', yp''), da projeção perspectiva P'' de qualquer ponto P de coordenadas (xp, yp, zp), colocado do lado oposto de CP, em relação ao plano de projeção PI, é obtido criando-se uma linha L de P até CP e calculando-se a interseção desta com o plano de projeção.

O cálculo das coordenadas de P'' é deduzido, de forma mais fácil, se a figura 2 for visualizada de 2 maneiras especiais:

- em uma vista lateral direita é possível calcular a componente YP'' da projeção do ponto P. O cálculo é feito com base na técnica de semelhança de triângulos.

d/Yp' = (d + zp)/yp

yp' = yp / (zp / d) + 1

Em uma vista superior é
possível calcular a componente
XP" da projeção do ponto P. O
cálculo é feito, também com
base na técnica de semelhança
de triângulos

d/xp' = (d + zp)/xp

xp' = xp / (zp / d) + 1

Como calcular o valor de "D" ? 
Suponha que o plano de projeção tenha 
dimens¨es fixas formando um retângulo 
com extremos, por exemplo, em (-10, -10) e 
(10,10). Suponha, ainda, que se arbitre um 
ângulo de visão "alfa" que defina o quanto 
o observador consegue ver do universo, e 
em conseqüência, quanto do universo será 
exibido na tela. Este ângulo funciona como 
o ângulo de abertura da lente de uma 
máquina fotográfica, ou seja, quanto maior 
o ângulo, maior a região que pode ser 
enquadrada na foto.