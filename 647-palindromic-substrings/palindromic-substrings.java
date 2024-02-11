class Solution {
    public int countSubstrings(String s) {
         int n = s.length();
        int[][] dp = new int[n][n];

        int ans = 0;
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                if (i == j) dp[i][j] = 1;
                else if (diff == 1) dp[i][j] = (s.charAt(i) == s.charAt(j)) ? 1 : 0;
                else {
                    if (dp[i + 1][j - 1] != 0 && s.charAt(i) == s.charAt(j)) dp[i][j] = dp[i + 1][j - 1];
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
}