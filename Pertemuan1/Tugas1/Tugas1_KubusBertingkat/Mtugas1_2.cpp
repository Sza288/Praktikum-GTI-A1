#include <windows.h>
#include <gl/glut.h>

void KubusBertingkat(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    float s = 0.15f; 
    //Paling atas
    glColor3f(1.0f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
        //Kiri atas
        glVertex2f(-s*1.5f, s*1.0f); glVertex2f(-s*0.5f, s*1.0f);
        glVertex2f(-s*0.5f, s*2.0f); glVertex2f(-s*1.5f, s*2.0f);
        
        //Kanan atas
        glVertex2f( s*0.5f, s*1.0f); glVertex2f( s*1.5f, s*1.0f);
        glVertex2f( s*1.5f, s*2.0f); glVertex2f( s*0.5f, s*2.0f);
    glEnd();

    //Tengah
    glColor3f(1.0f, 0.4f, 0.4f); 
    glBegin(GL_QUADS);
        //Kiri tengah
        glVertex2f(-s*1.0f, 0.0f); glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, s*1.0f);  glVertex2f(-s*1.0f, s*1.0f);
        
        //Kanan tengah
        glVertex2f(0.0f, 0.0f);    glVertex2f( s*1.0f, 0.0f);
        glVertex2f( s*1.0f, s*1.0f); glVertex2f(0.0f, s*1.0f);
    glEnd();

    //Bawah
    glColor3f(0.8f, 0.0f, 0.0f); 
    glBegin(GL_QUADS);
        glVertex2f(-s*0.5f, -s*1.0f); glVertex2f( s*0.5f, -s*1.0f);
        glVertex2f( s*0.5f, 0.0f);   glVertex2f(-s*0.5f, 0.0f);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kubus Love");
    glutDisplayFunc(KubusBertingkat);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
