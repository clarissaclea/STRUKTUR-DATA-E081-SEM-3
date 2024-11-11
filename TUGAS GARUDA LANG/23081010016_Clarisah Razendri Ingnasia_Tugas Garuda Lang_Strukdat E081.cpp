#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fungsi untuk memeriksa apakah karakter adalah tanda buka
bool adalah_tanda_buka(char karakter) {
    return karakter == '(' || karakter == '{' || karakter == '[';
}

// Fungsi untuk memeriksa apakah karakter adalah tanda tutup
bool adalah_tanda_tutup(char karakter) {
    return karakter == ')' || karakter == '}' || karakter == ']';
}

// Fungsi untuk memeriksa kecocokan antara tanda buka dan tanda tutup
bool tanda_sesuai(char tanda_buka, char tanda_tutup) {
    return (tanda_buka == '(' && tanda_tutup == ')') ||
           (tanda_buka == '{' && tanda_tutup == '}') ||
           (tanda_buka == '[' && tanda_tutup == ']');
}

// Fungsi utama untuk memeriksa apakah tanda kurung dalam kode seimbang
bool periksa_keseimbangan_tanda(const char* kode) {
    char stack[1000];  // Array untuk menyimpan tanda buka
    int indeks_puncak = -1;  // Posisi teratas yang ada di stack

    for (int i = 0; kode[i] != '\0'; i++) {
        char karakter = kode[i];
        
        // Jika karakter adalah tanda buka, tambahkan ke stack
        if (adalah_tanda_buka(karakter)) {
            if (indeks_puncak < 999) {
                stack[++indeks_puncak] = karakter;
            } else {
                printf("Kesalahan: Stack penuh! Terlalu banyak tanda buka.\n");
                return false;
            }
        }
        // Jika karakter adalah tanda tutup, periksa apakah sesuai dengan tanda di stack
        else if (adalah_tanda_tutup(karakter)) {
            if (indeks_puncak == -1) {
                printf("Kesalahan: Tanda tutup '%c' tidak memiliki pasangan!\n", karakter);
                return false;
            }
            char tanda_teratas = stack[indeks_puncak--];
            if (!tanda_sesuai(tanda_teratas, karakter)) {
                printf("Kesalahan: Tanda buka '%c' tidak sesuai dengan '%c'\n", tanda_teratas, karakter);
                return false;
            }
        }
    }

    // Jika stack tidak kosong, ada tanda buka yang tidak tertutup
    if (indeks_puncak != -1) {
        printf("Kesalahan: Ada tanda buka yang tidak tertutup!\n");
    }
    
    return indeks_puncak == -1;
}

// Fungsi untuk membaca kode dari input pengguna
void baca_kode(char* kode_lengkap, int ukuran_maks) {
    char baris[1000];  // Buffer sementara untuk setiap baris input

    // Menerima input dari pengguna
    printf("Masukkan kode yang ingin diperiksa (tekan Enter 2 kali untuk selesai):\n");

    while (1) {
        fgets(baris, sizeof(baris), stdin);

        // Jika pengguna menekan Enter dua kali, hentikan pengumpulan input
        if (strcmp(baris, "\n") == 0) {
            break;
        }

        // Jika panjang kode_lengkap melebihi ukuran maksimal, hentikan
        if (strlen(kode_lengkap) + strlen(baris) >= ukuran_maks) {
            printf("Peringatan: Kode terlalu panjang, tidak dapat diproses seluruhnya.\n");
            break;
        }

        // Tambahkan baris ke kode_lengkap
        strcat(kode_lengkap, baris);
    }
}

// Fungsi untuk membersihkan layar (opsional, tergantung sistem operasi)
void bersihkan_layar() {
    system(
        #ifdef _WIN32
            "cls"
        #else
            "clear"
        #endif
    );
}

int main() {
    char kode_lengkap[10000] = "";  // Buffer untuk menyimpan seluruh kode pengguna
    char pilihan;

    do {
        // Bersihkan layar setiap kali sebelum menerima input
        bersihkan_layar();

        // Baca kode dari input pengguna
        baca_kode(kode_lengkap, sizeof(kode_lengkap));

        // Pastikan kode tidak kosong, lalu periksa keseimbangan tanda
        if (strlen(kode_lengkap) > 0) {
            if (periksa_keseimbangan_tanda(kode_lengkap)) {
                printf("Hasil: Kode seimbang!\n");
            } else {
                printf("Hasil: Kode tidak seimbang.\n");
            }
        }

        // Reset kode_lengkap untuk input berikutnya
        kode_lengkap[0] = '\0';

        // Tanyakan pada pengguna apakah ingin memeriksa kode lain
        printf("Tekan 0 untuk keluar, atau tekan tombol lain untuk memeriksa kode lain: ");
        
        char buffer[10];
        fgets(buffer, sizeof(buffer), stdin);
        pilihan = buffer[0];

    } while (pilihan != '0');

    return 0;
}

