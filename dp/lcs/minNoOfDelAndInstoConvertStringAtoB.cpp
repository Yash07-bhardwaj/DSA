#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n) {
vector<vector> dp(m + 1, vector(n + 1, 0));
// Initialization
for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
        if (i == 0 || j == 0) {
            dp[i][j] = 0;
        }
    }
}

// Main code
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (a[i - 1] == b[j - 1]) {
            dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

return dp[m][n];
}
int main() {
string a, b;
cout << "Enter first string: ";
cin >> a;

cout << "Enter second string: ";
cin >> b;

int m = a.length();
int n = b.length();

int lcs = LCS(a, b, m, n);

cout << "Minimum Deletions: " << m - lcs << endl;
cout << "Minimum Insertions: " << n - lcs << endl;

return 0;
}