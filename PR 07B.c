
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *p, *n;
    int ch, x, key, i;

    printf("Enter number of nodes: ");
    scanf("%d", &x);

    for (i = 0; i < x; i++) {
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
    }

    do {
        printf("\n1.Delete First\n2.Delete Last");
        printf("\n3.Delete After Node\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            if (!head) printf("List is empty\n");
            else if (head->next == head) {
                free(head);
                head = NULL;
            } else {
                temp = head;
                while (temp->next != head) temp = temp->next;
                p = head;
                head = head->next;
                temp->next = head;
                free(p);
            }
            break;

        case 2:
            if (!head) printf("List is empty\n");
            else if (head->next == head) {
                free(head);
                head = NULL;
            } else {
                temp = head;
                while (temp->next->next != head) temp = temp->next;
                p = temp->next;
                temp->next = head;
                free(p);
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

            if (temp->data == key && temp->next != head) {
                p = temp->next;
                temp->next = p->next;
                free(p);
            } else printf("Node or next node not found\n");
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
