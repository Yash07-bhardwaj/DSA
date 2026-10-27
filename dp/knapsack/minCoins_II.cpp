#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int minCoins(vector& coins, int sum) {
int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, INT_MAX - 1));

    // Base case: sum = 0 requires 0 coins
    for (int i = 0; i <= n; i++) {
        t[i][0] = 0;
    }

    // Initialization for the first coin
    for (int j = 1; j <= sum; j++) {
        if (j % coins[0] == 0) {
            t[1][j] = j / coins[0];
        } else {
            t[1][j] = INT_MAX - 1;
        }
    }

    // Fill the DP table
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i - 1] <= j) {
                t[i][j] = min(
                    1 + t[i][j - coins[i - 1]],
                    t[i - 1][j]
                );
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Return the answer
    if (t[n][sum] >= INT_MAX - 1) {
        return -1;
    }

    return t[n][sum];
}
};

int main() {
Solution obj;
vector<int> coins = {1, 2, 3};
int sum = 4;

cout << obj.minCoins(coins, sum) << endl;

return 0;
}
