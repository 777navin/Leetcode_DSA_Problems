# Partition Equal Subset Sum
## 🧠 Problem
Check if array can be divided into two subsets with equal sum.
## ⚡ Approach
* Find total sum
* If odd → return false
* Else target = sum / 2
* Try include/exclude recursion
## ⏱ Complexity
* Time: O(2^n)
* Space: O(n)

## 🚀 Future Improvement

* Use DP (Memoization) for optimization



class Solution {
public:
    bool solve(vector<int>& nums, int target, int i){
        if(target < 0 || i >= nums.size()) return false;
        if(target == 0) return true;

        bool inc = solve(nums, target - nums[i], i + 1);
        bool exc = solve(nums, target, i + 1);

        return inc || exc;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        return solve(nums, sum / 2, 0);
    }
}; 
