class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        unordered_map<int, int> frequencies;

        for (int i = 0; i < n; i++) frequencies[nums[i]]++;

        for (auto& [num, freq] : frequencies) buckets[freq].push_back(num);

        vector<int> result;
        for (int i = n; i >= 0; i--){
            if (buckets[i].empty()) continue;
            for (auto& num : buckets[i]){        
                result.push_back(num);
                k--;
                if (k == 0) return result;
            }
        }
        return result;
    }
};
