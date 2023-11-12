#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// Ukuran papan Sudoku
const int N = 9;

// Fungsi untuk mencetak papan Sudoku
void cetakPapan(int papan[N][N]) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << " | ";
            }
            cout << papan[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk memeriksa apakah suatu nilai dapat ditempatkan di posisi tertentu
bool bisaDitempatkan(int papan[N][N], int row, int col, int num) {
    // Periksa baris
    for (int i = 0; i < N; i++) {
        if (papan[row][i] == num) {
            return false;
        }
    }

    // Periksa kolom
    for (int i = 0; i < N; i++) {
        if (papan[i][col] == num) {
            return false;
        }
    }

    // Periksa kotak 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fungsi rekursif untuk mencari solusi Sudoku
bool solveSudoku(int papan[N][N], int &iterasi) {
    int row, col;

    // Cari sel kosong
    bool foundEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            iterasi++; // Tambahkan iterasi
            if (papan[row][col] == 0) {
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty) {
            break;
        }
    }

    // Jika tidak ada sel kosong, maka Sudoku telah terselesaikan
    if (!foundEmpty) {
        return true;
    }

    // Coba semua angka dari 1 hingga 9
    for (int num = 1; num <= 9; num++) {
        if (bisaDitempatkan(papan, row, col, num)) {
            papan[row][col] = num;

            // Rekursif untuk mencoba angka selanjutnya
            if (solveSudoku(papan, iterasi)) {
                return true;
            }

            // Jika tidak ada solusi, kembalikan nilai ke 0
            papan[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int papan[N][N];
    int soal;

    cout << "Masukan Nomor Soal yang mau diselesaikan (1/2/3/4): ";
    cin >> soal;
    switch (soal) {
        case 1: {
            ifstream file("Soal1Sudoku.txt");
            if (!file) {
                cerr << "Gagal membaca file Soal1Sudoku.txt" << endl;
                return 1;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    file >> papan[i][j];
                }
            }
            break;
        }

        case 2: {
            ifstream file("Soal2Sudoku.txt");
            if (!file) {
                cerr << "Gagal membaca file Soal2Sudoku.txt" << endl;
                return 1;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    file >> papan[i][j];
                }
            }
            break;
        }

        case 3: {
            ifstream file("Soal3Sudoku.txt");
            if (!file) {
                cerr << "Gagal membaca file Soal3Sudoku.txt" << endl;
                return 1;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    file >> papan[i][j];
                }
            }
            break;
        }

        case 4: {
            ifstream file("Soal4Sudoku.txt");
            if (!file) {
                cerr << "Gagal membaca file Soal3Sudoku.txt" << endl;
                return 1;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    file >> papan[i][j];
                }
            }
            break;
        }

        default:
            cout << "Nomor soal tidak valid. Silakan pilih nomor soal 1, 2, atau 3." << endl;
            return 1;
    }

    int iterasi = 0; // Variabel untuk melacak jumlah iterasi
    clock_t start = clock(); // Catat waktu awal

    if (solveSudoku(papan, iterasi)) {
        cout << "Solusi Sudoku:\n";
        cetakPapan(papan);
    } else {
        cout << "Tidak ada solusi Sudoku yang valid.\n";
    }

    clock_t end = clock(); // Catat waktu akhir
    double waktuEksekusi = double(end - start) / CLOCKS_PER_SEC; // Hitung waktu eksekusi dalam detik

    cout << "Jumlah Iterasi: " << iterasi << endl;
    cout << "Waktu Eksekusi: " << waktuEksekusi << " detik" << endl;

    return 0;
}
