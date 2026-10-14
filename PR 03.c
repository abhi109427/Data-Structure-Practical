#include <stdio.h>
#define SIZE 5

void push(int s[], int *top) {
    int x;
    if (*top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &x);
        s[++(*top)] = x;
    }
}

void pop(int s[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Deleted: %d\n", s[(*top)--]);
    }
}

void peek(int s[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top: %d\n", s[top]);
    }
}

void display(int s[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", s[i]);
        }
    }
}

int main() {
    int s[SIZE], top = -1, ch;
    do {
        printf("\n1.Push  \n2.Pop  \n3.Peek  \n4.Display \n5.Exit \nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push(s, &top);
                break;
            case 2:
                pop(s, &top);
                break;
            case 3:
                peek(s, top);
                break;
            case 4:
                display(s, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 5);
    return 0;
}
