class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";

        function<void(int, int)> dfs = [&](int open, int close){
            if (current.size() == 2 * n){
                result.push_back(current);
                return;
            }

            if (open < n){
                current.push_back('(');
                dfs(open + 1, close);
                current.pop_back();
            }

            if (close < open){
                current.push_back(')');
                dfs(open, close + 1);
                current.pop_back();
            }
        };

        dfs(0, 0);
        return result;
    }
};
