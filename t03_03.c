#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <limits.h> // Diperlukan untuk INT_MIN dan INT_MAX

// Deklarasi konstanta untuk ukuran maksimum array nilai.
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

// Fungsi untuk menghitung banyaknya mahasiswa yang nilainya >= rata-rata
int count_above_or_equal_average(int n, int scores[], double average) {
    int count = 0; // Inisialisasi counter
    // Iterasi melalui setiap nilai dalam array
    for (int i = 0; i < n; i++) {
        // Bandingkan nilai saat ini dengan rata-rata
        if (scores[i] >= average) {
            count++; // Jika lebih besar atau sama, increment counter
        }
    }
    return count; // Kembalikan total hitungan
}

// FUNGSI BARU: Untuk mencari nilai minimum dan maksimum dalam array
void find_min_max(int n, int scores[], int *min_val_ptr, int *max_val_ptr) {
    // Inisialisasi nilai minimum dan maksimum dengan nilai awal array.
    // Atau bisa juga dengan INT_MAX dan INT_MIN dari <limits.h> untuk kasus umum
    // tapi untuk array non-kosong, nilai pertama adalah inisialisasi yang aman.
    *min_val_ptr = scores[0];
    *max_val_ptr = scores[0];

    // Iterasi dari elemen kedua untuk membandingkan
    for (int i = 1; i < n; i++) {
        if (scores[i] < *min_val_ptr) {
            *min_val_ptr = scores[i];
        }
        if (scores[i] > *max_val_ptr) {
            *max_val_ptr = scores[i];
        }
    }
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

    // 4. Menghitung banyaknya mahasiswa yang nilainya >= rata-rata
    int count_ge_average = count_above_or_equal_average(n, scores, rata_rata_nilai);

    // 5. MENCARI NILAI MINIMUM DAN MAKSIMUM, KEMUDIAN MENGHITUNG RENTANG (modifikasi baru)
    int min_nilai, max_nilai;
    find_min_max(n, scores, &min_nilai, &max_nilai);
    int rentang_nilai = max_nilai - min_nilai;

    // 6. Menampilkan hasil sesuai format yang diminta
    printf("%d\n", total_nilai);
    printf("%.2f\n", rata_rata_nilai);
    printf("%d\n", count_ge_average);
    printf("%d\n", rentang_nilai); // Menampilkan rentang nilai baru

    return 0; // Mengindikasikan program berjalan sukses
}