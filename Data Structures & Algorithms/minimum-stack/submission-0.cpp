class MinStack {
private:
    stack<int> st, mins;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (mins.empty()) mins.push(val);
        else {
            int top = mins.top();
            if (val <= top) mins.push(val);
        }
    }
    
    void pop() {
        int min = mins.top();
        int top = st.top();
        if (top == min) {
            st.pop(); 
            mins.pop();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
