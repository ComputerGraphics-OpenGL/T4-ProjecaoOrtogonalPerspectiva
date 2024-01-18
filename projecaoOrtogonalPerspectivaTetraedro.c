#include <GL/gl.h>
#include <GL/glu.h> 
#include <GL/glut.h> 
#include <math.h>
#include <stdio.h> 

int opcao; // declarar uma variável inteira para armazenar a opção de projeção (1 para perspectiva, 0 para ortogonal)
GLdouble traduzidoX, rotacionadoX; // declarar duas variáveis de ponto flutuante duplo para armazenar a translação e a rotação do tetraedro no eixo X

void ortogonal( // definir uma função para criar uma matriz de projeção ortogonal
    GLdouble coordenadaEsquerda, // receber a coordenada esquerda do plano de recorte
    GLdouble coordenadaDireita, // receber a coordenada direita do plano de recorte
    GLdouble coordenadaBase, // receber a coordenada inferior do plano de recorte
    GLdouble coordenadaTopo, // receber a coordenada superior do plano de recorte
    GLdouble Dproximo, // receber a distância do plano de recorte próximo
    GLdouble Dlonge // receber a distância do plano de recorte distante
) {
    GLdouble m[4][4] = {0}; // declarar e inicializar uma matriz 4x4 com zeros

    m[0][0] = 2 / (coordenadaDireita - coordenadaEsquerda); // calcular o elemento m[0][0] da matriz de projeção ortogonal
    m[1][1] = 2 / (coordenadaTopo - coordenadaBase); // calcular o elemento m[1][1] da matriz de projeção ortogonal
    m[2][2] = -2 / (Dlonge - Dproximo); // calcular o elemento m[2][2] da matriz de projeção ortogonal
    m[3][0] = -(coordenadaDireita + coordenadaEsquerda) / (coordenadaDireita - coordenadaEsquerda); // calcular o elemento m[3][0] da matriz de projeção ortogonal
    m[3][1] = -(coordenadaTopo + coordenadaBase) / (coordenadaTopo - coordenadaBase); // calcular o elemento m[3][1] da matriz de projeção ortogonal
    m[3][2] = -(Dlonge + Dproximo) / (Dlonge - Dproximo); // calcular o elemento m[3][2] da matriz de projeção ortogonal
    m[3][3] = 1; // atribuir o valor 1 ao elemento m[3][3] da matriz de projeção ortogonal
}

void inicializa() { // definir uma função para inicializar alguns parâmetros do programa
    opcao = 1; // atribuir o valor 1 à variável opcao, indicando que a projeção inicial é perspectiva
    traduzidoX = 0; // atribuir o valor 0 à variável traduzidoX, indicando que a translação inicial do tetraedro no eixo X é zero
    rotacionadoX = 0; // atribuir o valor 0 à variável rotacionadoX, indicando que a rotação inicial do tetraedro no eixo X é zero
    glClearColor(0.0, 0.0, 0.0, 0.0); // definir a cor de fundo da janela como preto
    glShadeModel(GL_FLAT); // definir o modelo de sombreamento como plano (sem interpolação de cores)
}

void perspectivaDirecaoX( // definir uma função para criar uma matriz de projeção perspectiva
    GLdouble angulo, // receber o ângulo de abertura do campo de visão
    GLdouble proporcao, // receber a proporção entre a largura e a altura da janela
    GLdouble Dproximo, // receber a distância do plano de recorte próximo
    GLdouble Dlonge // receber a distância do plano de recorte distante
) {
    GLdouble alturaEmX, xmin, ymin, larguraEmY; // declarar quatro variáveis de ponto flutuante duplo para armazenar a altura, a coordenada mínima, a coordenada máxima e a largura do plano de recorte
    GLdouble PI = 3.1415926535897932384626433832795; // declarar e atribuir o valor de PI

    GLdouble m[4][4] = {0}; // declarar e inicializar uma matriz 4x4 com zeros

    alturaEmX = tan((angulo / 2) / 180 * PI) * Dproximo; // calcular a altura do plano de recorte em função do ângulo e da distância do plano próximo
    xmin = -alturaEmX; // calcular a coordenada mínima do plano de recorte no eixo X
    ymin = xmin / proporcao; // calcular a coordenada mínima do plano de recorte no eixo Y em função da proporção
    larguraEmY = alturaEmX / proporcao; // calcular a largura do plano de recorte no eixo Y em função da proporção

    m[0][0] = (2.0 * Dproximo) / (alturaEmX - xmin); // calcular o elemento m[0][0] da matriz de projeção perspectiva
    m[1][1] = (2.0 * Dproximo) / (larguraEmY - ymin); // calcular o elemento m[1][1] da matriz de projeção perspectiva
    m[2][2] = -(Dlonge + Dproximo) / (Dlonge - Dproximo); // calcular o elemento m[2][2] da matriz de projeção perspectiva
    m[0][2] = (alturaEmX + xmin) / (alturaEmX - xmin); // calcular o elemento m[0][2] da matriz de projeção perspectiva
    m[1][2] = (larguraEmY + ymin) / (larguraEmY - ymin); // calcular o elemento m[1][2] da matriz de projeção perspectiva
    m[3][2] = -1.0; // atribuir o valor -1.0 ao elemento m[3][2] da matriz de projeção perspectiva
    m[2][3] = -(2.0 * Dlonge * Dproximo) / (Dlonge - Dproximo); // calcular o elemento m[2][3] da matriz de projeção perspectiva

    glMultMatrixd(*m); // multiplica a matriz atual pela matriz de projeção perspectiva
}

