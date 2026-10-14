
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
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert After Node\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            n = malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &n->data);

            if (!head) {
                head = n;
                n->next = head;
            } else {
                temp = head;
                while (temp->next != head) temp = temp->next;
                n->next = head;
                temp->next = n;
                head = n;
            }
            break;

        case 2:
            n = malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &n->data);

            if (!head) {
                head = n;
                n->next = head;
            } else {
                temp = head;
                while (temp->next != head) temp = temp->next;
                temp->next = n;
                n->next = head;
            }
            break;

        case 3:
            printf("Enter node value: ");
            scanf("%d", &key);
            if (!head) {
                printf("List is empty\n");
                break;
            }
            temp = head;
            do {
                if (temp->data == key) break;
                temp = temp->next;
            } while (temp != head);

            if (temp->data == key) {
                n = malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &n->data);
                n->next = temp->next;
                temp->next = n;
            } else printf("Node not found\n");
            break;

        case 4:
            if (!head) printf("List is empty\n");
            else {
                temp = head;
                do {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                } while (temp != head);
                printf("(head)\n");
            }
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
