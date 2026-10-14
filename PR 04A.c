#include <stdio.h>
#include <ctype.h>
char st[100];
int top = -1;
void push(char c) { st[++top] = c; }
char pop() { return st[top--]; }
int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int main() {
    char in[100], c;
    int i;
    printf("Enter infix expression: ");
    scanf("%99s", in);
    printf("Postfix: ");
    for (i = 0; in[i]; i++) {
        c = in[i];
        if (isalnum((unsigned char)c)) printf("%c", c);
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top >= 0 && st[top] != '(') printf("%c", pop());
            if (top >= 0) pop();
        } else {
            while (top >= 0 && st[top] != '(' && prec(st[top]) >= prec(c))
                printf("%c", pop());
            push(c);
        }
    }
    while (top >= 0) printf("%c", pop());
    printf("\n");
    return 0;
}
