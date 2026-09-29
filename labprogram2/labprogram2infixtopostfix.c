#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return (top == -1) ? '\0' : stack[top--];
}

int prec(char c) {
    return (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;
}

int main() {
    char infix[100], c;
    int i = 0;

    printf("Enter infix: ");
    scanf("%s", infix);

    printf("Postfix: ");
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            char x;
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
