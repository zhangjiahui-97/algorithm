#include<iostream>
using namespace std;
 
void Selection_sort(int num[100], int n)
{
    void print(int num[]);
    int temp, i, j, min, index;
    for (int i = 0; i < n; i++) {
        min = INT_MAX;
        for (int j = i; j < n; j++) {
            if (num[j] < min) {
                min = num[j];
                index = j;
            }
        }
        temp = num[index];
        num[index] = num[i];
        num[i] = temp;
    }
}

void print(int num[])
{
    for (int i = 0; i < 10; i++)
        cout << num[i] << " ";
    cout << endl;
}

int main()
{
    int num[100] = {5,4,6,2,3,1,9,0,7,8};
    Selection_sort(num, 10);
    print(num);
    return 0;
}