#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

double rx = 0.0;
double ry = 0.0;
float l[] = { 0.0, 80.0, 0.0 };   // Koordinat posisi sumber cahaya
float n[] = { 0.0, -40.0, 0.0 };  // Vektor normal (arah tegak lurus) bidang lantai
float e[] = { 0.0, -60.0, 0.0 };  // Titik acuan posisi tinggi lantai
void help();

// Fungsi pembantu untuk membuat satu balok penyusun huruf
void drawCube(float x, float y, float z, float sx, float sy, float sz) {
    glPushMatrix();
    glTranslatef(x, y, z); // Mengatur posisi balok
    glScalef(sx, sy, sz);     // Mengatur ukuran panjang, tinggi, lebar balok
    glutSolidCube(1.0);       // Menggambar kubus dasar ukuran 1
    glPopMatrix();
}

// OBYEK BARU: Menggambar susunan huruf E - X - O dalam bentuk 3D
void draw()
{
    glPushMatrix();
    glTranslatef(-5.0, 0.0, 0.0); // Geser seluruh grup tulisan ke tengah agar rotasi seimbang

    // ---- HURUF E ----
    drawCube(-25, 0, 0, 4, 20, 6);   // Batang vertikal E
    drawCube(-20, 8, 0, 10, 4, 6);  // Garis atas E
    drawCube(-21, 0, 0, 8, 4, 6);   // Garis tengah E
    drawCube(-20, -8, 0, 10, 4, 6); // Garis bawah E

    // ---- HURUF X ----
    glPushMatrix();
    glRotatef(45, 0, 0, 1);         // Diputar 45 derajat untuk silang pertama
    drawCube(0, 0, 0, 24, 5, 6);    
    glRotatef(90, 0, 0, 1);         // Diputar silang tegak lurus untuk silang kedua
    drawCube(0, 0, 0, 24, 5, 6);    
    glPopMatrix();

    // ---- HURUF O ----
    drawCube(20, 0, 0, 4, 20, 6);   // Sisi kiri O
    drawCube(32, 0, 0, 4, 20, 6);   // Sisi kanan O
    drawCube(26, 8, 0, 12, 4, 6);   // Sisi atas O
    drawCube(26, -8, 0, 12, 4, 6);  // Sisi bawah O

    glPopMatrix();
}

// FUNGSI MATRIKS BAYANGAN: Memipihkan objek 3D ke lantai berdasarkan arah cahaya
void glShadowProjection(float * l, float * e, float * n)
{
    float d, c;
    float mat[16];
    
    // ALUR 1: Hitung dot product antara normal lantai (n) dan posisi lampu (l)
    d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
    
    // ALUR 2: Hitung jarak relatif bidang lantai terhadap lampu
    c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;

    // ALUR 3: Menyusun matriks proyeksi 4x4 (urutan kolom/column-major untuk OpenGL)
    mat[0] = l[0]*n[0]+c; 
    mat[4] = n[1]*l[0];
    mat[8] = n[2]*l[0];
    mat[12] = -l[0]*c-l[0]*d;
    mat[1] = n[0]*l[1];
    mat[5] = l[1]*n[1]+c;
    mat[9] = n[2]*l[1];
    mat[13] = -l[1]*c-l[1]*d;
    mat[2] = n[0]*l[2];
    mat[6] = n[1]*l[2];
    mat[10] = l[2]*n[2]+c;
    mat[14] = -l[2]*c-l[2]*d;
    mat[3] = n[0];
    mat[7] = n[1];
    mat[11] = n[2];
    mat[15] = -d;
    
    // ALUR 4: Kalikan matriks transformasi aktif dengan matriks bayangan ini
    glMultMatrixf(mat); 
}

