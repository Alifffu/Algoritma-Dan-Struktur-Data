#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
        cout << "Data bertambah\n";
    } else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    } else {
        cout << "Data sudah ada\n";
    }
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    int pil, data;
    Node *pohon = NULL;

    do {
        system("cls");
        cout << "=== TREE ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. PreOrder\n";
        cout << "3. InOrder\n";
        cout << "4. PostOrder\n";
        cout << "5. Exit\n";
        cout << "===========================\n";
        cout << "Pilihan : ";
        cin >> pil;

        switch (pil) {
        case 1:
            cout << "\nMasukkan Data Baru : ";
            cin >> data;
            tambah(&pohon, data);
            break;
        case 2:
            cout << "\n=== PREORDER TRAVERSAL ===\n";
            if (pohon != NULL)
                preOrder(pohon);
            else
                cout << "Tree masih kosong!";
            cout << endl;
            break;
        case 3:
            cout << "\n=== INORDER TRAVERSAL ===\n";
            if (pohon != NULL)
                inOrder(pohon);
            else
                cout << "Tree masih kosong!";
            cout << endl;
            break;
        case 4:
            cout << "\n=== POSTORDER TRAVERSAL ===\n";
            if (pohon != NULL)
                postOrder(pohon);
            else
                cout << "Tree masih kosong!";
            cout << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "Pilihan tidak valid!\n";
        }

        cout << "\n\nTekan enter untuk melanjutkan...";
        _getch();

    } while (pil != 5);

    return EXIT_SUCCESS;
}