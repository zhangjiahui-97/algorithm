#include<iostream>
using namespace std;
#include<string>
#include<map>

void print(map<string, int> T) {
    map<string, int>::iterator it;
    cout << T.size() << endl;
    for (it = T.begin(); it != T.end(); it++) {
        pair<string, int> item = *it;
        cout << item.first << " --> " << item.second << endl;
    }
}

int main()
{
    map<string, int> T;
    T["red"] = 32;
    T["blue"] = 688;
    T["yellow"] = 122;
    T["blue"] += 312;
    print (T);
    
    return 0;
}