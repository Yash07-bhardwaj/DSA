class Solution {
  public:

    int dp[1001][1001];

    int solve(vector<int> &arr, int i, int j) {

        // Base Condition
        if(i >= j) {
            return 0;
        }

        // Check if already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        // Try all possible partitions
        for(int k = i; k < j; k++) {

            int tempAns = solve(arr, i, k)
                        + solve(arr, k + 1, j)
                        + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, tempAns);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &arr) {

        int n = arr.size();

        memset(dp, -1, sizeof(dp));

        return solve(arr, 1, n - 1);
    }
};