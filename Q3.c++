#include <stdio.h>

int produto(int a, int b) {
    if(b == 1)
    {
        return a;
    }
    else
    {
        return produto(a, b - 1) + a;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", produto(a, b));
    return 0;
}