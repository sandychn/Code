// Time  : 8 ms (100.00%)
// Memory: 10.7 MB (76.04%)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        // use `i` to find odd number, `j` to find even number
        // and swap them.
        while (i < j) {
            while (i < j && (A[i] & 1) == 0) ++i;
            while (i < j && (A[j] & 1) == 1) --j;
            if (i < j) {
                swap(A[i], A[j]);
                ++i;
                --j;
            }
        }
        return A;
    }

private:
    vector<int> sortArrayByParity_self(vector<int>& A) {
        vector<int> v[2];
        for (int value : A) {
            v[value & 1].push_back(value);
        }
        v[0].insert(v[0].end(), v[1].begin(), v[1].end());
        return v[0];
    }
};