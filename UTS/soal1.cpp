#include <iostream>
using namespace std;

int main() {
    int array[2][3][4];
    int maksimal[3][4];
    int rataRata[3][4];

    int ganjil = 1;
    int kelipatan = 5;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            array[0][i][j] = ganjil;
            ganjil = ganjil + 2;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            array[1][i][j] = kelipatan;
            kelipatan = kelipatan + 5;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {

            if (array[0][i][j] > array[1][i][j]) {
                maksimal[i][j] = array[0][i][j];
            } else {
                maksimal[i][j] = array[1][i][j];
            }

            rataRata[i][j] =
                (array[0][i][j] + array[1][i][j]) / 2;
        }
    }

    cout << "\nRata-rata:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << rataRata[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Nilai Maksimal:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << maksimal[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}