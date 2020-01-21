class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0, last = (int)s.size() - 1;
        while (first < last) {
            char tmp = s[first];
            s[first++] = s[last];
            s[last--] = tmp;
        }
    }
};