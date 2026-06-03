class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num: nums) {
            if (mp.find(num) != mp.end()) {
                mp[num]+= 1;
            } else {
                mp.insert({num, 1});
            }
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto [key, value]: mp) {
           bucket[value].push_back(key);
        }

        vector<int> res;

        for (int i = n; i >= 0 && res.size() < k; i--) {
    for (int num : bucket[i]) {
        res.push_back(num);

        if (res.size() == k)
            return res;
    }
}

    }
};
