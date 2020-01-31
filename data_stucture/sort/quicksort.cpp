#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int start, int end, int a[])
{
    if (start >= end)
        return;
    int k = a[start];
    int i = start, j = end;
    while(i != j) {
        while(i < j && a[j] >= k)
            j--;
        swap(a[i], a[j]);
        while(i < j && a[i] <= k)
            i++;
        swap(a[i], a[j]);
    }
    quicksort(start, i - 1, a);
    quicksort(i + 1, end, a);
}

int main()
{
    int a[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
    int size = sizeof(a)/sizeof(int);
    quicksort(0, size - 1, a);
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}