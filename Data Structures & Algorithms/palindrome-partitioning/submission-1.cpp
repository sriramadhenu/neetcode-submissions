class Solution {
public:
    bool isPalindrome(const string& s){
        int i = 0, j = s.size() - 1;
        while (i < j){
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        
        function<void(int)> dfs = [&](int start){
            if (start == s.size()){
                result.push_back(current);
                return;
            }

            for (int end = start; end < s.size(); end++){
                string str = s.substr(start, end - start + 1);
                if (isPalindrome(str)){
                    current.push_back(str);
                    dfs(end + 1);
                    current.pop_back();
                }
            }
        };

        dfs(0);
        return result;
    }
};
