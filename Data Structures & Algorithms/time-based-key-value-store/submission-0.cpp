class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        string res = "";
        auto arr = mp[key];
        int left = 0, right = arr.size() - 1;

        while(left <= right) {
            int mid = (right + left) / 2;

            if (arr[mid].second <= timestamp) {
                res = arr[mid].first;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;

    }
};
