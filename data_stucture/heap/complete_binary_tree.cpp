#include<iostream>
using namespace std;

int parent(int i) {return i/2;}
int left(int i) {return 2 * i;}
int right(int i) {return 2 * i + 1;}

int main()
{
    freopen("in", "r", stdin);
    int H, i, a[10000];
    cin >> H;
    for (i = 1; i <= H; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= H; i++) {
        cout << "node " << i << ": ";
        cout << "key = " << a[i] << ", ";
        if (parent(i) >= 1) {
            cout << "parent key = " << parent(i) << ", ";
        }
        if (left(i) <= H) {
            cout << "left key = " << left(i) << ", ";
        }
        if (right(i) <= H) {
            cout << "right key = " << right(i) << ", ";
        }
        cout << endl;
    }
    return 0;
}