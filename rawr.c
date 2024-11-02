#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_TYPE 50

typedef struct {
    char kode[20];
    char nama[MAX_TITLE];
    char jenis[MAX_TYPE];
    float harga;
} Buku;

Buku daftarBuku[MAX_BOOKS];
int jumlahBuku = 0;

void simpanDataKeFile() {
    FILE *file = fopen("databuku.txt", "w");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%s,%s,%s,%.2f\n", daftarBuku[i].kode, daftarBuku[i].nama, daftarBuku[i].jenis, daftarBuku[i].harga);
    }

    fclose(file);
}

void inputBuku() {
    if (jumlahBuku >= MAX_BOOKS) {
        printf("Jumlah buku sudah mencapai batas maksimum.\n");
        return;
    }

    Buku bukuBaru;

    printf("Masukkan kode buku: ");
    scanf("%s", bukuBaru.kode);
    printf("Masukkan nama buku: ");
    getchar();  
    fgets(bukuBaru.nama, MAX_TITLE, stdin);
    bukuBaru.nama[strcspn(bukuBaru.nama, "\n")] = '\0';  
    printf("Masukkan jenis buku: ");
    fgets(bukuBaru.jenis, MAX_TYPE, stdin);
    bukuBaru.jenis[strcspn(bukuBaru.jenis, "\n")] = '\0';  
    printf("Masukkan harga buku: ");
    scanf("%f", &bukuBaru.harga);

    daftarBuku[jumlahBuku] = bukuBaru;
    jumlahBuku++;

    simpanDataKeFile();

    printf("Buku berhasil ditambahkan dan disimpan ke file!\n");
}

void lihatRiwayat() {
    printf("Riwayat Penjualan:\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%d. Kode: %s, Nama: %s, Jenis: %s, Harga: %.2f\n", 
               i + 1, daftarBuku[i].kode, daftarBuku[i].nama, 
               daftarBuku[i].jenis, daftarBuku[i].harga);
    }
}

int main() {
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Input Data Buku\n");
        printf("2. Lihat Riwayat\n");
        printf("3. Exit\n");
        printf("Pilih opsi (1-3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputBuku();
                break;
            case 2:
                lihatRiwayat();
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 3);

    return 0;
}
