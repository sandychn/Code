class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (-(long long)n)) == n;
    }
};