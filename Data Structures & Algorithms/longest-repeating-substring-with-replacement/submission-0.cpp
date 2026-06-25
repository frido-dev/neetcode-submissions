class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxFreq = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;

            maxFreq = max(maxFreq, mp[s[i]]);

            while((i - left + 1 - maxFreq) > k) {
                mp[s[left]]--;
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};
