#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

static int shoulder = 0, elbow = 0, palm = 0;
static int fingerAngles[5][2] = {
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
};

GLUquadricObj *quadric;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_LINE);
}

void drawPhalanxCylinder(float length, float radius) {
    glPushMatrix();
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadric, radius, radius, length, 10, 5); 
    glPopMatrix();
}

void drawFingerWire2(int index, float offsetZ) {
    float a1 = (GLfloat)fingerAngles[index][0];
    float a2 = (GLfloat)fingerAngles[index][1];

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, offsetZ);
        
        // Ruas 1
        glRotatef(a1, 0.0, 0.0, 1.0);
        drawPhalanxCylinder(0.35f, 0.05f);

        // Ruas 2
        glTranslatef(0.35f, 0.0f, 0.0f);
        glRotatef(a2, 0.0, 0.0, 1.0);
        drawPhalanxCylinder(0.25f, 0.04f);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 

    glPushMatrix();
        //Lengan
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        //Siku
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        //Telapak
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
        glPushMatrix();
            glTranslatef(0.25, 0.0, 0.0);
            glScalef(0.5, 0.6, 0.6);
            glutWireCube(1.0);
        glPopMatrix();

        //5 Jari
        glTranslatef(0.5, 0.0, 0.0);
        drawFingerWire2(0,  0.25f);
        drawFingerWire2(1,  0.12f);
        drawFingerWire2(2,  0.00f);
        drawFingerWire2(3, -0.12f);
        drawFingerWire2(4, -0.25f);

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'p': palm = (palm + 5) % 360; break;
        case 'P': palm = (palm - 5) % 360; break;

        case '1': if (fingerAngles[0][0] < 90) fingerAngles[0][0] += 5; break;
        case '2': if (fingerAngles[1][0] < 90) fingerAngles[1][0] += 5; break;
        case '3': if (fingerAngles[2][0] < 90) fingerAngles[2][0] += 5; break;
        case '4': if (fingerAngles[3][0] < 90) fingerAngles[3][0] += 5; break;
        case '5': if (fingerAngles[4][0] < 90) fingerAngles[4][0] += 5; break;
        case '6': if (fingerAngles[0][0] > 0)  fingerAngles[0][0] -= 5; break;
        case '7': if (fingerAngles[1][0] > 0)  fingerAngles[1][0] -= 5; break;
        case '8': if (fingerAngles[2][0] > 0)  fingerAngles[2][0] -= 5; break;
        case '9': if (fingerAngles[3][0] > 0)  fingerAngles[3][0] -= 5; break;
        case '0': if (fingerAngles[4][0] > 0)  fingerAngles[4][0] -= 5; break;

        case 'q': if (fingerAngles[0][1] < 90) fingerAngles[0][1] += 5; break;
        case 'w': if (fingerAngles[1][1] < 90) fingerAngles[1][1] += 5; break;
        case 'r': if (fingerAngles[2][1] < 90) fingerAngles[2][1] += 5; break;
        case 't': if (fingerAngles[3][1] < 90) fingerAngles[3][1] += 5; break;
        case 'y': if (fingerAngles[4][1] < 90) fingerAngles[4][1] += 5; break;
        
        case ' ':
            for(int i=0; i<5; i++) {
                fingerAngles[i][0] = 0;
                fingerAngles[i][1] = 0;
            }
            break;

        case 27: 
            gluDeleteQuadric(quadric);
            exit(0); 
            break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(900, 500);
    glutCreateWindow("Tangan Bergerak- Khanza_011");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
