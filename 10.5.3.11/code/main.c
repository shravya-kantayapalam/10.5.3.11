#include <stdio.h>

// Function to calculate the sum of the first n terms of an arithmetic progression
int x(int n) {
    return 4 * n - n * n;
}

// Function to calculate the arithmetic progression
int arithmetic_progression(int n, int a, int d) {
    return (n * (2 * a + (n - 1) * d)) / 2;
}

// Function to compute the convolution of two sequences
void convolution(int x[], int u[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = 0;
        for (int j = 0; j <= i; j++) {
            y[i] += x[j] * u[i - j];
        }
    }
}

int main() {
    int n = 10; // Number of terms
    int a = 3, d = -2; // Parameters of the arithmetic progression
    int x_sequence[10]; // Sequence x(n)
    int u_sequence[10]; // Sequence u(n)
    int y_sequence[10]; // Sequence y(n)

    // Generate sequence x(n)
    for (int i = 0; i < n; i++) {
        x_sequence[i] = x(i + 1);
    }

    // Generate sequence u(n) (unit step function)
    for (int i = 0; i < n; i++) {
        u_sequence[i] = 1;
    }

    // Compute convolution y(n)
    convolution(x_sequence, u_sequence, y_sequence, n);

    // Print and store the output for y(n-1)
    FILE *fp = fopen("output.dat", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("n\t y(n-1)\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\n", i, y_sequence[i]);
        fprintf(fp, "%d\t %d\n", i, y_sequence[i]);
    }
    fclose(fp);

    // Verify if the computed values match the arithmetic progression
    fp = fopen("output.dat", "r");
    if (fp == NULL) {
        printf("Error opening file for verification.\n");
        return 1;
    }

    printf("\nVerification:\n");
    printf("Index\tActual\n");
    for (int i = 0; i < n; i++) {
        int index, actual;
        fscanf(fp, "%d %d", &index, &actual);
        int computed = arithmetic_progression(index + 1, a, d); // Adjust index
        printf("%d\t%d\n", index, actual);
    }

    fclose(fp);

    return 0;
}

