#include<iostream>
using namespace std;
#include<algorithm>

int main()
{
    freopen("in", "r", stdin);
    int n;
    cin >> n;
    int p[100];
    for (int i = 1; i <=n; i++) {
        cin >> p[i-1] >> p[i];
    }
    int dp[100][100];
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = (1 << 21);
            for (int k = i; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << dp[1][n];

    return 0;
}