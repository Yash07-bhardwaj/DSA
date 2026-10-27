#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int longestCommonSubsequence(string x, string y) {
int m = x.size();
int n = y.size();
    // Initialization
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Main code
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}
};

int main() {
Solution obj;
string x = "abcde";
string y = "ace";

cout << "Length of LCS: "
     << obj.longestCommonSubsequence(x, y) << endl;

return 0;
}
