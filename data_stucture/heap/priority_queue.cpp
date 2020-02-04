#include<iostream>
using namespace std;


int H, a[10000];

// 将a[i]的值一直向叶子结点移动，直到满足最大堆性质
void maxHeapify(int i)
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
        maxHeapify(largest);
    }
}

void increaseKey(int i, int key) 
{
    if (key < a[i])
        return;
    a[i] = key;
    while(i > 1 && a[i/2] < a[i]) {
        swap(a[i], a[i/2]);
        i = i/2;
    }
}

void insert(int key)
{
    H++;
    a[H] = INT_MIN;
    increaseKey(H, key);
}

int extract() {
    int maxv;
    if (H < 1) return INT_MIN;
    maxv = a[1];
    a[1] = a[H--];
    maxHeapify(1);
    return maxv;
}

int main()
{
    // input
    freopen("in_queue", "r", stdin);
    int key;
    char com[10];
    while(1) {
        scanf("%s", com);
        if (com[0] == 'e' && com[1] == 'n')
            break;
        if (com[0] == 'i') {
            scanf("%d", &key);
            insert(key);
        } else {
            printf("%d\n", extract());
        }
    }

    return 0;
}