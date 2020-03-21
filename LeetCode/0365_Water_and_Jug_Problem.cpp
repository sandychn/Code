// Time  : 1228 ms
// Memory: 185.6 MB

class Solution {
private:
    using PII = pair<int, int>;

public:
    struct MyHash {
        size_t operator()(const PII &p) const {
            return static_cast<size_t>(p.first) * 131 + p.second;
        }
    };

    bool canMeasureWater(int x, int y, int z) {
        unordered_set<PII, MyHash> st;
        queue<PII> q;
        q.emplace(0, 0);
        st.emplace(0, 0);
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (now.first == z || now.second == z || now.first + now.second == z) return true;
            // A倒空
            if (now.first != 0 && !st.count({0, now.second})) {
                st.emplace(0, now.second);
                q.emplace(0, now.second);
            }
            // B倒空
            if (now.second != 0 && !st.count({now.first, 0})) {
                st.emplace(now.first, 0);
                q.emplace(now.first, 0);
            }
            // A倒满
            if (now.first != x && !st.count({x, now.second})) {
                st.emplace(x, now.second);
                q.emplace(x, now.second);
            }
            // B倒满
            if (now.second != y && !st.count({now.first, y})) {
                st.emplace(now.first, y);
                q.emplace(now.first, y);
            }
            // A把B倒满或把A倒空
            if (now.first != 0) {
                int amount = min(y - now.second, now.first);
                if (!st.count({now.first - amount, now.second + amount})) {
                    st.emplace(now.first - amount, now.second + amount);
                    q.emplace(now.first - amount, now.second + amount);
                }
            }
            // B把A倒满或把B倒空
            if (now.second != 0) {
                int amount = min(x - now.first, now.second);
                if (!st.count({now.first + amount, now.second - amount})) {
                    st.emplace(now.first + amount, now.second - amount);
                    q.emplace(now.first + amount, now.second - amount);
                }
            }
        }
        return false;
    }
};
