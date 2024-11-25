
#include "alistlib.h"
#include <stdio.h>

int main() {
    List L;
    makeNull(&L); 

    int n, x;
    
    printf("Nhap so luong phan tu trong danh sach: ");
    scanf("%d", &n);

    printf("Nhap cac phan tu:\n");
    int i = 1;
    for (i ; i <= n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &x);
        append(x, &L); 
    }

    printf("\nDanh sach truoc khi sap xep: ");
    print(L);

    sort(&L);

    printf("\nDanh sach sau khi sap xep: ");
    print(L);

    return 0;
}

