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

        vector<pair<int, int>> sortedArr;

        for (auto [key, value]: mp) {
            pair<int, int> pr;
            pr.first = value;
            pr.second = key;
            sortedArr.push_back(pr);
        }

        sort(sortedArr.begin(), sortedArr.end());
        int n = sortedArr.size();

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(sortedArr[n- i - 1].second);
        }

        return res;

    }
};
