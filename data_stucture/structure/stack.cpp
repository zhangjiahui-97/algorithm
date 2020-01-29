#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<algorithm>
#include<vector>

int main() 
{
    stack<int> s1;
    stack< pair<int, int> > s2;
    string ch = "!!///!_/!/!!!!/_/!!///__!!!_!!/_!/_/!";
    int sum = 0;
    for (int i = 0; i < ch.length(); i++) {
        if (ch[i] == '!')
            s1.push(i);
        else if (ch[i] == '/' && s1.size() > 0) {
            int j = s1.top(); 
            s1.pop();
            sum += i - j;
            int a = i - j;
            while(s2.size() > 0 && s2.top().first > j) {
                a += s2.top().second; 
                s2.pop();
            }
            s2.push(make_pair(j, a));
        }
    }
    vector<int> ans;
    while(s2.size() > 0) {
        ans.push_back(s2.top().second);
        s2.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
    cout << ans.size();
    for (int i = 0; i < ans.size(); i++) {
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}