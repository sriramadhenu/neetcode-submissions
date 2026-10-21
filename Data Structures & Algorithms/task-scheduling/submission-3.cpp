class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;

        priority_queue<int> maxHeap;
        for (int f : freq){
            if (f > 0) maxHeap.push(f);
        }

        // {remaining count, time until ready (time + n - time passed)}
        queue<pair<int, int>> cooldown;
        while (!maxHeap.empty() || !cooldown.empty()){
            time++;
            if (!maxHeap.empty()){
                int num = maxHeap.top();
                maxHeap.pop();
                num--;
                if (num > 0) cooldown.push({num, time + n});
            }
            if (!cooldown.empty()){
                pair<int, int> p = cooldown.front();
                if (p.second == time){
                    maxHeap.push(p.first);
                    cooldown.pop();
                }
            }
        }

        return time;
    }
};
