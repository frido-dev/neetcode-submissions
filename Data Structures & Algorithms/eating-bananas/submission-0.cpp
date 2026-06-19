class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1;
        int r = piles[piles.size() - 1];
        int ans = r;

        while(l <= r) {
            int mid = (l + r) / 2;

            long long hrs = 0;

            for (int i = 0; i <= piles.size() - 1; i++) {
                if (piles[i] <= mid) {
                    hrs+= 1;
                } else {
                    hrs+= ( piles[i] + mid -1 )/mid;
                }
            }

            if (hrs <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
