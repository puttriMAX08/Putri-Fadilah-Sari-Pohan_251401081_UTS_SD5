#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int harga;
    Node* next;
};

Node* head = NULL;

void insertTail(string nama, int harga) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->harga = harga;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;

        while (bantu->next != NULL) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }
}

void deleteHead() {
    if (head == NULL) {
        return;
    }

    Node* hapus = head;
    head = head->next;
    delete hapus;
}

void deleteTail() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* bantu = head;

    while (bantu->next->next != NULL) {
        bantu = bantu->next;
    }

    delete bantu->next;
    bantu->next = NULL;
}

void tampilkan() {
    Node* bantu = head;
    int no = 1;

    cout << "\nList Barang mewah:\n";

    while (bantu != NULL) {
        if (bantu->harga > 100000) {
            cout << no << " | " << bantu->nama
                 << " (Rp" << bantu->harga << ")" << endl;
            no++;
        }

        bantu = bantu->next;
    }
}

int main() {
    int pilih, harga;
    string nama;

    do {
        cout << "\nPilih menu (1 - 4)\n";
        cout << "1. Insert tail\n";
        cout << "2. Delete head\n";
        cout << "3. Delete tail\n";
        cout << "4. Tampilkan barang mewah\n";
        cout << "Pilihan: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Nama barang: ";
            getline(cin >> ws, nama);

            cout << "Harga: ";
            cin >> harga;

            insertTail(nama, harga);
        }
        else if (pilih == 2) {
            deleteHead();
        }
        else if (pilih == 3) {
            deleteTail();
        }
        else if (pilih == 4) {
            tampilkan();
        }

    } while (pilih != 4);

    return 0;
}