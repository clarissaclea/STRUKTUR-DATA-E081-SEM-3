#include <iostream>
using namespace std;

// Mendefinisikan struktur Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Mendefinisikan struktur Stack
typedef struct Stack {
    int count;
    struct Node* top;
    const int MAX_SIZE = 10;  // Menentukan kapasitas maksimal stack
} Stack;

Stack stack;  // Global stack

// Fungsi untuk membuat stack kosong
void createStack() {
    stack.count = 0;
    stack.top = NULL;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return stack.count == 0;
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull() {
    return stack.count >= stack.MAX_SIZE;
}

// Fungsi untuk menambah data ke dalam stack (Push)
void push(int data) {
    if (isFull()) {
        cout << "Stack penuh! Tidak bisa menambah data.\n";
        return;
    }

    Node* newPtr = new Node;  // Alokasi memori untuk node baru
    if (newPtr == NULL) {
        cout << "Alokasi memori gagal!";
        return;
    }

    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
    cout << "Data " << data << " berhasil ditambahkan.\n";
}

// Fungsi untuk menghapus data dari stack (Pop)
void pop() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data untuk dihapus.\n";
        return;
    }

    Node* dltPtr = stack.top;
    stack.top = stack.top->next;  // Memindahkan top ke node berikutnya
    stack.count--;
    delete dltPtr;  // Menghapus node
    cout << "Data berhasil dihapus.\n";
}

// Fungsi untuk melihat data teratas stack (Stack Top)
void stackTop() {
    if (isEmpty()) {
        cout << "Stack kosong! Tidak ada data pada top.\n";
        return;
    }
    cout << "Nilai pada top: " << stack.top->data << endl;
}

// Fungsi untuk mengecek apakah stack kosong (Empty Stack)
void emptyStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
    } else {
        cout << "Stack tidak kosong.\n";
    }
}

// Fungsi untuk mengecek apakah stack penuh (Full Stack)
void fullStack() {
    if (isFull()) {
        cout << "Stack penuh.\n";
    } else {
        cout << "Stack belum penuh.\n";
    }
}

// Fungsi untuk menghitung jumlah data dalam stack (Stack Count)
int stackCount() {
    return stack.count;
}

// Fungsi untuk menghancurkan stack (Destroy Stack)
void destroyStack() {
    while (!isEmpty()) {
        pop();  // Hapus semua elemen dalam stack
    }
    cout << "Stack telah dikosongkan.\n";
}

// Fungsi untuk mencetak isi stack (Print Stack)
void printStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
        return;
    }
    Node* current = stack.top;
    cout << "Isi stack dari atas ke bawah: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi utama (main)
int main() {
    int pilihan, value;
    createStack();  // Membuat stack kosong

    do {
        cout << "\nMenu Stack:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Stack Top\n";
        cout << "4. Empty Stack\n";
        cout << "5. Full Stack\n";
        cout << "6. Stack Count\n";
        cout << "7. Destroy Stack\n";
        cout << "8. Print Stack\n";
        cout << "9. Exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                cout << "Masukkan nilai untuk di push: ";
                cin >> value;
                push(value);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                stackTop();
                break;
            case 4: 
                emptyStack();
                break;
            case 5: 
                fullStack();
                break;
            case 6: 
                cout << "Ukuran stack: " << stackCount() << endl;
                break;
            case 7: 
                destroyStack();
                break;
            case 8: 
                printStack();
                break;
            case 9: 
                cout << "Exiting...\n";
                break;
            default: 
                cout << "Input tidak valid!\n";
        }
    } while (pilihan != 9);  // Keluar jika pilihan 9

    return 0;
}

