// Time  : 20 ms (11.55%)
// Memory: 15.5 MB (66.94%)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return vector<string>{""};
        }
        vector<string> res;
        for (int c = 0; c < n; c++) {
            for (const string& left : generateParenthesis(c)) {
                for (const string &right : generateParenthesis(n - c - 1)) {
                    res.emplace_back("(" + left + ")" + right);
                }
            }
        }
        return res;
    }
};
