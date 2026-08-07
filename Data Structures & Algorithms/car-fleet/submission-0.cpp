class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int numFleets = 0;
        vector<pair<int, int>> cars; // (position, speed)
        for (int i = 0; i < position.size(); i++) cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<>());

        stack<double> fleets;
        for (auto [pos, spd] : cars){
            double time = (double)(target - pos) / spd;
            if (fleets.empty() || time > fleets.top()) fleets.push(time);
        }

        return fleets.size();
    }
};
