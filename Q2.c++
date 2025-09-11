#include <stdio.h>
#include <iostream>
#include <cstdlib>

// soma reverse
int soma(int n)
{
    if(n == 0)
    {
        return 0;
    };
    if(n % 2 == 0)
    {
        return n + soma(n - 2);
    }
    else
    {
        return soma(n - 1);
    }
    
}

int main(){
    int x;
    scanf("%d", &x);
    x = soma(x);
    printf("%d", x);
}