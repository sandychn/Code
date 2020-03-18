// Time  : 4 ms
// Memory: 7.9 MB

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[52] = {};
        for (char ch : s) ++cnt[getId(ch)];
        int res = 0;
        bool flag = false;
        for (int i = 0; i < 52; i++) {
            res += cnt[i] - (cnt[i] & 1);
            if (!flag && (cnt[i] & 1)) {
                ++res;
                flag = true;
            }
        }
        return res;
    }
private:
    int getId(char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch - 'A';
        return ch - 'a' + 26;
    }
};
