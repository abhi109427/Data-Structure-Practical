#include <stdio.h>
int main() {
    int a[100], n, i, *p;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    p = a + n - 1;
    printf("Reverse order: ");
    for (i = n - 1; i >= 0; i--) printf("%d ", *(p--));
    printf("\n");
    return 0;
}
