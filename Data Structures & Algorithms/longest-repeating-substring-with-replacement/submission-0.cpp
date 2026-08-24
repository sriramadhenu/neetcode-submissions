class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int left = 0, maxLength = 0, maxFreq = 0;
        for (int right = 0; right < s.size(); right++){
            m[s[right]]++;
            maxFreq = max(maxFreq, m[s[right]]);

            while ((right - left + 1) - maxFreq > k){
                m[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
