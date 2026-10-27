#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
string printLCS(string s1, string s2) {
int m = s1.size();
int n = s2.size();
    // Prepare DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Print LCS by backtracking
    int i = m, j = n;
    string ans = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        } else {
            if (dp[i][j - 1] > dp[i - 1][j]) {
                j--;
            } else {
                i--;
            }
        }
    }

    // Reverse to get correct order
    reverse(ans.begin(), ans.end());

    return ans;
}
};
int main() {
Solution obj;
string s1 = "abcde";
string s2 = "ace";

cout << "LCS: " << obj.printLCS(s1, s2) << endl;

return 0;
}