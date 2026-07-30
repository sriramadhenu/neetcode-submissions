class Solution {
public:
    bool isPalindrome(string s) {
        string used = "";
        for (char c : s){
            if (isalnum(c)) used += tolower(c);
        }

        int n = used.size() - 1;
        for (int i = 0; i < (used.size() / 2); i++){
            if (used[i] != used[n]) return false;
            n--;
        }
        return true;
    }
};
