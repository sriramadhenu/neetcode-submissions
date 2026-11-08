class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int prev2 = 1;
        int prev1 = (s[0] == '0') ? 0 : 1;
        for (int i = 2; i < n + 1; i++){
            int cur = 0;
            if (s[i - 1] != '0') cur += prev1;
            int two = stoi(s.substr(i - 2, 2));
            if (two >= 10 && two <= 26) cur += prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
