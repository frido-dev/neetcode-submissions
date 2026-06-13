class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        int left = 0;
        int right = n-1;

        while(left < right) {
            int area = (right - left) * min(heights[left], heights[right]);
            maxArea = max(maxArea, area);

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }
};
