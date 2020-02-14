// Time  : 4 ms (94.47%)
// Memory: 13.9 MB (74.00%)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        dfs(res, n, 0, tmp);
        return res;
    }

private:
    void dfs(vector<string>& res, int parenthesToAdd, int parenthesToEnd, string &now) {
        if (parenthesToAdd == 0 && parenthesToEnd == 0) {
            res.emplace_back(now);
            return;
        }
        if (parenthesToAdd > 0) {
            now.push_back('(');
            dfs(res, parenthesToAdd - 1, parenthesToEnd + 1, now);
            now.pop_back();
        }
        if (parenthesToEnd > 0) {
            now.push_back(')');
            dfs(res, parenthesToAdd, parenthesToEnd - 1, now);
            now.pop_back();
        }
    }
};
