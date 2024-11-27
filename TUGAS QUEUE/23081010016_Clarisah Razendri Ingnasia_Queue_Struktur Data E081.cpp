#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur node untuk elemen queue
struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Struktur queue
struct queue {
    int count;
    int maxSize;  // Menyimpan ukuran maksimal dari queue
    node *front;
    node *rear;
};
typedef struct queue queue;

// Variabel global queue
queue myQueue;

// Membuat queue baru
queue createQueue(int maxSize) {
    myQueue.count = 0;
    myQueue.maxSize = maxSize;  // Atur ukuran maksimal queue
    myQueue.front = NULL;
    myQueue.rear = NULL;
    return myQueue;
}

// Deklarasi fungsi
void enqueue();
void dequeue();
void queuefront();
void queuerear();
bool emptyqueue();
bool fullqueue();
void queueCount();
void destroyqueue();
void displayqueue();

int main() {
    int pilih, maxQueueSize;

    // Meminta input ukuran maksimal queue
    printf("Masukkan ukuran maksimal queue: ");
    scanf("%d", &maxQueueSize);

    // Membuat queue dengan ukuran maksimal
    createQueue(maxQueueSize);

    do {
        system("cls"); // Membersihkan layar terminal 
        printf("Menu Pilihan:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Queue Front\n");
        printf("4. Queue Rear\n");
        printf("5. Destroy Queue\n");
        printf("6. Full Queue\n");
        printf("7. Empty Queue\n");
        printf("8. Queue Count\n");
        printf("9. Display Queue\n");
        printf("Pilih menu (0 untuk keluar): ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                queuefront();
                break;
            case 4:
                queuerear();
                break;
            case 5:
                destroyqueue();
                break;
            case 6:
                printf(fullqueue() ? "Queue penuh!\n" : "Queue tidak penuh.\n");
                getchar();
                getchar(); // Menunggu input untuk kembali ke menu
                break;
            case 7:
                printf(emptyqueue() ? "Queue kosong!\n" : "Queue tidak kosong.\n");
                getchar();
                getchar(); // Menunggu input untuk kembali ke menu
                break;
            case 8:
                queueCount();
                break;
            case 9:
                displayqueue();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
                getchar();
                getchar(); // Menunggu input untuk kembali ke menu
                break;
        }
    } while (pilih != 0);

    return 0;
}

// Fungsi untuk menambahkan elemen ke queue
void enqueue() {
    if (fullqueue()) {
        printf("Queue penuh!\n");
        getchar();
        getchar();
        return;
    }
    
    int bil;
    node *pNew = (node *)malloc(sizeof(node));

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (myQueue.front == NULL) {
            myQueue.front = pNew;
        } else {
            myQueue.rear->next = pNew;
        }
        myQueue.rear = pNew;
        myQueue.count++;
        printf("Data %d berhasil ditambahkan ke dalam queue.\n", bil);
        getchar();
        getchar();
    } else {
        printf("Alokasi memori gagal.\n");
        getchar();
        getchar();
    }
}

// Fungsi untuk menghapus elemen dari queue
void dequeue() {
    if (emptyqueue()) {
        printf("Queue kosong!\n");
        getchar();
        getchar();
        return;
    }

    node *dltPtr = myQueue.front;
    myQueue.front = myQueue.front->next;

    if (myQueue.front == NULL) {
        myQueue.rear = NULL;
    }

    printf("Data %d berhasil dihapus.\n", dltPtr->data);
    free(dltPtr);
    myQueue.count--;
    getchar();
    getchar();
}

// Fungsi untuk menampilkan elemen di depan queue
void queuefront() {
    if (emptyqueue()) {
        printf("Queue kosong, tidak ada elemen di depan!\n");
        getchar();
        getchar();
    } else {
        printf("Data paling depan dalam queue: %d\n", myQueue.front->data);
        getchar();
        getchar();
    }
}

// Fungsi untuk menampilkan elemen di belakang queue
void queuerear() {
    if (emptyqueue()) {
        printf("Queue kosong, tidak ada elemen di belakang!\n");
        getchar();
        getchar();
    } else {
        printf("Data paling belakang dalam queue: %d\n", myQueue.rear->data);
        getchar();
        getchar();
    }
}

// Fungsi untuk memeriksa apakah queue kosong
bool emptyqueue() {
    return myQueue.count == 0;
}

// Fungsi untuk memeriksa apakah queue penuh
bool fullqueue() {
    return myQueue.count >= myQueue.maxSize;  // Periksa apakah queue penuh berdasarkan ukuran maksimal
}

// Fungsi untuk menampilkan jumlah elemen dalam queue
void queueCount() {
    printf("Jumlah data yang ada dalam queue: %d\n", myQueue.count);
    getchar();
    getchar();
}

// Fungsi untuk menghancurkan queue
void destroyqueue() {
    while (myQueue.front != NULL) {
        node *temp = myQueue.front;
        myQueue.front = myQueue.front->next;
        free(temp);
    }
    myQueue.rear = NULL;
    myQueue.count = 0;
    printf("Queue berhasil dikosongkan.\n");
    getchar();
    getchar();
}

// Fungsi untuk menampilkan semua elemen dalam queue
void displayqueue() {
    if (emptyqueue()) {
        printf("Queue kosong, tidak ada yang bisa ditampilkan.\n");
        getchar();
        getchar();
    } else {
        node *temp = myQueue.front;
        printf("Isi Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        getchar();
        getchar();
    }
}
