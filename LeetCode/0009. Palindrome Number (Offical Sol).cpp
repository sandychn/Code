// Time  : 16 ms (71.03%)
// Memory: 8 MB (84.09%)

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        // With respect to the following algorithm may give a wrong verdict
        // when x % 10 == 0, check for that.
        // When x % 10 == 0, the first digit of x must be 0 too, i.e. x == 0.
        if (x % 10 == 0) return x == 0; 

        int revNumber = 0;
        while (x > revNumber) {
            revNumber = revNumber * 10 + x % 10;
            x /= 10;
        }

        // if the length of the original x is an even number, now x should be equal to revNumber.
        // otherwise, original x is an odd number, now x should be equal to revNumber / 10.
        return x == revNumber || x == revNumber / 10;
    }
};