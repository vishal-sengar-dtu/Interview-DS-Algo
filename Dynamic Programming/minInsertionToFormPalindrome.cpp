#include <bits/stdc++.h>
using namespace std;

class Solution // (https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)
{
public:
    int minInsertions(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i + 1][j + 1] = (s[i] == s[n - 1 - j]) ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return n - dp[n][n];
    }
};