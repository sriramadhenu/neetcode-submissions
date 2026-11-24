class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sizes;
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        unordered_set<char> used;
        int size = 0;

        for (int i = 0; i < s.size(); i++){
            used.insert(s[i]);
            freq[s[i]]--;
            size++;

            bool open = false;
            for (char c : used){
                if (freq[c] > 0){
                    open = true;
                    break;
                }
            }
            
            if (!open){
                sizes.push_back(size);
                size = 0;
                used.clear();
            }
        }

        return sizes;
    }
};
