// Time  : 0 ms (100.00%)
// Memory: 11.6 MB (5.20%)

namespace std {
    template<>
    struct hash<pair<int, int>>  {
        size_t operator()(const pair<int, int> &p) const {
            return p.first * 131 + p.second;
        }
    };
}

class Solution {
   public:
    int uniquePaths(int m, int n) {
        return helper(n + m - 2, n - 1);
    }

private:
    unordered_map<pair<int, int>, int> mp;
    int helper(int m, int n) {
        if (n == 0 || n == m) return 1;

        auto it = mp.find(make_pair(m, n));
        if (it == mp.end()) {
            return mp[make_pair(m, n)] = helper(m - 1, n - 1) + helper(m - 1, n);
        }
        return it->second;
    }
};
