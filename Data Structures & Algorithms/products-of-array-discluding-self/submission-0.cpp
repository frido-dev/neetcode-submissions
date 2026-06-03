class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        vector<int> suffix;
        vector<int> res;
        prefix.push_back(1);
        suffix.push_back(1);
        int prefixProd = 1;
        int suffixProd = 1;

        for (int i = 0; i < n - 1; i++) {
            prefixProd*= nums[i];
            prefix.push_back(prefixProd);
        }

        for (int i = n-1; i >= 1; i--) {
            suffixProd*= nums[i];
            suffix.push_back(suffixProd);
        }

        reverse(suffix.begin(), suffix.end());

        for (int i = 0; i < n; i++) {
            res.push_back(suffix[i] * prefix[i]);
        }

        return res;
    }
};
