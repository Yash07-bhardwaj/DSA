#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n) {
vector<vector> dp(m + 1, vector(n + 1, 0));
// Initialization
for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
        if (i == 0) {
            dp[i][j] = 0;
        }
        if (j == 0) {
            dp[i][j] = 0;
        }
    }
}

// Main code
for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
        if (a[i - 1] == b[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

return dp[m][n];
}

int main() {
string a, b;
cin >> a >> b;
cout << a.length() + b.length() - LCS(a, b, a.length(), b.length());

return 0;
}