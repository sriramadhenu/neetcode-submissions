class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s){
            if (isalnum(c)) str += tolower(c);
        }
        int k = str.size() - 1, i = 0;
        while (i < k){
            if (str[i] != str[k]) return false;
            i++;
            k--;
        }
        return true;
    }
};
