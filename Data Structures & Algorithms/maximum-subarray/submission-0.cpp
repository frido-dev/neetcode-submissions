class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxSum = max(nums[i], maxSum + nums[i]);
            res = max(res, maxSum);
        }

        return res;
    }
};
