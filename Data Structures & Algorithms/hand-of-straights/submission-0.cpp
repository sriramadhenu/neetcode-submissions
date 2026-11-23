class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> frequencies;
        for (const int& h : hand) frequencies[h]++;

        while (!frequencies.empty()){
            int start = frequencies.begin()->first;
            for (int i = 0; i < groupSize; i++){
                if (frequencies.count(start + i) == 0) return false;
                else {
                    frequencies[start + i]--;
                    if (frequencies[start + i] == 0) frequencies.erase(start + i);
                }
            }
        }
        return true;
    }
};
