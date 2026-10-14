#include <stdio.h>
#define SIZE 5

void enqueue(int q[], int *rear) {
    if (*rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &q[++(*rear)]);
    }
}

void dequeue(int q[], int *front, int *rear) {
    if (*front > *rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted: %d\n", q[(*front)++]);
        if (*front > *rear) {
            *front = 0;
            *rear = -1;
        }
    }
}

void display(int q[], int front, int rear) {
    int i;
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        for (i = front; i <= rear; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

int main(void) {
    int q[SIZE], front = 0, rear = -1, ch;

    do {
        printf("\n1.Enqueue  \n2.Dequeue  \n3.Display  \n4.Exit \nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue(q, &rear);
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
