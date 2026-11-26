class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' or s[i] == '*') open++;
            else open--;

            if (s[s.size() - 1 - i] == ')' or s[s.size() - 1 - i] == '*') close++;
            else close--;

            if (open < 0 or close < 0) return false;
        }

        return true;
    }
};
