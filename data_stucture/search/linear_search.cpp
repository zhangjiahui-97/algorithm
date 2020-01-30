#include<stdio.h>

int search (int S[], int key, int n)
{
    S[n] = key;
    int i = 0;
    while (S[i] != S[n]) i++;
    return i != n;
}

int main()
{
    // input 
    freopen("in.txt", "r", stdin);
    int n, q;
    int S[10010], T[510];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    
    // process
    int num = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &T[i]);  
        num += search(S, T[i], n);
    }
    printf("%d", num);

    return 0;
}