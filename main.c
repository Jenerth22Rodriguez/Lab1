#include <stdio.h>

// Function prototypes for assembly functions
extern int add(int a, int b);
extern int subtract(int a, int b);
extern int multiply(int a, int b);
extern int divide(int a, int b);
extern int modulus(int a, int b);

int main() {
    int choice, a, b;
    int result, remainder;

    while (1) {
        printf("Menu:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) break;

        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        switch (choice) {
            case 1:
                result = add(a, b);
                printf("Result: %d\n", result);
                break;
            case 2:
                result = subtract(a, b);
                printf("Result: %d\n", result);
                break;
            case 3:
                result = multiply(a, b);
                printf("Result: %d\n", result);
                break;
            case 4:
                if (b == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = divide(a, b);
                    remainder = modulus(a, b);
                    printf("Quotient: %d\n", result);
                    printf("Remainder: %d\n", remainder);
                }
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

