/*
    Problem: Minimum Jumps to Reach End
    Date: 19-04-2026

    Intuition:
    We are given an array where each element tells the maximum jump length
    from that position. We need minimum jumps to reach last index.

    Approaches:
    1. Brute Force Recursion:
       Try every possible jump from current index and take minimum.

    2. Greedy Optimized:
       Maintain current jump range and farthest reachable index.
       When current range ends, take another jump.

    Time & Space:
    Brute Force:
    TC: Exponential
    SC: O(n)

    Greedy:
    TC: O(n)
    SC: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------------------------
    // 1. Brute Force Recursive Approach
    // -------------------------------------------------
    
    int solve(vector<int>& arr, int i) {
        int n = arr.size();

        if (i >= n - 1) return 0;
        if (arr[i] == 0) return 1e9;

        int mini = 1e9;

        for (int jump = 1; jump <= arr[i]; jump++) {
            mini = min(mini, 1 + solve(arr, i + jump));
        }

        return mini;
    }

    int minJumpsBrute(vector<int>& arr) {
        int ans = solve(arr, 0);

        if (ans >= 1e9) return -1;
        return ans;
    }


    // -------------------------------------------------
    // 2. Greedy Optimized Approach
    // -------------------------------------------------

    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return 0;
        if (arr[0] == 0) return -1;

        int jumps = 1;
        int maxReach = arr[0];
        int steps = arr[0];

        for (int i = 1; i < n; i++) {

            if (i == n - 1) return jumps;

            maxReach = max(maxReach, i + arr[i]);

            steps--;

            if (steps == 0) {
                jumps++;

                if (i >= maxReach) return -1;

                steps = maxReach - i;
            }
        }

        return -1;
    }
};
