#include <bits/stdc++.h>
using namespace std;

bool SequencePatternMatching(string a, string b, int m, int n) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialization
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Main Code (LCS)
    for (int i = 1; i < m + 1; i++) {

        for (int j = 1; j < n + 1; j++) {

            if (a[i - 1] == b[j - 1]) {

                dp[i][j] = 1 + dp[i - 1][j - 1];

            }
            else {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }
        }
    }

    int LCS = dp[m][n];

    if (LCS == m) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    string a, b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();

    if (SequencePatternMatching(a, b, m, n)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}