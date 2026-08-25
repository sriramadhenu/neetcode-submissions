class Solution {
public:
    string minWindow(string s, string t) {
        int length = INT_MAX;
        // everytime you slide the window and get to a substring that contains every character in t
        // check the size of the substring
        // if it is smaller than the current size of shortest, set shortest to this new substring
        // dynamically sized sliding window, so have two separate pointers: left and right
        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int left = 0;
        unordered_map<char, int> freq_tracker;
        int have = 0, need = freq.size();
        pair<int, int> res = {-1, -1};

        // sliding window
        for (int right = 0; right < s.size(); right++){
            // logic to update have and need
            // i think: increment left until left == right OR we have the shortest VALID substring
            // THEN increment right
            freq_tracker[s[right]]++;
            if (freq.count(s[right]) != 0 && freq_tracker[s[right]] == freq[s[right]]) have++;

            // then if have == need, update shortest and length
            while (have == need){
                int windowLen = right - left + 1;
                if (windowLen < length){
                    length = right - left + 1;
                    res = {left, right};
                }

                // shrinking window by incrementing left
                freq_tracker[s[left]]--;
                if (freq.count(s[left]) != 0 && freq_tracker[s[left]] < freq[s[left]]) have--;
                left++;
            }
        }
        return length == INT_MAX ? "" : s.substr(res.first, length);
    }
};