void remodelar(int w, int h) { // definir uma função para ajustar a janela e a projeção quando o tamanho da janela é alterado
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // definir a área de visualização como toda a janela
    glMatrixMode(GL_PROJECTION); // seleciona a matriz de projeção como a matriz atual
    glLoadIdentity(); // carrega a matriz identidade na matriz atual

    if (opcao) // se a opção for 1 (perspectiva)
        perspectivaDirecaoX(15.0, 1.0, 2, 40); // chama a função para criar uma matriz de projeção perspectiva com ângulo de 15 graus, proporção de 1, distância do plano próximo de 2 e distância do plano distante de 40
    else // se a opção for 0 (ortogonal)
        ortogonal(-1.5, 1.5, -1.5, 1.0, -2, 1.5); // chama a função para criar uma matriz de projeção ortogonal com as coordenadas do plano de recorte especificadas

    glMatrixMode(GL_MODELVIEW); // seleciona a matriz de modelagem e visualização como a matriz atual
}

void desenha(void) { // define uma função para desenhar o tetraedro na janela
    glClear(GL_COLOR_BUFFER_BIT); // limpa a janela com a cor de fundo

    glColor3f(1.0, 1.0, 0.0); // define a cor de desenho como amarela

    glLoadIdentity(); // carrega a matriz identidade na matriz atual

    if (opcao) // se a opção for 1 (perspectiva)
        gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // define a posição e a direção da câmera

    glRotatef(rotacionadoX, 0.0, 0.0, 1.0); // rotaciona o tetraedro no eixo X de acordo com a variável rotacionadoX
    glTranslatef(traduzidoX, 0.0, 0.0); // translada o tetraedro no eixo X de acordo com a variável traduzidoX

    if (!opcao) // se a opção for 0 (ortogonal)
        glScalef(0.5, 0.5, 0.5); // reduz o tamanho do tetraedro pela metade

    glutWireTetrahedron(); // desenha um tetraedro com linhas

    glFlush(); // envia os comandos de desenho para a placa gráfica
}

void teclado(unsigned char tecla, int x, int y) { // define uma função para tratar os eventos de teclado
    switch (tecla) // verifica qual tecla foi pressionada
    {
    case 27: // se foi a tecla ESC
        exit(0); // encerra o programa
        break;
    case 'q': // se foi a tecla Q
        opcao = 1; // muda a opção para 1 (perspectiva)
        break;
    case 'e': // se foi a tecla E
        opcao = 0; // muda a opção para 0 (ortogonal)
        break;
    case 'w': // se foi a tecla W
        traduzidoX += 0.1; // aumenta a translação do tetraedro no eixo X em 0.1
        break;
    case 's': // se foi a tecla S
        traduzidoX -= 0.1; // diminui a translação do tetraedro no eixo X em 0.1
        break;
    case 'd': // se foi a tecla D
        rotacionadoX += 2; // aumenta a rotação do tetraedro no eixo X em 2 graus
        if (rotacionadoX >= 360) // se a rotação ultrapassar 360 graus
            rotacionadoX = 0; // zera a rotação
        break;
    case 'a': // se foi a tecla A
        rotacionadoX -= 2; // diminui a rotação do tetraedro no eixo X em 2 graus
        if (rotacionadoX <= -360) // se a rotação for menor que -360 graus
            rotacionadoX = 0; // zera a rotação
        break;
    }

    remodelar(800, 800); // chama a função para ajustar a janela e a projeção
    desenha(); // chama a função para desenhar o tetraedro
}


int main(int argc, char **argv) { // define a função principal do programa
    glutInit(&argc, argv); // inicializa a biblioteca GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // define o modo de exibição como simples e com cores RGB
    glutInitWindowSize(700, 700); // define o tamanho inicial da janela como 500x500 pixels
    glutInitWindowPosition(100, 100); // define a posição inicial da janela como 100x100 pixels
    glutCreateWindow(argv[0]); // cria a janela com o nome do programa
    inicializa(); // chama a função para inicializar alguns parâmetros do programa
    glutDisplayFunc(desenha); // registra a função para desenhar o tetraedro na janela
    glutReshapeFunc(remodelar); // registra a função para ajustar a janela e a projeção quando o tamanho da janela é alterado
    glutKeyboardFunc(teclado); // registra a função para tratar os eventos de teclado
    glutMainLoop(); // entra no laço principal da GLUT
    return 0; // retorna 0 ao finalizar o programa
}
