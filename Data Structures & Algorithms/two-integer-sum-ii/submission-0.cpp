class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sizeNum = numbers.size();
        int i = 0, j = sizeNum - 1;
        vector<int> res;

        while (i < j) {
            int currSum = numbers[i] + numbers[j];
            if (currSum == target) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            } else if (currSum > target) {
                j--;
            } else {
                i++;
            }
        }

        return res;
    }
};
