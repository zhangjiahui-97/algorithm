#include<iostream>
using namespace std;
 
void Bubble_sort(int num[100], int n)
{
    int temp, i, j;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (num[j] > num[j+1]) {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}

void print(int num[100])
{
    for (int i = 0; i < 10; i++)
        cout << num[i] << " ";
}

int main()
{
    int num[100] = {5,4,6,2,3,1,9,0,7,8};
    Bubble_sort(num, 10);
    print(num);
    return 0;
}