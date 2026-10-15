class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        vector<int> result;

        for (int num : nums) mp[num]++;
        for (auto it : mp) pq.push({it.second, it.first});
        for (int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
