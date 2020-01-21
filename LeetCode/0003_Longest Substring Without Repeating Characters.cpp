class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = -1;
        int cnt[129] = {0};
        while (++r < s.size()) {
            int next = s[r];
            ++cnt[next];
            while (cnt[next] > 1) {
                --cnt[s[l]];
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};