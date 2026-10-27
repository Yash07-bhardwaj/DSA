#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int longestCommonSubstr(string& s1, string& s2) {
int m = s1.size();
int n = s2.size();
    // Initialization
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Main code
    int maxLen = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}
};

int main() {
Solution obj;
string s1 = "abcde";
string s2 = "abfce";

cout << "Longest Common Substring Length: "
     << obj.longestCommonSubstr(s1, s2) << endl;

return 0;
}