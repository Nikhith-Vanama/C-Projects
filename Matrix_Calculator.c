#include <stdio.h>

// Function to read a matrix
void readMatrix(int mat[10][10], int rows, int cols, const char* name) {
    printf("Enter elements of %s (%dx%d):\n", name, rows, cols);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++) {
            printf("%s[%d][%d]: ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
}

// Function to display a matrix
void displayMatrix(int mat[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            printf("%5d", mat[i][j]);
        printf("\n");
    }
}

// Addition of matrices
void addMatrix(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Subtraction of matrices
void subtractMatrix(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

// Multiplication of matrices
void multiplyMatrix(int a[10][10], int b[10][10], int result[10][10], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;
    int choice;

    printf("Matrix Calculator\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2) {
        printf("Enter rows and columns of matrices: ");
        scanf("%d%d", &r1, &c1);
        r2 = r1;
        c2 = c1;
        readMatrix(a, r1, c1, "A");
        readMatrix(b, r2, c2, "B");

        if(choice == 1)
            addMatrix(a, b, result, r1, c1);
        else
            subtractMatrix(a, b, result, r1, c1);

        printf("Result:\n");
        displayMatrix(result, r1, c1);

    } else if(choice == 3) {
        printf("Enter rows and columns of Matrix A: ");
        scanf("%d%d", &r1, &c1);
        printf("Enter rows and columns of Matrix B: ");
        scanf("%d%d", &r2, &c2);

        if(c1 != r2) {
            printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
            return 1;
        }

        readMatrix(a, r1, c1, "A");
        readMatrix(b, r2, c2, "B");

        multiplyMatrix(a, b, result, r1, c1, c2);
        printf("Result:\n");
        displayMatrix(result, r1, c2);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
