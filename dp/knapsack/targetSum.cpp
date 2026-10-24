class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int totalSum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if (totalSum < abs(target) || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int sum = (totalSum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Initialization (your code)
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) {
                    dp[i][j] = 0;
                }
                if (j == 0) {
                    dp[i][j] = 1;
                }
            }
        }

        // DP transitions
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]]
                              + dp[i - 1][j]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};