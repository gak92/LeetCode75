/*
https://leetcode.com/problems/longest-common-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
// Recursive + Memoization (DP)
class Solution {
private:
    int m, n;
    int dp[1001][1001];

    int solve(string &text1, string &text2, int i, int j) {
        if(i >= m || j>= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(text1, text2, i+1, j+1);

        return dp[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();
        memset(dp, -1, sizeof(dp));

        return solve(text1, text2, 0, 0);
    }
};
*/

// Bottom Up Approach (DP)
class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.size();
    int n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        if (text1[i] == text2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }

    return dp[0][0];
  }
};

int main()
{
  Solution s;
  cout << s.longestCommonSubsequence("abcde", "ace") << endl;
  return 0;
}