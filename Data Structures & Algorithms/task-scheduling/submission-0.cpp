class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxCount = 0;

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        for (int fq: freq) {
            maxFreq = max(fq, maxFreq);
        }

        for (int fq: freq) {
            if (fq == maxFreq) {
                maxCount++;
            }
        }

        int interval = (maxFreq - 1) * (n + 1) + maxCount;
        int arrSize = tasks.size();
        return max(arrSize, interval);
    }
};
