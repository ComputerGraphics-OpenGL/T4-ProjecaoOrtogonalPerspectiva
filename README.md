# trabalho-CG-projecoes

## Projeção em perspectiva e paralela no OpenGL
Este projeto é um exemplo de como usar a biblioteca OpenGL para desenhar um tetraedro em uma janela, usando diferentes tipos de projeção: perspectiva e paralela.

## Projeção
Projeção é o processo de representar um objeto tridimensional em um plano bidimensional, como uma tela ou um papel. Existem vários tipos de projeção, mas os mais comuns são a projeção em perspectiva e a projeção paralela.

## Projeção em perspectiva
A projeção em perspectiva é aquela que simula a forma como o olho humano vê o mundo. Nessa projeção, os objetos mais próximos parecem maiores e os mais distantes parecem menores. Além disso, as linhas paralelas convergem em um ponto de fuga no horizonte. A projeção em perspectiva é mais realista, mas também mais complexa de se calcular.

## Projeção paralela
A projeção paralela é aquela que preserva as proporções e os ângulos dos objetos, independentemente da distância. Nessa projeção, os objetos têm o mesmo tamanho e as linhas paralelas permanecem paralelas. A projeção paralela é mais simples de se calcular, mas também menos realista.

## Código
O código deste projeto é escrito em C e usa as bibliotecas OpenGL, GLU e GLUT para criar a janela, a matriz de projeção e o desenho do tetraedro. O código está comentado em português, explicando o que cada função e cada linha faz.

O código permite ao usuário alterar a projeção, a translação e a rotação do tetraedro usando o teclado. As teclas são as seguintes:

Q: muda a projeção para perspectiva
E: muda a projeção para paralela
W: aumenta a translação do tetraedro no eixo X
S: diminui a translação do tetraedro no eixo X
D: aumenta a rotação do tetraedro no eixo Z
A: diminui a rotação do tetraedro no eixo Z
ESC: encerra o programa



## Compilação
```shell

gcc -c projecaoOrtogonalPerspectivaTetraedro.c -lGL -lGLU -lglut -lm
gcc -o projecaoOrtogonalPerspectivaTetraedro projecaoOrtogonalPerspectivaTetraedro.c -lGL -lGLU -lglut -lm
./projecaoOrtogonalPerspectivaTetraedro
```