#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 3

typedef struct {
int count;
int front;
int rear;
int item[MAXQUEUE];
} QUEUE;

QUEUE antrean;

void inisialisasi(QUEUE *Q) {
Q->count = 0;
Q->front = 0;
Q->rear = 0;
}

int isEmpty(QUEUE *Q) {
    return (Q->count == 0);
}
int isFull(QUEUE *Q) {
    return (Q->count == MAXQUEUE);
}
void insert(QUEUE *Q, int data) {
    if (isFull(Q)) {
        printf("Antrean penuh %d\n", data);
        return;
    }
    Q->item[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->count++;
}

void hapus(QUEUE *Q) {
    if (isEmpty(Q)) {
        printf("kosong \n");
        return;
    }
    int data = Q->item[Q->front];
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->count--;
    printf("Menghapus data: %d\n", data);
}

void printQueue(QUEUE *Q) {
    if (isEmpty(Q)) {
        printf("Antrean kosong\n");
        return;
    }
    printf("Isi antrean: ");
    for (int i = 0; i < Q->count; i++) {
        int index = (Q->front + i) % MAXQUEUE;
        printf("%d ", Q->item[index]);
    }
    printf("\n");
}

int main() {
    inisialisasi(&antrean);

printf("masukkan 17\n");
insert(&antrean, 17);
printQueue(&antrean);

printf("masukkan 45\n");
insert(&antrean, 45);
printQueue(&antrean);

printf("masukkan 77\n");
insert(&antrean, 77);
printQueue(&antrean);

printf("hapus mahasiswa pertama\n");
hapus(&antrean);
printQueue(&antrean);

printf("masukkan 15\n");
insert(&antrean, 15);
printQueue(&antrean);

return 0;
}
