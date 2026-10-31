#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialization
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {

            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Main Code
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {

            if(a[i - 1] == b[j - 1]) {

                dp[i][j] = 1 + dp[i - 1][j - 1];

            }
            else {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }
        }
    }

    return dp[m][n];
}

int main() {

    string s;
    cin >> s;

    string rev = s;

    reverse(rev.begin(), rev.end());

    int n = s.length();

    int LPS = LCS(s, rev, n, n);

    cout << "Minimum Insertions: " << n - LPS;

    return 0;
}