/*
https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
      int mid = (left + right) / 2;

      if (target == nums[mid])
        return mid;

      if (target > nums[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }

    return left;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  cout << s.searchInsert(nums, target) << endl;

  return 0;
}