void render()
{
    glClearColor(0.0,0.6,0.9,0.0); // Set warna background langit (biru muda)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_POSITION, l); // Set posisi sumber cahaya nyata
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    
    // Gambar titik lampu (warna kuning)
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POINTS);
    glVertex3f(l[0],l[1],l[2]);
    glEnd();
    
    // Gambar Lantai tempat bayangan jatuh (warna abu-abu terang)
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-1300.0,e[1]-0.1, 1300.0);
    glVertex3f( 1300.0,e[1]-0.1, 1300.0);
    glVertex3f( 1300.0,e[1]-0.1,-1300.0);
    glVertex3f(-1300.0,e[1]-0.1,-1300.0);
    glEnd();
    
    // =================================================================
    // PROSES 1: GAMBAR OBJEK ASLI TULISAN EXO (3D)
    // =================================================================
    glPushMatrix();             // Simpan matriks modelview
    glRotatef(ry,0,1,0);        // Rotasi pada sumbu Y
    glRotatef(rx,1,0,0);        // Rotasi pada sumbu X
    glEnable(GL_LIGHTING);      // Aktifkan pencahayaan 3D
    glColor3f(0.1, 0.1, 0.1);   // Warna objek asli (hitam/abu gelap elegan)
    draw();                     // Panggil fungsi gambar EXO
    glPopMatrix();              // Kembalikan matriks
    
    // =================================================================
    // PROSES 2: GAMBAR BAYANGAN TULISAN EXO (2D)
    // =================================================================
    glPushMatrix();             // Simpan matriks modelview
    glShadowProjection(l,e,n);  // Aktifkan fungsi pemipihan objek ke lantai berdasarkan arah lampu
    glRotatef(ry,0,1,0);        // Rotasi Y (harus sama agar gerakan bayangan sinkron)
    glRotatef(rx,1,0,0);        // Rotasi X (harus sama agar gerakan bayangan sinkron)
    glDisable(GL_LIGHTING);     // Matikan pencahayaan (karena bayangan fisik tidak menerima cahaya)
    glColor3f(0.3, 0.3, 0.3);   // Warna bayangan (abu-abu gelap samar)
    draw();                     // Gambar ulang EXO (otomatis terproyeksi ceper di atas lantai)
    glPopMatrix();              // Kembalikan matriks
    
    glutSwapBuffers(); // Tukar buffer grafis (Double Buffering)
}

// Kontrol keyboard untuk memindahkan posisi sumber cahaya
void keypress(unsigned char c, int a, int b)
{
    if ( c==27 ) exit(0);
    else if ( c=='s' ) l[1]-=5.0; // Turunkan posisi lampu
    else if ( c=='w' ) l[1]+=5.0; // Naikkan posisi lampu
    else if ( c=='a' ) l[0]-=5.0; // Geser lampu ke kiri
    else if ( c=='d' ) l[0]+=5.0; // Geser lampu ke kanan
    else if ( c=='q' ) l[2]-=5.0; // Geser lampu ke depan
    else if ( c=='e' ) l[2]+=5.0; // Geser lampu ke belakang
    else if ( c=='h' ) help();
}

void help()
{
    printf("Proyeksi bayangan objek 3D berbentuk tulisan EXO\n");
    printf("Gunakan tombol W,A,S,D,Q,E untuk menggerakkan posisi lampu.\n");
}

// Membuat animasi rotasi objek secara real-time
void idle()
{
    rx+=0.1; // Tambah sudut rotasi X
    ry+=0.1; // Tambah sudut rotasi Y
    render(); // Panggil fungsi render ulang layar
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300,30);
    glutCreateWindow("Proyeksi Bayangan 3D - EXO");
    glutReshapeFunc(resize);
    glutReshapeWindow(500,500);
    glutKeyboardFunc(keypress);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
    
    // Inisialisasi Fitur OpenGL
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST); // Mengaktifkan Z-Buffer agar objek bertumpuk dengan benar
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    
    // Set Kamera & Proyeksi Perspektif
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1.0, 1.0, 400.0);
    
    // Set Koordinat Mulai Modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -150.0); // Mundurkan kamera agar objek terlihat utuh
    
    glutMainLoop(); // Jalankan loop utama GLUT
    return 0;
}
