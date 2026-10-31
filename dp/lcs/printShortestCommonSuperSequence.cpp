#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n) {

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

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
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    // Print Shortest Common Supersequence
    int i = m, j = n;
    string ans = "";

    while (i > 0 && j > 0) {

        if (a[i - 1] == b[j - 1]) {

            ans.push_back(a[i - 1]);
            i--;
            j--;

        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {

            ans.push_back(a[i - 1]);
            i--;

        }
        else {

            ans.push_back(b[j - 1]);
            j--;

        }
    }

    // Add remaining characters of a
    while (i > 0) {
        ans.push_back(a[i - 1]);
        i--;
    }

    // Add remaining characters of b
    while (j > 0) {
        ans.push_back(b[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    cout << "Shortest Common Supersequence: " << ans << endl;

    return dp[m][n];
}

int main() {

    string a, b;
    cin >> a >> b;

    int m = a.length();
    int n = b.length();

    int lcs = LCS(a, b, m, n);

    cout << "Minimum Length of SCS: " << m + n - lcs;

    return 0;
}