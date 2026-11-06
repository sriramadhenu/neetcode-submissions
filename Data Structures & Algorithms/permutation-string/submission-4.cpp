class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> s1freq;
        unordered_map<char, int> s2freq;
        for (char c : s1) s1freq[c]++;

        int left = 0;
        for (int i = 0; i < s1.size(); i++) s2freq[s2[i]]++;
        if (s1freq == s2freq) return true;
        
        for (int right = s1.size(); right < s2.size(); right++){
            s2freq[s2[right]]++;
            s2freq[s2[left]]--;
            if (s2freq[s2[left]] == 0) s2freq.erase(s2[left]);
            if (s2freq == s1freq) return true;
            left++;
        }
        return false;
    }
};
