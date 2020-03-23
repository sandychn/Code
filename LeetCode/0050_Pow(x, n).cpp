// Time  : 0 ms
// Memory: 7.4 MB

class Solution {
public:
    double myPow(double x, int n) {
        if (floatEqual(x, 0) && n == 0) {
            throw invalid_argument("Invalid parameters.");
        }

        double res = 1.0;

        bool negN = false;
        unsigned int exponent;
        if (n < 0) {
            negN = true;
            exponent = -static_cast<unsigned int>(n);
        } else {
            exponent = static_cast<unsigned int>(n);
        }
        
        while (exponent) {
            if (exponent & 1) res = res * x;
            x = x * x;
            exponent >>= 1;
        }
        return negN ? 1.0 / res : res;
    }

private:
    bool floatEqual(double x, double y) {
        return fabs(x - y) < 1e-7;
    }
};
