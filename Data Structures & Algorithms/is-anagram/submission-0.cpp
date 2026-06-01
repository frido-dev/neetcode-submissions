class Solution {
public:
    bool isAnagram(string s, string t) {
        int hashArray[27] = {0};

        int sizeS = s.length();
        int sizeT = t.length();

        if (sizeS != sizeT) return false;

        for (auto ch: s) {
            hashArray[int(ch) - 97]++;
        }

        for (auto ch: t) {
            hashArray[int(ch) - 97]--;
        }

        for (int i = 0; i <= 26; i++) {
            if (hashArray[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
