#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int angka) {
    Node* baru = new Node;
    baru->data = angka;
    baru->left = NULL;
    baru->right = NULL;

    return baru;
}

Node* insert(Node* root, int angka) {
    if (root == NULL) {
        return buatNode(angka);
    }

    if (angka < root->data) {
        root->left = insert(root->left, angka);
    }
    else if (angka > root->data) {
        root->right = insert(root->right, angka);
    }

    return root;
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int nilaiTerbesar(Node* root) {
    Node* bantu = root;

    while (bantu->right != NULL) {
        bantu = bantu->right;
    }

    return bantu->data;
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0 berhenti) : ";

    while (true) {
        cin >> angka;

        if (angka == 0) {
            break;
        }

        root = insert(root, angka);
    }

    if (root == NULL) {
        cout << "Tree kosong";
        return 0;
    }

    cout << "Post-Order : ";
    postOrder(root);

    cout << "\nNilai terbesar : "
         << nilaiTerbesar(root);

    cout << "\nRoot : "
         << root->data;

    return 0;
}