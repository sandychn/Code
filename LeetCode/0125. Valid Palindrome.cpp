// Time  : 8 ms (84.95%)
// Memory: 9.3 MB (69.42%)

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (tolower(s[i]) == tolower(s[j])) ++i, --j;
            else return false;
        }
        return true;
    }
};
