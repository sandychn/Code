// Time  : 4 ms (87.63%)
// Memory: 8.9 MB (40.34%)

class Solution {
public:
    string countAndSay(int n) {
        string str[2];
        str[1] = "1";
        for (int i = 2; i <= n; i++) {
            str[i & 1] = get(str[(i & 1) ^ 1]);
        }
        return str[n & 1];
    }
    
private:
    string intToString(int val) {
        if (val == 0) return "0";
        string temp;
        while (val) temp += val % 10 + '0', val /= 10;
        reverse(temp.begin(), temp.end());
        return temp;
    }
    string get(const string &s) {
        string temp;
        char pre = s[0];
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == pre) {
                count++;
            } else {
                temp += intToString(count) + pre;
                // temp += to_string(count) + pre;
                count = 1;
                pre = s[i];
            }
        }
        if (count) {
            temp += intToString(count) + pre;
        }
        return temp;
    }
};
