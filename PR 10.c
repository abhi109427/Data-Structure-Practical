
#include <stdio.h>

int main() {
    int a[50], n, i, j, temp, min, ch;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                for (i = 0; i < n - 1; i++)
                    for (j = 0; j < n - i - 1; j++)
                        if (a[j] > a[j + 1]) {
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                printf("Bubble Sort: ");
                break;

            case 2:
                for (i = 0; i < n - 1; i++) {
                    min = i;
                    for (j = i + 1; j < n; j++)
                        if (a[j] < a[min])
                            min = j;

                    temp = a[i];
                    a[i] = a[min];
                    a[min] = temp;
                }
                printf("Selection Sort: ");
                break;

            case 3:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

        if (ch == 1 || ch == 2) {
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
        }

    } while (ch != 3);

    return 0;
}