class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums){
            if (seen[num] != 0) return num;
            else seen[num]++;
        }
        return -1;
    }
};
