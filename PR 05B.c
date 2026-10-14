#include <stdio.h>
#define SIZE 5

void enqueue(int q[], int *front, int *rear) {
    int x;
    if ((*rear + 1) % SIZE == *front) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    if (*front == -1) *front = 0;
    *rear = (*rear + 1) % SIZE;
    q[*rear] = x;
}

void dequeue(int q[], int *front, int *rear) {
    if (*front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", q[*front]);
        if (*front == *rear) {
            *front = *rear = -1;
        } else {
            *front = (*front + 1) % SIZE;
        }
    }
}

void display(int q[], int front, int rear) {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    int q[SIZE], front = -1, rear = -1, ch;
    do {
        printf("\n1.Enqueue  \n2.Dequeue  \n3.Display  \n4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue(q, &front, &rear);
                break;
            case 2:
                dequeue(q, &front, &rear);
                break;
            case 3:
                display(q, front, rear);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}
