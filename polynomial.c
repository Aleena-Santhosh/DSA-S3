#include<stdio.h>
#define MAX 100

typedef struct {
    int coe, exp;
} Term;

int readpoly(Term poly[]) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter each term (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].coe, &poly[i].exp);
    }
    return n;
}

void displaypoly(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].coe != 0) {
            if (poly[i].coe > 0 && i != 0) {
                printf("+");
            } else if (poly[i].coe < 0) {
                printf("-");
            }
            printf("%d", (poly[i].coe < 0) ? -poly[i].coe : poly[i].coe);
            if (poly[i].exp != 0) {
                printf("x^%d", poly[i].exp);
            }
        }
    }
    printf("\n");
}

int sumpoly(Term poly1[], int nTerms1, Term poly2[], int nTerms2, Term sumPoly[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < nTerms1 && j < nTerms2) {
        if (poly1[i].exp == poly2[j].exp) {
            sumPoly[k].coe = poly1[i].coe + poly2[j].coe;
            sumPoly[k].exp = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            sumPoly[k] = poly1[i];
            i++;
            k++;
        } else {
            sumPoly[k] = poly2[j];
            j++;
            k++;
        }
    }

    while (i < nTerms1) {
        sumPoly[k] = poly1[i];
        i++;
        k++;
    }
    while (j < nTerms2) {
        sumPoly[k] = poly2[j];
        j++;
        k++;
    }

    return k; 
}

int main() {
    Term poly1[MAX], poly2[MAX], sumPoly[MAX];
    int nTerms1, nTerms2, nSum;

    printf("Enter the first polynomial:\n");
    nTerms1 = readpoly(poly1);

    printf("Enter the second polynomial:\n");
    nTerms2 = readpoly(poly2);

    nSum = sumpoly(poly1, nTerms1, poly2, nTerms2, sumPoly);

    printf("First polynomial: ");
    displaypoly(poly1, nTerms1);

    printf("Second polynomial: ");
    displaypoly(poly2, nTerms2);

    printf("Sum of polynomials: ");
    displaypoly(sumPoly, nSum);

    return 0;
}