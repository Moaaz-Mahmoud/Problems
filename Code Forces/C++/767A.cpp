#include <stdio.h>
 
bool snacks[100009];
 
int main()
{
    int n, a, next;
    scanf_s("%d", &n);
    next = n;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a);
        snacks[a] = true;
        if (a == next) {
            printf("%d ", a);
            next--;
            snacks[a] = false;
            for (int j = a - 1; j >= 1 && snacks[j]; j--) {
                if (snacks[j]) {
                    printf("%d ", j);
                    next = j - 1;
                    snacks[j] = false;
                }
            }
        }
        printf("\n");
    }
}
