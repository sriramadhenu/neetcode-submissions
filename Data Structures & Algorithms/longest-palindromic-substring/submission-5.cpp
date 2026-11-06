class Solution {
public:
    int expandFromCenter(const string& s, int left, int right){
        while (left >= 0 && right < s.size() and s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        int start = 0;
        for (int i = 0; i < s.size(); i++){
            int odd = expandFromCenter(s, i, i);
            int even = expandFromCenter(s, i, i + 1);
            if (max(odd, even) > maxLen){
                maxLen = max(odd, even);
                start = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
