// Time  : 16 ms (71.03%)
// Memory: 8.1 MB (34.88%)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long xx = x;
        long long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return xx == y;
    }
};