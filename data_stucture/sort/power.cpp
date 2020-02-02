#include<iostream>
using namespace std;

// 快速幂
int power(int a, int b)
{
    int result = 1;
    int base = a;
    while(b) {
        printf("%d\n", b);
        if (b & 1) {
            result *= base;
            printf("base:%d\n", base);  
        }
        base *= base;
        b >>= 1;
    }
    return result;
}

int main() 
{
    cout << power(2, 10);
    return 0;
}