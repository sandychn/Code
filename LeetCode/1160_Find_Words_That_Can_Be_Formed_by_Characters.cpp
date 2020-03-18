// Time  : 44 ms
// Memory: 15.7 MB

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {};
        int tmp[26];
        for (char ch : chars) ++cnt[ch - 'a'];
        int ans = 0;
        for (const string& str : words) {
            bool f = true;
            memcpy(tmp, cnt, sizeof(tmp));
            for (char ch : str) {
                if (--tmp[ch - 'a'] < 0) {
                    f = false;
                    break;
                }
            }
            if (f) ans += str.size();
        }
        return ans;
    }
};
