/* Nama : Khanza Qaila
NIM : 24060124120011 
Lab : A1 */

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 3.0f, z = 15.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;

void Reshape(int w1, int h1)
{
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
    x = x + i * (lx) * 0.1;
    z = z + i * (lz) * 0.1;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for(i=Z_MIN; i<Z_MAX; i+=gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for(i=X_MIN; i<X_MAX; i+=gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void CustomBlock(float dx, float dy, float dz)
{
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-dx, -dy, dz); glVertex3f(dx, -dy, dz); glVertex3f(dx, dy, dz); glVertex3f(-dx, dy, dz);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-dx, -dy, -dz); glVertex3f(-dx, dy, -dz); glVertex3f(dx, dy, -dz); glVertex3f(dx, -dy, -dz);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-dx, dy, -dz); glVertex3f(-dx, dy, dz); glVertex3f(dx, dy, dz); glVertex3f(dx, dy, -dz);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-dx, -dy, -dz); glVertex3f(dx, -dy, -dz); glVertex3f(dx, -dy, dz); glVertex3f(-dx, -dy, dz);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(dx, -dy, -dz); glVertex3f(dx, dy, -dz); glVertex3f(dx, dy, dz); glVertex3f(dx, -dy, dz);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-dx, -dy, -dz); glVertex3f(-dx, -dy, dz); glVertex3f(-dx, dy, dz); glVertex3f(-dx, dy, -dz);
    glEnd();
}

void CustomWheel()
{
    GLUquadricObj* quad = gluNewQuadric();
    gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -0.2f);
    
    glColor3f(0.15f, 0.15f, 0.15f);
    gluCylinder(quad, 0.4f, 0.4f, 0.4f, 16, 16);
    
    glPushMatrix();
    glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.85f, 0.85f, 0.8f);
    gluDisk(quad, 0.0f, 0.25f, 16, 1);
    glColor3f(0.15f, 0.15f, 0.15f);
    gluDisk(quad, 0.25f, 0.4f, 16, 1);
    glPopMatrix();
    
    glTranslatef(0.0f, 0.0f, 0.4f);
    glColor3f(0.85f, 0.85f, 0.8f);
    gluDisk(quad, 0.0f, 0.25f, 16, 1);
    glColor3f(0.15f, 0.15f, 0.15f);
    gluDisk(quad, 0.25f, 0.4f, 16, 1);
    
    glPopMatrix();
    gluDeleteQuadric(quad);
}

void Car3D()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f);
    
    glColor3f(0.7f, 0.05f, 0.05f);
    CustomBlock(2.5f, 0.4f, 1.1f);

    glPushMatrix();
    glTranslatef(-0.2f, 0.6f, 0.0f);
    glColor3f(0.6f, 0.8f, 0.9f);
    CustomBlock(0.9f, 0.3f, 1.0f);
    glPopMatrix();

    glPushMatrix(); glTranslatef(-1.4f, -0.3f, 1.1f); CustomWheel(); glPopMatrix();
    glPushMatrix(); glTranslatef(1.4f, -0.3f, 1.1f); CustomWheel(); glPopMatrix();
    glPushMatrix(); glTranslatef(-1.4f, -0.3f, -1.1f); CustomWheel(); glPopMatrix();
    glPushMatrix(); glTranslatef(1.4f, -0.3f, -1.1f); CustomWheel(); glPopMatrix();

    glPopMatrix();
}

void display() {
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glDisable(GL_LIGHTING);
    Grid();
    glEnable(GL_LIGHTING);
    
    Car3D();
    
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
    case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
    case GLUT_KEY_UP: deltaMove = 1; break;
    case GLUT_KEY_DOWN: deltaMove = -1; break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT: if (deltaAngle < 0.0f) deltaAngle = 0.0f; break;
    case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f) deltaAngle = 0.0f; break;
    case GLUT_KEY_UP: if (deltaMove > 0) deltaMove = 0; break;
    case GLUT_KEY_DOWN: if (deltaMove < 0) deltaMove = 0; break;
    }
}

const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.9f, 0.55f, 0.15f, 1.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("3D Mobil Sza");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}
