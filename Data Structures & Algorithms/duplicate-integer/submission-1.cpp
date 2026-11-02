class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums){
            if (m.count(num) == 0) m[num]++;
            else return true;
        }
        return false;
    }
};