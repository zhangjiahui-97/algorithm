#include<stdio.h>

int search (int S[], int key, int n)
{
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (S[mid] == key) 
            return 1;
        else if (S[mid] > key) {
            right = mid;
        }
        else if (S[mid] < key) {
            left = mid + 1;
        }
    }
    return 0;
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