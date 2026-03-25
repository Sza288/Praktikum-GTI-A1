# Lengan Robot (Jawaban no 1)

Program ini  menampilkan gerakan hierarkis lengan robot yang terdiri dari dua bagian: **Bahu (Shoulder)** dan **Siku (Elbow)**.

## Cara Kerja Kode
Program ini menggunakan konsep **Hierarchical Modeling** , di mana satu objek menjadi induk bagi objek lainnya.

1.  **Transformasi Matriks (`glPushMatrix` & `glPopMatrix`)**:
    * Setiap bagian lengan dibungkus dalam *stack* matriks.
    * Siku digambar sebagai "anak" dari lengan atas . Artinya, jika bahu berputar, posisi siku akan otomatis mengikuti ujung bahu.
2.  **Titik Tumpu (Pivot Point)**:
    * Secara default, objek di OpenGL berputar di titik pusatnya $(0,0,0)$.
    * Kode ini menggunakan teknik `glTranslatef` sebelum dan sesudah `glRotatef` untuk memindahkan titik rotasi ke ujung balok, sehingga gerakannya tampak seperti sendi engsel alami.
3.  **Skalasi**:
    * `glScalef(2.0, 0.4, 1.0)` digunakan untuk mengubah kubus standar menjadi bentuk balok panjang yang menyerupai tulang lengan.

---

## Kontrol Keyboard
| Tombol | Aksi | Deskripsi |
| :---: | :--- | :--- |
| **s** | Rotasi Bahu (+) | Memutar bahu berlawanan arah jarum jam. |
| **S** | Rotasi Bahu (-) | Memutar bahu searah jarum jam. |
| **e** | Rotasi Siku (+) | Memutar siku berlawanan arah jarum jam. |
| **E** | Rotasi Siku (-) | Memutar siku searah jarum jam. |
| **Esc** | Keluar | Menutup jendela aplikasi. |
