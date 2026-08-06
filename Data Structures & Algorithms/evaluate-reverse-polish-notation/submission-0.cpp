class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string str : tokens){
            if (str == "+" || str == "-" || str == "*" || str == "/"){
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                if (str == "+") st.push(val1 + val2);
                else if (str == "-") st.push(val1 - val2);
                else if (str == "*") st.push(val1 * val2);
                else st.push(val1 / val2);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
