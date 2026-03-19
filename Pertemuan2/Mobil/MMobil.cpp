#include <windows.h>
#include <gl/glut.h>
#include <math.h>

#define PI 3.1415926535898

void drawWheel(float x, float y)
{
    int i; float angle;
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0f, 0.0f);
            for (i = 0; i <= 60; i++) {
                angle = 2 * PI * i / 60;
                glVertex2f(0.12f*cos(angle), 0.12f*sin(angle));
            }
        glEnd();
        glColor3f(0.85f, 0.82f, 0.75f);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0f, 0.0f);
            for (i = 0; i <= 60; i++) {
                angle = 2 * PI * i / 60;
                glVertex2f(0.07f*cos(angle), 0.07f*sin(angle));
            }
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2.0f);
        glBegin(GL_LINE_LOOP);
            for (i = 0; i < 60; i++) {
                angle = 2 * PI * i / 60;
                glVertex2f(0.12f*cos(angle), 0.12f*sin(angle));
            }
        glEnd();
    glPopMatrix();
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //background orange
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0.85f, 0.45f, 0.10f);
            glVertex2f(-1.0f,  1.0f); glVertex2f(1.0f,  1.0f);
            glColor3f(0.95f, 0.62f, 0.20f);
            glVertex2f( 1.0f, -0.42f); glVertex2f(-1.0f, -0.42f);
        glEnd();
    glPopMatrix();

    //jalan
    glPushMatrix();
        glColor3f(0.20f, 0.20f, 0.22f);
        glBegin(GL_QUADS);
            glVertex2f(-1.0f,-0.42f); glVertex2f(1.0f,-0.42f);
            glVertex2f( 1.0f,-1.0f);  glVertex2f(-1.0f,-1.0f);
        glEnd();
    glPopMatrix();

    //garis jalan 
        glColor3f(0.95f, 0.88f, 0.20f);
        glLineWidth(3.0f);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(3, 0xAAAA);
        glBegin(GL_LINES);
            glVertex2f(-1.0f,-0.75f); glVertex2f(1.0f,-0.75f);
        glEnd();
        glDisable(GL_LINE_STIPPLE);

    //papan
    glColor3f(0.50f, 0.40f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2f(0.70f,-0.42f); glVertex2f(0.74f,-0.42f);
        glVertex2f(0.74f,-0.10f); glVertex2f(0.70f,-0.10f);
    glEnd();
    glColor3f(0.95f, 0.95f, 0.95f);
    glBegin(GL_QUADS);
        glVertex2f(0.58f,-0.10f); glVertex2f(0.86f,-0.10f);
        glVertex2f(0.86f, 0.12f); glVertex2f(0.58f, 0.12f);
    glEnd();

    //body
    glPushMatrix();
        glColor3f(0.75f, 0.06f, 0.06f);
        glBegin(GL_QUADS);
            glVertex2f(-0.50f,-0.32f); glVertex2f(0.50f,-0.32f);
            glVertex2f( 0.50f,-0.12f); glVertex2f(-0.50f,-0.12f);
        glEnd();
    glPopMatrix();

    //atap
    glPushMatrix();
        glColor3f(0.62f, 0.04f, 0.04f);
        glBegin(GL_QUADS);
            glVertex2f(-0.22f,-0.12f); glVertex2f(0.22f,-0.12f);
            glVertex2f( 0.18f, 0.06f); glVertex2f(-0.18f, 0.06f);
        glEnd();
    glPopMatrix();

    //kaca depan
    glPushMatrix();
        glColor3f(0.60f, 0.85f, 0.95f);
        glBegin(GL_QUADS);
            glVertex2f(0.05f,-0.11f); glVertex2f(0.20f,-0.11f);
            glVertex2f(0.18f, 0.05f); glVertex2f(0.05f, 0.05f);
        glEnd();
    glPopMatrix();

    //kaca belakang
    glPushMatrix();
        glColor3f(0.60f, 0.85f, 0.95f);
        glBegin(GL_QUADS);
            glVertex2f(-0.20f,-0.11f); glVertex2f(-0.05f,-0.11f);
            glVertex2f(-0.05f, 0.05f); glVertex2f(-0.18f, 0.05f);
        glEnd();
    glPopMatrix();

    //lampu
    glPushMatrix();
        glTranslatef(0.46f, -0.20f, 0.0f);
        glColor3f(1.0f, 1.0f, 0.80f);
        int i; float angle;
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(0.0f, 0.0f);
            for (i = 0; i <= 30; i++) {
                angle = 2 * PI * i / 30;
                glVertex2f(0.04f*cos(angle), 0.04f*sin(angle));
            }
        glEnd();
    glPopMatrix();

    drawWheel( 0.28f, -0.42f);
    drawWheel(-0.28f, -0.42f);

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mobil Vintage Sza ");
    glutDisplayFunc(RenderScene);
    glClearColor(0.90f, 0.55f, 0.15f, 1.0f);
    glutMainLoop();
    return 0;
}
