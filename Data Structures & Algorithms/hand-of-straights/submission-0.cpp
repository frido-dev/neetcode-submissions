class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> count;

        for (int val : hand) {
            count[val]++;
        }

        for (auto [card, freq] : count) {
            if (freq == 0) continue;

            for (int x = card; x < card + groupSize; x++) {
                if (count[x] < freq) return false;

                count[x]-= freq; 
            }
        }

        return true;
    }
};
