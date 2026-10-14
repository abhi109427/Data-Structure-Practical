#include <stdio.h>

int readNumber(char **p, int *number) {
    int digits = 0;
    *number = 0;

    while (**p >= '0' && **p <= '9') {
        if (++digits > 2) return 0;
        *number = *number * 10 + (**p - '0');
        (*p)++;
    }
    return digits > 0;
}

int applyOperator(int *total, int *term, int *sign, int number, char op) {
    switch (op) {
        case '*': *term *= number; break;
        case '/':
            if (number == 0) return 0;
            *term /= number;
            break;
        case '+':
        case '-':
            *total += *sign * *term;
            *sign = (op == '+') ? 1 : -1;
            *term = number;
            break;
        default: return 0;
    }
    return 1;
}

int main(void) {
    char expression[100], *p;
    int total = 0, term, sign = 1, number;

    printf("Enter expression: ");
    if (scanf("%99s", expression) != 1) return 1;

    p = expression;
    if (!readNumber(&p, &term)) {
        printf("Invalid expression\n");
        return 1;
    }

    while (*p != '\0') {
        char op = *p++;
        if (!readNumber(&p, &number) ||
            !applyOperator(&total, &term, &sign, number, op)) {
            printf("Invalid expression\n");
            return 1;
        }
    }

    printf("Result = %d\n", total + sign * term);
    return 0;
}
