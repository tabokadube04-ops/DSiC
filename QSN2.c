2. #include <stdio.h>
#define MAX 10   // Maximum size of matrix
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int C[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Sum of matrices:\n");
    displayMatrix(C, rows, cols);
}
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int C[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }	
    printf("Subtraction of matrices (A - B):\n");
    displayMatrix(C, rows, cols);		
}
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Matrix multiplication not possible (columns of A != rows of B).\n");
        return;
    }
    int C[MAX][MAX];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Product of matrices:\n");
    displayMatrix(C, r1, c2);
}
void transposeMatrix(int A[MAX][MAX], int rows, int cols) {
    int T[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }
    printf("Transpose of matrix:\n");
    displayMatrix(T, cols, rows);
}
int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(A, r1, c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(B, r2, c2);
    while (1) {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Sum of matrices\n");
        printf("2. Subtraction of matrices\n");
        printf("3. Product of matrices\n");
        printf("4. Transpose of Matrix A\n");
        printf("5. Transpose of Matrix B\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (r1 == r2 && c1 == c2)
                    addMatrix(A, B, r1, c1);
                else
                    printf("Addition not possible (matrices must be same size).\n");
                break;
            case 2:
                if (r1 == r2 && c1 == c2)
                    subtractMatrix(A, B, r1, c1);
                else
                    printf("Subtraction not possible (matrices must be same size).\n");
                break;
            case 3:
                multiplyMatrix(A, B, r1, c1, r2, c2);
                break;
            case 4:
                transposeMatrix(A, r1, c1);
                break;
            case 5:
                transposeMatrix(B, r2, c2);
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
