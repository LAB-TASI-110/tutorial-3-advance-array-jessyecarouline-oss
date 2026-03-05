#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf

// Deklarasi konstanta untuk ukuran maksimum array nilai.
// Ini membantu kita membuat array statis yang cukup besar.
#define MAX_N 1000

// Fungsi untuk membaca jumlah nilai (n) dan nilai-nilai tugas ke dalam array
void read_input_values(int *n_ptr, int scores[]) {
    // Membaca bilangan bulat positif n
    scanf("%d", n_ptr);

    // Membaca n baris nilai tugas dan menyimpannya ke dalam array scores
    for (int i = 0; i < *n_ptr; i++) {
        scanf("%d", &scores[i]);
    }
}

// Fungsi untuk menghitung total dari seluruh nilai dalam array
int calculate_sum(int n, int scores[]) {
    int total_sum = 0;
    // Melakukan iterasi untuk menjumlahkan setiap nilai
    for (int i = 0; i < n; i++) {
        total_sum += scores[i];
    }
    return total_sum;
}

// Fungsi untuk menghitung nilai rata-rata
double calculate_average(int n, int sum) {
    // Penting: Konversi 'sum' ke double sebelum pembagian agar hasilnya floating-point
    // dan tidak terjadi pemotongan hasil karena integer division.
    return (double)sum / n;
}

// Fungsi utama program
int main() {
    int n;             // Variabel untuk menyimpan jumlah nilai
    int scores[MAX_N]; // Array untuk menyimpan nilai-nilai tugas

    // 1. Membaca n dan nilai-nilai tugas
    read_input_values(&n, scores);

    // 2. Menghitung total seluruh nilai
    int total_nilai = calculate_sum(n, scores);

    // 3. Menghitung nilai rata-rata
    double rata_rata_nilai = calculate_average(n, total_nilai);

    // 4. Menampilkan hasil sesuai format yang diminta
    // %d untuk bilangan bulat (total_nilai)
    // %.2f untuk floating-point dengan 2 digit presisi di belakang koma (rata_rata_nilai)
    printf("%d\n", total_nilai);
    printf("%.2f\n", rata_rata_nilai);

    return 0; // Mengindikasikan program berjalan sukses
}