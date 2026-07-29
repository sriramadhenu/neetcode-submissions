class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s;
        for (int num : nums) s.insert(num);

        int longest = 0;
        for (int num : s){
            if (!s.contains(num - 1)){
                int j = num + 1, length = 1;
                while (s.contains(j)){
                    j++;
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
