class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool hit[3] = {false, false, false};
        
        for (auto& triplet : triplets){
            if (triplet[0] > target[0] or triplet[1] > target[1] or triplet[2] > target[2]) continue;
            for (int k = 0; k < 3; k++){
                if (triplet[k] == target[k]) hit[k] = true;
            }
        }
        return hit[0] and hit[1] and hit[2];
    }
};
