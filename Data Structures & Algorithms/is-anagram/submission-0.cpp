class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        int n = s.length(), m = t.length();
        if (n != m) return false;
        for (int i = 0; i < n; i++){
            s_map[s[i]]++;
            t_map[t[i]]++;
        }
        for (auto p : s_map){
            if (t_map[p.first] != p.second) return false;
        }
        return true;
    }
};
