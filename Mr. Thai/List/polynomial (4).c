#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    float coefficient;
    int exponent;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int size;
} Polynomial;

void initPolynomial(Polynomial *p) {
    p->size = 0;
}

int isEmpty(Polynomial p) {
    return p.size == 0;
}

void addTerm(Polynomial *p, float coefficient, int exponent) {
    if (p->size >= MAX_TERMS) {
        printf("Polynomial term limit reached.\n");
        return;
    }
    int i;
    for (i = 0; i < p->size; i++) {
        if (p->terms[i].exponent == exponent) {
            p->terms[i].coefficient += coefficient;
            return;
        }
    }
    p->terms[p->size].coefficient = coefficient;
    p->terms[p->size].exponent = exponent;
    p->size++;
    // Keep terms sorted by exponent in descending order
    for (i = p->size - 1; i > 0 && p->terms[i].exponent > p->terms[i - 1].exponent; i--) {
        Term temp = p->terms[i];
        p->terms[i] = p->terms[i - 1];
        p->terms[i - 1] = temp;
    }
}

void printPolynomial(Polynomial p) {
    if (isEmpty(p)) {
        printf("0");
        return;
    }
    for (int i = 0; i < p.size; i++) {
        if (i > 0 && p.terms[i].coefficient > 0) {
            printf(" + ");
        } else if (p.terms[i].coefficient < 0) {
            printf(" - ");
        }
        if (fabs(p.terms[i].coefficient) != 1 || p.terms[i].exponent == 0) {
            printf("%.1f", fabs(p.terms[i].coefficient));
        }
        if (p.terms[i].exponent > 0) {
            printf("x");
            if (p.terms[i].exponent > 1) {
                printf("^%d", p.terms[i].exponent);
            }
        }
    }
    printf("\n");
}

void addPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    initPolynomial(result);
    for (int i = 0; i < p1->size; i++) {
        addTerm(result, p1->terms[i].coefficient, p1->terms[i].exponent);
    }
    for (int i = 0; i < p2->size; i++) {
        addTerm(result, p2->terms[i].coefficient, p2->terms[i].exponent);
    }
}

void derivative(Polynomial *p, Polynomial *result) {
    initPolynomial(result);
    for (int i = 0; i < p->size; i++) {
        if (p->terms[i].exponent > 0) {
            float newCoefficient = p->terms[i].coefficient * p->terms[i].exponent;
            int newExponent = p->terms[i].exponent - 1;
            addTerm(result, newCoefficient, newExponent);
        }
    }
}

int main() {
    Polynomial p1, p2, sum, derivativeP1;
    initPolynomial(&p1);
    initPolynomial(&p2);

    printf("Enter the first polynomial:\n");
    int numTerms;
    printf("Number of terms: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        float coefficient;
        int exponent;
        printf("Term %d: ", i + 1);
        scanf("%f %d", &coefficient, &exponent);
        addTerm(&p1, coefficient, exponent);
    }

    printf("Enter the second polynomial:\n");
    printf("Number of terms: ");
    scanf("%d", &numTerms);
    for (int i = 0; i < numTerms; i++) {
        float coefficient;
        int exponent;
        printf("Term %d: ", i + 1);
        scanf("%f %d", &coefficient, &exponent);
        addTerm(&p2, coefficient, exponent);
    }

    addPolynomials(&p1, &p2, &sum);
    printf("Sum of the polynomials:\n");
    printPolynomial(sum);

    derivative(&p1, &derivativeP1);
    printf("Derivative of the first polynomial:\n");
    printPolynomial(derivativeP1);

    return 0;
}

