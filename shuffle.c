#include <stdio.h>

int A[10];
int B[] = {7, 3, 9, 9, 6, 9, 8, 9, 8, 9};

int main() {
    int i, r, swap;
    
    for (i=0; i<10; i++)
        A[i] = i;
    for (i=0; i<10; i++) {
        r = B[i];
        swap = A[r];
        A[r] = A[i];
        A[i] = swap;
    }
    for (i=0; i<10; i++) {
        printf("%d", A[i]);
        printf("\n");
    }
}