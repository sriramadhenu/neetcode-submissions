class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> mapping = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string current = "";

        function<void(int)> dfs = [&](int index){
            if (current.size() == digits.size()){
                result.push_back(current);
                return;
            }

            for (int start = index; start < digits.size(); start++){
                string str = mapping[digits[start]];
                for (char c : str){
                    current.push_back(c);
                    dfs(start + 1);
                    current.pop_back();
                }
            }
        };

        dfs(0);
        return result;
    }
};
