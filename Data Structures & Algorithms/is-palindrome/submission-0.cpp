class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = "";
        bool isPassed = true;

        int sSize = s.length();
        if (sSize == 1) return true;

        for (char ch: s) {
            if (isalnum(ch)) {
                cleanString+= tolower(ch);
            }
        }

        int n = cleanString.length() - 1;
        int i = 0;

        while(i < n) {
            if (cleanString[i] != cleanString[n]) {
                isPassed = false;
                break;
            }

            i++;
            n--;
        }

        return isPassed;
    }
};
