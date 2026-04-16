# 78. Subsets

Solved LeetCode 78. Subsets using C++ recursion and backtracking.

## Problem Statement

Given an integer array `nums` of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the answer in any order.

## Example

Input: nums = [1,2,3]  
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

## Approach

We use **Recursion + Backtracking** to generate every possible subset.

For each element, we have **two choices**:

1. Exclude the current element  
2. Include the current element

This creates a decision tree where each level represents one index.

When we reach the end of the array, the current subset is added to the result.

## Intuition

Every element can either be present or absent in a subset.

So for `n` elements:

Total subsets = `2^n`

For `[1,2,3]`

- Take none → `[]`
- Take 1 only → `[1]`
- Take 2 only → `[2]`
- Take 1,2 → `[1,2]`
- ...
- Take all → `[1,2,3]`

## Code (C++)

```cpp
class Solution {
public:
    void generate(int index, vector<int>& nums, vector<int> current,
                  vector<vector<int>>& result) {

        if(index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Exclude current element
        generate(index + 1, nums, current, result);

        // Include current element
        current.push_back(nums[index]);
        generate(index + 1, nums, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        generate(0, nums, current, result);
        return result;
    }
}; 
