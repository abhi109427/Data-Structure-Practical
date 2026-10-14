
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *p, *n;
    int ch, x, key;

    /* Create initial list */
    printf("Enter number of nodes: ");
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        n = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &n->data);
        n->next = NULL;

        if (!head) head = n;
        else {
            temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }

    do {
        printf("\n1.Delete First  \n2.Delete Last");
        printf("\n3.Delete After Node  \n4.Display  \n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            if (head) {
                temp = head;
                head = head->next;
                free(temp);
            } else printf("List is empty\n");
            break;

        case 2:
            if (!head) printf("List is empty\n");
            else if (!head->next) {
                free(head);
                head = NULL;
            } else {
                temp = head;
                while (temp->next->next) temp = temp->next;
                free(temp->next);
                temp->next = NULL;
            }
            break;

        case 3:
            printf("Enter node value: ");
            scanf("%d", &key);
            temp = head;
            while (temp && temp->data != key)
                temp = temp->next;

            if (temp && temp->next) {
                p = temp->next;
                temp->next = p->next;
                free(p);
            } else printf("Node or next node not found\n");
            break;

        case 4:
            temp = head;
            while (temp) {
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
