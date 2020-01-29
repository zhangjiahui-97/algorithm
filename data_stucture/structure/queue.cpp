#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define LEN 100005

typedef struct pp {
     string name;
     int t;
} P;

P Q[LEN];
int head, tail, n;

void enqueue(P x) 
{
    Q[tail] = x;
    tail = (tail + 1 ) % LEN;
}

P dequeue() {
    P x = Q[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
    int elaps = 0, c;
    int i, q;
    P u;
    n = 5, q = 100;
    /*
    for (i = 1; i <= n; i++) {
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }
    */
    Q[1].name = "p1";
    Q[2].name = "p2";
    Q[3].name = "p3";
    Q[4].name = "p4";
    Q[5].name = "p5";
    Q[1].t = 150;
    Q[2].t = 80;
    Q[3].t = 200;
    Q[4].t = 350;
    Q[5].t = 20;

    head = 1;
    tail = n + 1;
    while (head != tail) {
        u = dequeue();
        c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if (u.t > 0)
            enqueue(u);
        else
            cout << u.name << " " << elaps << endl;     
    }
    return 0;
}