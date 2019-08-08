#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>



void Desenha(void){
    printf("Callback de redesenho da tela");
    //limpa a tela de visualizaçao com a cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);
    //exibe na tela
    glutSwapBuffers();
}

void AlteraTamanoJanela(GLsizei w, GLsizei h){
    printf("Novo Tamanho: %d x %d", w, h);
}

void Teclado(unsigned char tecla, int x, int y){
    int modificadores;
    printf("Tecla: %c", tecla);
    if (tecla == 27)
        exit(0);
    if (tecla == 'a')
        glutFullScreen();
    if (tecla == 'A'){
        glutReshapeWindow(500, 400);
        glutPositionWindow(100, 100);
    }

    modificadores = glutGetModifiers();
    //Casos de SHIFT, CTRL, ALT
    if (modificadores & GLUT_ACTIVE_SHIFT)
        printf("SHIFT pressionado");
    if (modificadores & GLUT_ACTIVE_CTRL)
        printf("CTRL pressionado");
    if (modificadores & GLUT_ACTIVE_ALT)
        printf("ALT pressionado");
}

void TeclasEspeciais(int tecla, int x, int y){
    switch (tecla){
        case GLUT_KEY_F1:
            printf("Tecla F1");
            break;
        case GLUT_KEY_F2:
            printf("Tecla F2");
            break;
        case GLUT_KEY_F3:
            printf("Tecla F3");
            break;
    }

}

void GerenciaMouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON)
        printf("Botao Esquerdo");
    if(button == GLUT_RIGHT_BUTTON)
        printf("Botao Direito");
    if(button == GLUT_MIDDLE_BUTTON)
        printf("Botao do Meio");
    if(button == GLUT_DOWN)
        printf("Botao pressionado");
    if(button == GLUT_UP)
        printf("Botao Liberado");
}

void MenuCor(int op){
    switch(op){
        case 0:
            printf("Vermelho");
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
            break;
        case 1:
            printf("Verde");
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 2:
            printf("Azul");
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
            break;
    }
    glutPostRedisplay();
}

void MenuPrimitiva(int op){
    switch(op){
        case 0:
            printf("Triangulo");
            break;
        case 1:
            printf("Quadrado");
            break;
        case 2:
            printf("Circulo");
            break;
    }
    glutPostRedisplay();
}

void MenuPrincipal(int op){
    switch(op){
        case 0:
            glutFullScreen();
            break;
    }

    glutPostRedisplay();
}

void CriaMenu(){
    int menu, submenu1, submenu2;

    //cria submenu de cor
    submenu1 = glutCreateMenu(MenuCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);

    //cria submenu de primitiva
    submenu2 = glutCreateMenu(MenuPrimitiva);
    glutAddMenuEntry("Triangulo", 0);
    glutAddMenuEntry("Quadrado", 1);
    glutAddMenuEntry("Circulo", 2);

    //menu principal
    menu = glutCreateMenu(MenuPrincipal);
    glutAddSubMenu("Cor", submenu1);
    glutAddSubMenu("Primitiva", submenu2);
    glutAddMenuEntry("Tela Cheia", 0);

    //associa botao direito do mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void Inicializa(void){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[] ){
    glutInit(&argc,argv);

    //Define o modo de operação da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

    //especifica a posiçao inicial da janela
    glutInitWindowPosition(0,0);

    //especifica o tamanho da janela
    glutInitWindowSize(500, 400);

    //cria a janela e passa o nome
    glutCreateWindow("Trabalho de CG");

    //callback da funçao que desenha a janela
    glutDisplayFunc(Desenha);

    //callback de redimensionamento da janela
    glutReshapeFunc(AlteraTamanoJanela);

    //callback do teclado comum
    glutKeyboardFunc(Teclado);

    //callback teclas especiais
    glutSpecialFunc(TeclasEspeciais);

    //callback do mouse
    glutMouseFunc(GerenciaMouse);

    //criar menu
    CriaMenu();

    Inicializa();

    //inicia o processamento
    glutMainLoop();

    return 0;
}
