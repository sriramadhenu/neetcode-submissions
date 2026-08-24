class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (char c : s1) freq[c]++;

        int n = s1.size(), m = s2.size();
        unordered_map<char, int> freq2;
        for (int i = 0; i < n; i++) freq2[s2[i]]++;
        if (freq == freq2) return true;

        for (int i = 1; i < m - n + 1; i++){
            freq2[s2[i - 1]]--;
            if (freq2[s2[i - 1]] == 0) freq2.erase(s2[i - 1]);
            freq2[s2[i + n - 1]]++;
            if (freq == freq2) return true;
        }
        return false;
    }
};
