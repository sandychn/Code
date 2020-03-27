// Time  : 52 ms
// Memory: 16.7 MB

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int cnt[10000] = {};
        for (int val : deck) ++cnt[val];
        int g = 0;
        for (int i = 0; i < 10000; i++)
            if (cnt[i]) g = g ? __gcd(g, cnt[i]) : cnt[i];
        return g > 1;
    }
};
