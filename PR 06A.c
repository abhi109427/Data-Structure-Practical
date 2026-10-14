
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *n;
    int ch, x, key;

    do {
        printf("\n1.Insert Beginning\n2.Insert End");
        printf("\n3.Insert After Node\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            n = malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &x);
            n->data = x;
            n->next = head;
            head = n;
            break;

        case 2:
            n = malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &x);
            n->data = x;
            n->next = NULL;

            if (head == NULL)
                head = n;
            else {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = n;
            }
            break;

        case 3:
            printf("Enter node value: ");
            scanf("%d", &key);
            temp = head;

            while (temp != NULL && temp->data != key)
                temp = temp->next;

            if (temp == NULL)
                printf("Node not found\n");
            else {
                n = malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &x);
                n->data = x;
                n->next = temp->next;
                temp->next = n;
            }
            break;

        case 4:
            temp = head;
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
            break;

        case 5:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);

    return 0;
}
