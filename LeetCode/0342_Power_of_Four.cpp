// Time  : 0 ms (100.00%)
// Memory: 8.2 MB (7.64%)

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num & 0x55555555) == num && (num & -num) == num);
    }
};
