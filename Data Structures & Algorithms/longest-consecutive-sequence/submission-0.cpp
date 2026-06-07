class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        vector<int> sortedNum;
        int maxLen = 1;
        int currLen = 1;
        int prevEle = INT_MAX;

        if (nums.size() == 0 || nums.size() == 1) return nums.size();

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (int num: st) {
            sortedNum.push_back(num);
        }

        prevEle = sortedNum[0];
        
        for (int i = 1; i < sortedNum.size(); i++) {
            if (prevEle + 1 == sortedNum[i]) {
                currLen++;
            } else {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
            prevEle = sortedNum[i];
        }

        maxLen = max(maxLen, currLen);

        return maxLen;
    }
};
