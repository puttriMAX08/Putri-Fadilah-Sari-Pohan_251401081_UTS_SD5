#include <iostream>
#include <string>
using namespace std;

int main() {
    char stack[100];
    string kata, balik = "";
    int top = -1;

    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        top++;
        stack[top] = kata[i];
    }

    while (top >= 0) {
        balik += stack[top];
        top--;
    }

    cout << "Kata dibalik : " << balik << endl;

    if (kata == balik) {
        cout << "Kesimpulan : Kata ini adalah palindrom";
    } else {
        cout << "Kesimpulan : Bukan palindrom";
    }

    return 0;
}