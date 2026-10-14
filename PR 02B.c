#include <stdio.h>
void callByValue(int x) {
    printf("\nInside call by value: x = %d", x);
}

void callByReference(int *x) {
    printf("\nInside call by reference: y= %d", *x);
}

int main() {
    int a, b;

    printf("Enter a = ");
    scanf("%d", &a);
    printf("Enter b = ");
    scanf("%d", &b);

    printf("\nBefore call by value: a = %d \nBefore call by reference: b = %d", a, b);
    callByValue(a);
    callByReference(&b);
    printf("\nAfter call by value: a = %d \nAfter call by reference: b = %d", a, b);

    return 0;
}
