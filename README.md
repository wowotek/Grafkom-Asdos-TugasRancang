# Grafkom-Dosen-TugasRancang

> Tugas Ini di rilis oleh  **Erlangga Ibrahim** secara terbuka (*Open Source*)
> Dibawah Lisensi **GNU GPLv3**. untuk keterangan dan informasi lebih lanjut mengenai
> Lisensi, dapat dibuka di : https://www.gnu.org/licenses/gpl-3.0.en.html
> atau dengan membaca file `LICENSE`
>  
> Semua sumber yang digunakan pada tugas ini, dapat dilihat pada :
> https://github.com/wowotek/Grafkom-Asdos-TugasRancang
>  
> **PERINGATAN** : *Tugas ini dirilis **setelah tenggat waktu** pengumpulan tugas, dan tidak akan berlaku untuk kolega dengan tenggat waktu pengumpulan yang sama*
>  
> **PERINGATAN** : *Tugas ini dirilis **tanpa garansi**, termasuk nilai yang di-nihilkan oleh sebab **mencontek** dan/atau **menyalin** dan/atau **meniru** yang bersumber dari tugas ini*

![screenshot](./Screenshot.png)

## Penulis

* **Aurelia Gabriele** (672017277) - *@aureliagbrl*
* **Erlangga Ibrahim** (672017282) - *@wowotek*

## Deskripsi Tugas

Buat Sebuah Rumah Tradisional **Kalimantan Tengah** atau disebut juga **Rumah Betang** secara 3D dengan OpenGL 1.x

### Ketentuan

1. Bangunan Dibuat Semirip Mungkin
2. Menggunakan Viewport
3. Semua Objek harus 3D
4. Terdapat fungsi mouse dan keyboard
    1. Mouse untuk memutar objek
    2. Keyboard untuk menggerakan object minimal dengan `W`, `A`, `S`, `D`
5. Didalam bangunan terdapat minimal 5 jenis furnitur yang berbeda
6. Terdapat papan bertuliskan nama rumah adat diluar rumah

## Cara Menggunakan Project

### Cloning

Clone repo ini dengan cara :

```bash
git clone https://github.com/wowotek/Grafkom-Asdos-TugasRancang
```

### Dependencies
Tugas Rancang ini memiliki kebutuhan library external yaitu:
  * freeglut3
  * freeglut3-dev
  * Makefile

sebelum melakukan kompilasi, harap penuhi kebutuhan library tersebut
#### Freeglut dan Make

##### Ubuntu

```bash
sudo apt install freeglut3 freeglut3-dev make
```

##### Windows

> TODO : Fill this section about how to install GLUT in windows

### Kompilasi

#### Ubuntu 18.04

1. Buka terminal dengan

    __`CTRL` + `ALT` + `T`__

2. Compile menggunakan Make
    * Gunakan `make build` untuk kompilasi saja
        ```bash
        make build
        ```
    * Gunakan `make run` untuk run project
        ```bash
        make run
        ```
    * Gunaka `make all` untuk kompilasi dan run project
        ```bash
        make all
        ```

#### Windows

> TODO : Fill this section about how to compile in windows

### Eksekusi Program
file yang telah dicompile berada pada **`build/bin/`**

#### Ubuntu

Running project secara manual dapat menggunakan command
```bash
./build/bin/trAsdos.app
```
atau dapat di buka di `[root_project_folder]/build/bin/` lalu dengan klik 2 kali pada aplikasi `trAsdos.app`

#### Windows

> TODO : Fill this section about how to run executable in windows

## Kontribusi

untuk melakukan kontribusi, ada beberapa hal yang perlu diketahui beberapa diantaranya adalah :

### Panduan Penamaan File

Ketika membuat source file baru, mohon gunakan standard sebagai berikut:

* Implementation File
  * nama file implementasi harus menggunakan huruf kecil
  * ekstensi file implementasi harus menggunakan **`*.cc`** melainkan **`*.cpp`**
    * *contoh :* __`render.cc`__
  * sangat disarankan hanya menggunakan satu buah kata 
    * *contoh :* __`entities.cc`__
  * jika lebih dari satu, kedua kata menggunakan huruf kecil, tanpa pemisah
    * *contoh :* __`makanankucing.cc`__
* Header / Definition File
  * nama file implementasi harus menggunakan huruf kecil
  * ekstensi file implementasi harus menggunakan **`*.hh`** melainkan **`*.h`** atau **`*.hpp`**
    * *contoh :* __`render.hh`__
  * sangat disarankan hanya menggunakan satu buah kata 
    * *contoh :* __`entities.hh`__
  * jika lebih dari satu, kedua kata menggunakan huruf kecil, tanpa pemisah
    * *contoh :* __`makanankucing.hh`__

### Panduan *Coding Style*

*Coding style* yang digunakan adalah gabungan dari **_GNU Coding Standards_** dan **_Object Pascal Style_** berikut penjabaran lebih lengkap mengenai kedua style tersebut :

* **GNU Coding Standards** : https://www.gnu.org/prep/standards/standards.html
* **Object Pascal / Delphi Style** : https://edn.embarcadero.com/article/10280

#### Gambaran Umum

Secara singkat berikut contoh gabungan dari kedua standard tersebut:

```c++
                                // Semua Comment harus sejajar dengan comment yang lain
#include <iostream>             // semua library standard harus ada diatas library-
#include <string.h>             // yang anda buat

#include "control.h"            // library anda harus ada setelah library standard

int exitCode = 0;               // nama variabel harus mengikuti gaya 'camelCase'

void RenderDisplay(void);       // definisi Fungsi mengikuti gaya standar C

void                            // tipe data implementasi fungsi harus ada diatas nama fungsi
RenderDisplay(void)             // nama fungsi dan definisi parameter harus mengikuti-
{                               // gaya Object-Pascal / Delphi
      ...
}

template <typename T> struct    // tipe data, dan definisi template mengikuti gaya-
vec2f_t {                       // GNU Coding standard
    T x, y;
    ...  
}

int                             // mohon gunakan integer sebagai tipe data fungsi utama
main(int argc, char ** argv)
{
    ...

    return exitCode;
}
```

#### Implementation File

Setiap Implementation File / Header file, diwajibkan menggunakan proteksi header

berikut adalah contoh pada file **`makanan.hh`**

```c++
#ifndef MAKANAN_HH // Proteksi Header
#define MAKANAN_HH // Buka Proteksi Header

// Code utama mulai disini
class Makanan{
  public:
    Makanan(int, int);
  private:
    void makan(Makanan);
}

void Makanan::Makanan(int x, int y);
void Makanan::makan(Makanan makanan);
// Code utama selesai


#endif // Tutup Proteksi Header
```

#### Penjelasan Lisensi Pada Source File

Setiap File diwajibkan menautkan potongan lisensi berikut pada baris pertama pada file tersebut

```txt
<Satu baris penjelasan singkat mengenai apa yang dilakukan file ini>
Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele, <Nama Anda>

This program is free software: you can redistribute it and/or modifyv
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```

contoh tautan potongan lisensi pada file **`makanan.hh`**

```c++
/* Mendefinisikan class makanan dan metoda metoda penunjangnya
 * Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 **/

#ifndef MAKANAN_HH
#define MAKANAN_HH

class Makanan{
  public:
    Makanan(int, int);
  private:
    void makan(Makanan);
}

void Makanan::Makanan(int x, int y);
void Makanan::makan(Makanan makanan);

#endif
```