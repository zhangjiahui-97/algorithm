#include<iostream>
using namespace std;
#include<string.h>

int main() 
{
    int sortNum[100] = {5,4,6,2,3,1,9,0,7,8};
    int res[100];
    int j = 0, i = 0, k = 0;
    for (i = 0; i < 10; i++) {
        for(j = 0; j < i; j++) {
            if (sortNum[i] < res[j]) {
                for (k = i - 1; k >= j; k--) {
                    res[k + 1] = res[k];
                }
                break;
            }
        }
        res[j] = sortNum[i];
    }
    for (i = 0; i < 10; i++) 
        cout << res[i] << " ";
    return 0;
}