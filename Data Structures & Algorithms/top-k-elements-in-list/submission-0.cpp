class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for (auto& num : nums){
            frequencies[num]++;
        }

        vector<pair<int, int>> freqs;
        for (auto& [number, freq] : frequencies){
            freqs.push_back({number, freq});
        }

        sort(freqs.begin(), freqs.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < k && i < freqs.size(); i++){
            result.push_back(freqs[i].first);
        }
        return result;
    }
};
