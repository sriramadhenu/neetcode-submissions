class Solution {
public:
    bool isValid(string s) {
        stack<char> pars;
        for (char c : s){
            if (c == '(' || c == '{' || c == '[') pars.push(c);
            else {
                if (pars.empty()) return false;
                char top = pars.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    pars.pop();
                } else {
                    return false;
                }
            }
        }
        return pars.empty();
    }
};