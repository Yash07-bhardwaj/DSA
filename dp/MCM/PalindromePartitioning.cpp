class Solution {
public:

    int dp[1001][1001];

    bool isPalindrome(string &s, int i, int j) {

        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int solve(int i, int j, string &s) {

        if(i >= j) {
            return 0;
        }

        if(isPalindrome(s, i, j)) {
            return dp[i][j] = 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        for(int k = i; k < j; k++) {

            int left, right;

            // Left part
            if(dp[i][k] != -1) {
                left = dp[i][k];
            }
            else {
                left = solve(i, k, s);
            }

            // Right part
            if(dp[k+1][j] != -1) {
                right = dp[k+1][j];
            }
            else {
                right = solve(k+1, j, s);
            }

            int temp = left + right + 1;

            mini = min(mini, temp);
        }

        return dp[i][j] = mini;
    }

    int palPartition(string &s) {

        int n = s.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, n-1, s);
    }
};