#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double rotAngle = 10;
double rotAngle1 = 10;

// IMPLEMENTASI TUGAS A: Mengubah sudut geser menjadi lebih halus (5.0 derajat) menggunakan variabel agar mudah dikonfigurasi
double deltaAngle = 5.0;

void init()
{
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glRotated(rotAngle, 0, 1, 0);
    glRotated(rotAngle1, 1, 0, 0);

    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 0.1, 0.1);

    glutSolidTeapot(1);

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
        // IMPLEMENTASI TUGAS B: Mengubah papan tombol dari WASD menjadi WASD dan tombol keluar menggunakan Escape (27)
        case 'W':
            rotAngle1 -= deltaAngle; // Putar ke atas
            break;
        case 'A':
            rotAngle1 += deltaAngle; // Putar ke bawah
            break;
        case 'S':
            rotAngle -= deltaAngle;  // Putar ke kiri
            break;
        case 'D':
            rotAngle += deltaAngle;  // Putar ke kanan
            break;
        case 27:
            exit(0);                 // Tombol Escape untuk keluar
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutCreateWindow("GLUT Example");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();
    return 0;
}
