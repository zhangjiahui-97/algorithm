#include<iostream>
using namespace std;

int H;

void maxHeapify(int a[], int i)
{
    int left, right, largest;
    left = 2 * i;
    right = 2 * i + 1;

    if (left <= H && a[left] > a[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if (right <= H && a[right] > a[largest]) {
        largest = right;
    }
    
    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, largest);
    }
}

int main()
{
    // input
    freopen("in", "r", stdin);
    int a[10000], i;
    cin >> H;
    for (i = 1; i <= H; i++)
        cin >> a[i];
    
    // process
    for (i = H/2; i >= 1; i--) {
        maxHeapify(a, i);
    }

    // output
    for (i = 1; i <= H; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}