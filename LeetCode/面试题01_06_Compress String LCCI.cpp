// Time  : 8 ms
// Memory: 9 MB

class Solution {
public:
    string compressString(string S) {
        if (S.empty()) {
            return S;
        }
        string T;
        char pre = S[0];
        int cnt = 0;
        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == pre) ++cnt;
            else {
                T += pre;
                T += to_string(cnt);
                if (T.size() >= S.size()) return S;
                pre = S[i];
                cnt = 1;
            }
        }
        if (cnt) {
            T += pre;
            T += to_string(cnt);
            if (T.size() >= S.size()) return S;
        }
        return T;
    }
};
