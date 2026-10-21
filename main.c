#include <stdio.h>

#define MAX 100

int sort1(int a[], int n) {
    int i, j, t;
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                k++;
            }
        }
    }
    return k;
}

void almashtir(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int sort2(int *p, int n) {
    int i, j;
    int k = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (*(p + j) > *(p + j + 1)) {
                almashtir(p + j, p + j + 1);
                k++;
            }
        }
    }
    return k;
}

int main() {
    int a[MAX], b[MAX];
    int n, i, k1, k2;

    printf("N ni kiriting (1..100): ");
    if (scanf("%d", &n) != 1) {
        printf("Xato: N butun son bo'lishi kerak!\n");
        return 1;
    }
    if (n <= 0 || n > MAX) {
        printf("Xato: N 1 dan 100 gacha bo'lishi kerak!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%d", &a[i]) != 1) {
            printf("Xato: butun son kiriting!\n");
            return 1;
        }
        b[i] = a[i];
    }

    k1 = sort1(a, n);
    printf("\n1-masala: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nAlmashtirishlar soni: %d\n", k1);

    k2 = sort2(b, n);
    printf("\n2-masala: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(b + i));
    }
    printf("\nAlmashtirishlar soni: %d\n", k2);

    printf("\nb manzili: %p\n", (void *)b);
    printf("n manzili: %p\n", (void *)&n);

    return 0;
}
