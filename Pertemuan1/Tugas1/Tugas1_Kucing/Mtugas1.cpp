#include <windows.h>
#include <gl/glut.h>

void KucingKartun(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //BADAN
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(-0.5f, -0.6f); 
		glVertex2f(0.5f, -0.6f);
        glVertex2f(0.5f, 0.1f); 
		glVertex2f(-0.5f, 0.1f);
    glEnd();

    //KEPALA
    glBegin(GL_QUADS);
        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(-0.35f, 0.1f); 
		glVertex2f(0.35f, 0.1f);
        glVertex2f(0.35f, 0.6f); 
		glVertex2f(-0.35f, 0.6f);
    glEnd();

    //TANGAN
    //Kiri
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.55f, 0.55f, 0.55f);
        glVertex2f(-0.5f, -0.2f); 
        glVertex2f(-0.5f, -0.4f); 
        glVertex2f(-0.7f, -0.1f); 
        glVertex2f(-0.7f, -0.3f); 
    glEnd();

    //Kanan
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.55f, 0.55f, 0.55f);
        glVertex2f(0.5f, -0.2f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.7f, -0.1f);
        glVertex2f(0.7f, -0.3f);
    glEnd();

    //TELINGA
    glBegin(GL_TRIANGLES);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(-0.35f, 0.6f); glVertex2f(-0.5f, 0.8f); glVertex2f(-0.15f, 0.6f);
        glVertex2f(0.15f, 0.6f); glVertex2f(0.5f, 0.8f); glVertex2f(0.35f, 0.6f);
    glEnd();

    //MATA
    glPointSize(12.0f);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.15f, 0.45f); glVertex2f(0.15f, 0.45f);
    glEnd();

    // SENYUMAN
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-0.1f, 0.3f); 
        glVertex2f(-0.05f, 0.25f); 
        glVertex2f(0.0f, 0.3f);    
        glVertex2f(0.05f, 0.25f);  
        glVertex2f(0.1f, 0.3f);    
    glEnd();

    //EKOR 
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.5f, 0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f); 
		glVertex2f(0.5f, -0.4f);
        glVertex2f(0.8f, -0.2f); 
		glVertex2f(0.8f, -0.1f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kibom My Cat");
    glutDisplayFunc(KucingKartun);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
