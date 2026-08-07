class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> waitingIndices;
        for (int i = 0; i < temperatures.size(); i++){
            while (!waitingIndices.empty() && temperatures[i] > temperatures[waitingIndices.top()]){
                result[waitingIndices.top()] = i - waitingIndices.top();
                waitingIndices.pop();
            }
            waitingIndices.push(i);
        }
        return result;
    }
};
