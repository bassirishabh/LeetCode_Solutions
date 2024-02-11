class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n];

        for (int i = 0; i < n; i++) {
            for (String word : wordDict) {
                if (i < word.length() - 1) continue;
                if (i == word.length() - 1 || dp[i - word.length()]) {
                    String substr = s.substring(i - word.length() + 1, i + 1);
                    if (substr.equals(word)) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
}