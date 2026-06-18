class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = -1;

        for (int i = 0; i < m; i++) {
            if (target <= matrix[i][n-1]) {
                row = i;
                break;
            }
        }

        if (row == -1) return false;

        int l = 0;
        int r = n - 1;

        while(l <= r) {
            int mid = (l + r)/2;

            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
