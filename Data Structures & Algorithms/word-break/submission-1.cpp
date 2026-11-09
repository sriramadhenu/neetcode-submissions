class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        // dp[i] is true if the first i letters can be split into words in wordDict
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++){
            for (const string& word : wordDict){
                int n = word.size();
                if (n <= i && s.substr(i - n, n).compare(word) == 0 && dp[i - n]) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
