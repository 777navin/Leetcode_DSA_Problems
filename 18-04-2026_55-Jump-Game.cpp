// Problem: 55. Jump Game
// Date: 18-04-2026
// Language: C++

/*
Intuition:
From every index, we can jump forward up to nums[i] steps.
Instead of checking all possible jumps recursively, we track the
farthest index reachable so far.

If at any point current index becomes greater than farthest reachable,
it means we are stuck and cannot move further.

Approach:
1. Initialize maxReach = 0.
2. Traverse the array from left to right.
3. If i > maxReach, return false.
4. Update maxReach = max(maxReach, i + nums[i]).
5. If maxReach reaches last index, return true.
6. If loop finishes, return true.

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach)
                return false;

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};
