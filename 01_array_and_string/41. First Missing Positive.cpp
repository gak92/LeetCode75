/*
https://leetcode.com/problems/first-missing-positive/description/
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      if (nums[i] < 0)
        nums[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
      int val = abs(nums[i]);
      if (val >= 1 && val <= n) // check if not out of bound
      {
        if (nums[val - 1] > 0) // if value is +ve, make it -ve
          nums[val - 1] *= -1;
        else if (nums[val - 1] == 0) // if value is 0, make it -ve with value not in array
          nums[val - 1] = -1 * (n + 1);
      }
    }

    for (int i = 1; i <= n; i++)
    {
      if (nums[i - 1] >= 0)
        return i;
    }

    return (n + 1);
  }
};

int main()
{
  vector<int> nums = {3, 4, -1, 1};
  Solution s;
  cout << s.firstMissingPositive(nums) << endl;
  return 0;
}