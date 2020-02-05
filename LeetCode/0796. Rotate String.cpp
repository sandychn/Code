// Time  : 0 ms (100.00%)
// Memory: 8.4 MB (40.21%)

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.length() == B.length() && (A + A).find(B) != string::npos;
    }
};
