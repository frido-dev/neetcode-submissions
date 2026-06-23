class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        vector<int> combinedNum;

        while(i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                combinedNum.push_back(nums1[i]);
                i++;
            } else {
                combinedNum.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n) {
            combinedNum.push_back(nums1[i]);
            i++;
        }

        while (j < m) {
            combinedNum.push_back(nums2[j]);
            j++;
        }

        int combinedSize = m + n;
        float median = 0;

        if (combinedSize % 2 == 0) {
            int m1 = combinedSize/2;

            median = (float)(combinedNum[m1-1] + combinedNum[m1])/2;
        } else {
            int m1 = (combinedSize - 1)/2;
            median = combinedNum[m1];
        }

        return median;
    }
};
