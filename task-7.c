#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void reduce() {
    // Example grammar:
    // E->E+E | E*E | i

    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("Reduce: E->E+E\n");
    }
    else if (top >= 2 && stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("Reduce: E->E*E\n");
    }
    else if (stack[top] == 'i') {
        stack[top] = 'E';
        printf("Reduce: E->i\n");
    }
}

int main() {
    int i = 0;

    printf("Enter input (end with $): ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (input[i] != '$') {
        push(input[i]);
        printf("%s\t%s\tShift\n", stack, input + i + 1);

        reduce(); // try reducing after each shift
        i++;
    }

    if (top == 0 && stack[top] == 'E')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}
