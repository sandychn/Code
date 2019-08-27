class Solution {
public:
    string int2String(int x) {
        string str;
        while (x) str += x % 10 + '0', x /= 10;
        reverse(str.begin(), str.end());
        return str;
    }
    
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.reserve(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) res.emplace_back("FizzBuzz");
            else if (i % 3 == 0) res.emplace_back("Fizz");
            else if (i % 5 == 0) res.emplace_back("Buzz");
            else res.emplace_back(move(int2String(i)));
        }
        return res;
    }
};