#include <stdio.h>
int main() {
    int a[100], n, i, ch, pos, x, found;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    do {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Search \n5.Exit \nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &x);
            if (pos < 1 || pos > n + 1 || n == 100) printf("Invalid position/full array\n");
            else {
                for (i = n; i >= pos; i--) a[i] = a[i - 1];
                a[pos - 1] = x; n++;
            }
        } else if (ch == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            if (pos < 1 || pos > n) printf("Invalid position\n");
            else {
                for (i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
                n--;
            }
        } else if (ch == 3) {
            for (i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
        } else if (ch == 4) {
            printf("Enter value to search: "); scanf("%d", &x);
            found = 0;
            for (i = 0; i < n; i++)
                if (a[i] == x) { printf("Found at position %d\n", i + 1); found = 1; break; }
            if (!found) printf("Not found\n");
        }
    } while (ch != 5);
    return 0;
}
