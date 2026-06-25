class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> arr1(26,0);
        vector<int> arr2(26,0);

        for (int i = 0; i < n; i++) {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }

        if (arr1 == arr2) return true;

        for (int i = n; i < m; i++) {
            arr2[s2[i] - 'a']++;
            arr2[s2[i - n] - 'a']--;

            if (arr1 == arr2) return true;
        }

        return false;
    }
};
