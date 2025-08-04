#include <stdio.h>
#define MAX 10
int main() {
    int a[MAX][MAX], b[MAX][MAX], c[MAX][3], d[MAX][3], a2[MAX][3], b2[MAX][3];
    int r1, r2, c1, c2, i, j, k = 1, x = 1, m = 0, n, t;
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the elements of Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter the elements of Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    k = 1;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            if (a[i][j] != 0) {
                a2[k][0] = i;
                a2[k][1] = j;
                a2[k][2] = a[i][j];
                k++;
            }
        }
    }
    a2[0][0] = r1;
    a2[0][1] = c1;
    a2[0][2] = k - 1;
    printf("Tuple of Matrix A:\n");
    for (i = 0; i <= a2[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a2[i][j]);
        }
        printf("\n");
    }
    x = 1;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            if (b[i][j] != 0) {
                b2[x][0] = i;
                b2[x][1] = j;
                b2[x][2] = b[i][j];
                x++;
            }
        }
    }
    b2[0][0] = r2;
    b2[0][1] = c2;
    b2[0][2] = x - 1;
    printf("Tuple of Matrix B:\n");
    for (i = 0; i <= b2[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", b2[i][j]);
        }
        printf("\n");
    }
    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition not possible!\n");
    } else {
        c[0][0] = a2[0][0];
        c[0][1] = a2[0][1];
        int m = a2[0][2], n = b2[0][2];
        i = j = k = 1;
        while (i <= m && j <= n) {
            if (a2[i][0] == b2[j][0] && a2[i][1] == b2[j][1]) {
                c[k][0] = a2[i][0];
                c[k][1] = a2[i][1];
                c[k][2] = a2[i][2] + b2[j][2];
                i++; j++;
            } else if (a2[i][0] < b2[j][0] || (a2[i][0] == b2[j][0] && a2[i][1] < b2[j][1])) {
                c[k][0] = a2[i][0];
                c[k][1] = a2[i][1];
                c[k][2] = a2[i][2];
                i++;
            } else {
                c[k][0] = b2[j][0];
                c[k][1] = b2[j][1];
                c[k][2] = b2[j][2];
                j++;
            }
            k++;
        }
        while (i <= m) {
            c[k][0] = a2[i][0];
            c[k][1] = a2[i][1];
            c[k][2] = a2[i][2];
            i++; k++;
        }
        while (j <= n) {
            c[k][0] = b2[j][0];
            c[k][1] = b2[j][1];
            c[k][2] = b2[j][2];
            j++; k++;
        }
        c[0][2] = k - 1;
        printf("Addition of Matrix (Tuple form):\n");
        for (i = 0; i <= c[0][2]; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }
    t = 1;
    d[0][0] = c[0][1];
    d[0][1] = c[0][0];
    d[0][2] = c[0][2];
    for (i = 0; i < c[0][1]; i++) {
        for (j = 1; j <= c[0][2]; j++) {
            if (c[j][1] == i) {
                d[t][0] = c[j][1];
                d[t][1] = c[j][0];
                d[t][2] = c[j][2];
                t++;
            }
        }
    }

   
    printf("Transpose Matrix:\n");
    for (i = 0; i < t; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}