class Solution {
public:
    bool check(vector<int> piles, int h, int k){
        int totalHours = 0;
        for (int i = 0; i < piles.size(); i++){
            int hours = ceil((double)piles[i] / k);
            totalHours += hours;
        }
        return (totalHours <= h) ? true : false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_it = max_element(piles.begin(), piles.end());
        int max_pile = *max_it, low = 1, high = max_pile;

        while (low <= high){
            int rate = low + (high - low) / 2;
            bool completed = check(piles, h, rate);

            if (!completed) low = rate + 1;
            else high = rate - 1;
        }
        return low;
    }
};
