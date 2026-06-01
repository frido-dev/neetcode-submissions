class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0, j = n-1;

        while(i < j) {
            int sum = arr[i].first + arr[j].first;
            if (sum == target) {
                break;
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }

        res.push_back(arr[i].second);
        res.push_back(arr[j].second);
        sort(res.begin(), res.end());

        return res;
    }
};
