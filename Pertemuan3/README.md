# Tugas Lengan Bergerak (No 2 & 3)
## Khanza Qaila (24060124120011)
## Keyboard Kontrol
### 1. Bagian Lengan & Telapak
| Sendi | Tambah Sudut | Kurang Sudut |
| :--- | :---: | :---: |
| **Bahu (Shoulder)** | `s` | `S`  |
| **Siku (Elbow)** | `e` | `E`  |
| **Telapak (Palm)** | `p` | `P` |

### 2. Ruas Jari 1 (Pangkal)
*Gunakan angka untuk menekuk dan meluruskan ruas pertama:*
* **Tekuk (0° ke 90°)**: Tombol `1`, `2`, `3`, `4`, `5`
* **Luruskan (90° ke 0°)**: Tombol `6`, `7`, `8`, `9`, `0`

### 3. Ruas Jari 2 (Ujung)
*Gunakan tombol huruf berikut untuk menambah tekukan pada ruas kedua:*
* `q` : Jari 1 (Ibu Jari)
* `w` : Jari 2 (Telunjuk)
* `r` : Jari 3 (Tengah)
* `t` : Jari 4 (Manis)
* `y` : Jari 5 (Kelingking)
* **[SPACE]**: Reset posisi semua jari menjadi lurus .
* **[ESC]**: Keluar dari jendela.

## Jawaban No.3

Setiap kali tombol keyboard ditekan, program melakukan operasi **Transformasi Geometri** pada sumbu X, Y, dan Z. Berikut adalah penjelasannya:

### 1. Sistem Sudut (+5 / -5)
* **Rotasi Positif (+5)**: Saat menekan tombol huruf kecil (s, e, p, q, w, r, t, y) atau angka (1-5), sudut akan bertambah 5 derajat. Ini menyebabkan objek berputar **berlawanan arah jarum jam** pada sumbu Z
* **Rotasi Negatif (-5)**: Saat menekan tombol huruf kapital (S, E, P) atau angka (6-0), sudut berkurang 5 derajat. Ini menyebabkan objek berputar **searah jarum jam** .

### 2. Operasi Sumbu (X, Y, Z)
Dalam sistem koordinat 3D di program ini:
* **Sumbu X**: Digunakan sebagai arah panjang tulang (lengan dan jari). Objek digeser (`glTranslatef`) sepanjang sumbu ini.
* **Sumbu Y**: Menentukan ketinggian objek dalam ruang.
* **Sumbu Z**: Menjadi **poros rotasi** utama. Semua gerakan menekuk lengan dan jari berputar mengelilingi sumbu Z agar objek bergerak naik-turun di layar.

---

##Simulasi

*Berikut adalah perbandingan posisi objek saat koordinat digerakan melalui keyboard:*

### A. Gerakan Bahu (Shoulder)
| Keadaan Normal (0°) | pencet 's' (+5°) |  (-5°) | 
| :---: | :---: | :---:
| <img width="750" height="214" alt="image" src="https://github.com/user-attachments/assets/1142c9f9-bb9f-4571-bae3-ed014002c737" />| <img width="717" height="218" alt="image" src="https://github.com/user-attachments/assets/76ba638a-102e-4c47-b342-8b44bb44b237" /> | <img width="708" height="221" alt="image" src="https://github.com/user-attachments/assets/fb9e3600-523d-498f-9e20-08c032bb350f" />|
| *Posisi lengan sejajar sumbu X* | *Seluruh lengan terangkat ke atas* | *Seluruh lengan turun ke bawah* |

### B. Gerakan Siku (Elbow)
| Keadaan Normal (0°) | pencet 'e' (+5°) | pencet 'E' (-5°) | 
| :---: | :---: | :---:
| <img width="714" height="208" alt="image" src="https://github.com/user-attachments/assets/616bb70f-883a-42ca-b00e-fb47f7990196" />| <img width="702" height="204" alt="image" src="https://github.com/user-attachments/assets/db79ca69-976d-47f3-bd5c-f137c50123c2" />| <img width="669" height="170" alt="image" src="https://github.com/user-attachments/assets/b40b79f5-225c-495f-872a-e91a0a175eca" /> |

| *Lengan bawah lurus* | *Hanya lengan bawah yang menekuk keatas* | *Hanya lengan bawah yang menekuk ke bawah* | 

### C. Gerakan Jari (Fingers)
| Keadaan Normal (0°) | Ruas 1 - pencet 1-5  (+5°/pencet) | Ruas 2 - pencet q,w,r,t,y (+5°/pencet) |
| :---: | :---: | :---: |
| <img width="714" height="208" alt="image" src="https://github.com/user-attachments/assets/616bb70f-883a-42ca-b00e-fb47f7990196" /> | <img width="666" height="176" alt="image" src="https://github.com/user-attachments/assets/4cc2e8e2-657d-4803-8ee5-d0fca3e56777" />| <img width="613" height="224" alt="image" src="https://github.com/user-attachments/assets/5cde818f-8cf1-4281-8d24-42c02b53b278" />|
| *Jari lurus horizontal* | *Pangkal jari menekuk , disini 45°* | *Ujung jari melengkung , disini 90°* |

## Pose.1
<img width="1920" height="1080" alt="Screenshot Pose1" src="https://github.com/user-attachments/assets/2ded1c64-d605-4c19-88c8-21ba23cf3e7e" />

## Pose.2
<img width="1920" height="1080" alt="Screenshot Pose2" src="https://github.com/user-attachments/assets/74ed50a8-05e8-4724-8656-f40f079180f5" />

## Pose.3
<img width="1920" height="1080" alt="Screenshot Pose3" src="https://github.com/user-attachments/assets/8dd8064a-191b-48a6-b6fe-35fcd84c2e30" />

---
