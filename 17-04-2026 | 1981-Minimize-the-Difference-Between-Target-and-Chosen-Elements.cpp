/**
 * Question Brief:
 * - Given an m x n matrix and an integer 'target'.
 * - Select exactly one element from each row.
 * - Goal: Minimize the absolute difference between the sum of chosen elements and 'target'.
 * - Constraints: Matrix size up to 70x70, target up to 800, elements up to 70.
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    // dp[row][sum] stores the minimum difference found from this state
    // Max sum possible: 70 rows * 70 (max value) = 4900. Hence [71][5000].
    int dp[71][5000];

    int solve(vector<vector<int>>& mat, int& target, int sum, int row) {
        // Base Case: When all rows are processed
        if (row == mat.size()) {
            return abs(target - sum);
        }

        // Memoization check
        if (dp[row][sum] != -1) {
            return dp[row][sum];
        }

        int ans = INT_MAX;
        for (int col = 0; col < mat[row].size(); col++) {
            // Recurrence relation: move to next row and add current element to sum
            int res = solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, res);
            
            // Optimization: If we found a perfect sum (diff = 0), no need to check further
            if (ans == 0) break; 
        }

        return dp[row][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(mat, target, 0, 0);
    }
};

/**
 * Intuition:
 * This is a variation of the "Subset Sum" or "Knapsack" problem. Since we must pick 
 * one element from every row, we explore all possible sums layer by layer (row by row).
 * Using memoization prevents us from re-calculating the minimum difference for a 
 * specific (row, current_sum) pair.
 *
 * Time Complexity: O(m * n * max_sum)
 * - m = number of rows (70)
 * - n = number of columns (70)
 * - max_sum = maximum possible sum (~4900)
 * - Total operations approx: 70 * 70 * 4900 ≈ 2.4 million (well within limits).
 *
 * Space Complexity: O(m * max_sum)
 * - Due to the 2D DP table: 70 * 5000 integers.
 */
