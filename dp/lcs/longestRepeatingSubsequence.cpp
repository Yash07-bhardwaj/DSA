#include <bits/stdc++.h>
using namespace std;

int LRS(string s) {

    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Initialization
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Main Code (LCS + Extra Condition)
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (s[i - 1] == s[j - 1] && i != j) {

                dp[i][j] = 1 + dp[i - 1][j - 1];

            }
            else {

                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            }
        }
    }

    return dp[n][n];
}

int main() {

    string s;
    cin >> s;

    cout << "Length of Longest Repeating Subsequence: " << LRS(s);

    return 0;
}