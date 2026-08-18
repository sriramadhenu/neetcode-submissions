class TimeMap {
private:
    // there should be a key-value data structure such that one key can hold pairs of timestamps + values
    // keys and values are strings, whereas the timestamp is an int
    // data structure: hashmap of string : pair<int, string>
    unordered_map<string, vector<pair<int, string>>> tmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (tmap.find(key) == tmap.end()) return "";
        vector<pair<int, string>>& values = tmap[key];
        // get the largest present timestamp that is <= timestamp
        int n = values.size();
        int low = 0;
        int high = n - 1;
        string ans = "";

        while (low <= high){
            int mid = low + (high - low) / 2;
            if (timestamp == values[mid].first) return values[mid].second;
            else if (timestamp > values[mid].first){
                ans = values[mid].second;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
