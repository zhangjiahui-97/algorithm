#include<iostream>
using namespace std;
#include<vector>

void print(vector<int> v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it;
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    int n, x;
    freopen("itin.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    print(v);
    return 0;
}