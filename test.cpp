////////////////////////////////////////////////////////////////////          
// boxWithLookAt.cpp
//
// Novia Zulfa Fitri                 5222600048
// Devina Yusra Wijaya               5222600055
// Sumanta Guha.
//
////////////////////////////////////////////////////////////////////

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

using namespace std;

float _angle = -70.0f;  // Sudut awal rotasi meja

void initRendering() {
    glEnable(GL_DEPTH_TEST);  // Aktifkan uji kedalaman
    glEnable(GL_COLOR_MATERIAL);  // Aktifkan material warna
    glEnable(GL_LIGHTING);  // Aktifkan pencahayaan
    glEnable(GL_LIGHT0);  // Aktifkan lampu nomor 0
    glEnable(GL_NORMALIZE);  // Aktifkan normalisasi vektor
    glShadeModel(GL_SMOOTH);  // Atur model shading menjadi GL_SMOOTH (halus)
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);  // Atur ukuran viewport sesuai dengan ukuran jendela
    glMatrixMode(GL_PROJECTION);  // Mode matriks proyeksi
    glLoadIdentity();  // Reset matriks proyeksi
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);  // Atur perspektif
}

void drawTable() {
    glColor3f(1.0f, 1.0f, 1.0f);  // Atur warna menjadi putih

    // Gambar papan atas meja
    glPushMatrix();
    glScalef(4.0f, 0.2f, 2.0f);  // Atur skala papan atas meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar lemari bawah meja KANAN
    glPushMatrix();
    glScalef(1.4f, 1.0f, 1.6f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -0.6f, 0.0f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();
  
    //LEMARI pop
    glPushMatrix();
    glScalef(1.4f, 0.4f, 0.09f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -2.2f, 9.2f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glScalef(1.4f, 0.4f, 0.09f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -1.0f, 9.2f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //pengangan lemari
    glPushMatrix();
    glTranslatef(0.85f, -0.4f, 0.88f);  // Geser ke bawah
    glScalef(0.4f, 0.05f, 0.08f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85f, -0.85f, 0.88f);  // Geser ke bawah
    glScalef(0.4f, 0.05f, 0.08f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar kaki meja 1
    glPushMatrix();
    glTranslatef(-1.6f, -1.0f, -0.8f);  // Geser ke posisi kaki meja 1
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 1 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6f, -1.0f, -0.8f);  // Geser ke posisi kaki meja 2
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 2 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -1.0f, 0.8f);  // Geser ke posisi kaki meja 3
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 3 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6f, -1.0f, 0.8f);  // Geser ke posisi kaki meja 4
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 kaki horizontal BAWAH
    glPushMatrix();
    glTranslatef(1.6f, -1.8f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -1.8f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 kaki horizontal ATAS
    glPushMatrix();
    glTranslatef(1.6f, -0.2f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -0.2f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //penutup kaki meja belakang
    glPushMatrix();
    glTranslatef(0.0f, -0.6f, -0.8f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0f, 3.2f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 penutup samping meja
    glPushMatrix();
    glTranslatef(1.6f, -0.8f, 0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.8f, 1.8f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -0.8f, 0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.8f, 1.8f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Bersihkan buffer warna dan kedalaman

    glMatrixMode(GL_MODELVIEW);  // Mode matriks tampilan model
    glLoadIdentity();  // Reset matriks tampilan model

    glTranslatef(0.0f, 0.0f, -14.0f);  // Geser ke posisi pandangan kamera

    GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Warna ambien
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);  // Atur warna ambien

    GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f };  // Warna cahaya
    GLfloat lightPos0[] = { 0.0f, -8.0f, 8.0f, 1.0f };  // Posisi cahaya
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);  // Atur warna dan posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    glRotatef(10, 1.0f, 0.0f, 0.0f);  // Putar objek di sekitar sumbu x
    glRotatef(-10, 0.0f, 0.0f, 1.0f);  // Putar objek di sekitar sumbu z
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);  // Putar objek di sekitar sumbu y

    drawTable();  // Gambar meja

    glutSwapBuffers();  // Tukar buffer untuk menampilkan hasil gambar
}

void update(int value) {
    _angle += 1.5f;  // Tingkat rotasi
    if (_angle > 360) {
        _angle -= 360;  // Reset sudut rotasi setelah melebihi 360 derajat
    }

    glutPostRedisplay();  // Meminta tampilan ulang jendela
    glutTimerFunc(25, update, 0);  // Atur timer untuk memanggil fungsi update lagi
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // Mode tampilan
    glutInitWindowSize(600, 600);  // Ukuran jendela

    glutCreateWindow("Table");  // Buat jendela dengan judul "Table"
    initRendering();  // Inisialisasi rendering

    glutDisplayFunc(drawScene);  // Fungsi tampilan
    glutReshapeFunc(handleResize);  // Fungsi penanganan perubahan ukuran jendela

    update(0);  // Memulai pembaruan sudut rotasi
    glutMainLoop();  // Memulai loop utama GLUT

    return 0;
}