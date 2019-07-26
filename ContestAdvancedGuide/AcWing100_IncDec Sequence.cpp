// 2019-02-27
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve() {
        ios::sync_with_stdio(false);
        int n, x;
        cin >> n;
        long long positive = 0, negiatve = 0;
        long long pre = 0, now;
        for (int i = 0; i < n; ++i) {
            cin >> now;
            if (i) {
                if (now - pre > 0) {
                    positive += now - pre;
                } else {
                    negiatve += pre - now;
                }
            }
            pre = now;
        }
        cout << min(positive, negiatve) + abs(negiatve - positive) << endl;
        cout << abs(negiatve - positive) + 1 << endl;
    }
} sol;

int main() {
    sol.solve();
    return 0;
}
