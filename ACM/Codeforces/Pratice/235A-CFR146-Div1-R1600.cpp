#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

// vector<int> v;
// vector<int> select;
// LL ans;

// LL lcm(LL a, LL b, LL c) {
//     LL res = a / __gcd(a, b) * b;
//     return res / __gcd(res, c) * c;
// }

// void dfs() {
//     if (select.size() == 3) {
//         ans = max(ans, lcm(select[0], select[1], select[2]));
//         return;
//     }
//     for (int i = 0; i < (int)v.size(); ++i) {
//         select.push_back(v[i]);
//         dfs();
//         select.pop_back();
//     }
// }

// there is a better solution for this problem in main().
// all commented code is a dfs solution I used when solving this problem
// which is not the best.
// uncommented code is the best solution read from the tutorial's comments.

int main() {
    int n;
    cin >> n;
    // for (int i = n; i >= max(1, n - 5); --i) v.push_back(i);
    // dfs();
    // cout << ans << endl;
    LL ans = 1;
    if (n == 1) {
        ans = 1;
    } else if (n == 2) {
        ans = 2;
    } else if (n == 3) {
        ans = 6;
    } else if (n % 2 == 1) {                // this line below, n is an odd number
        ans = 1LL * n * (n - 1) * (n - 2);  // they are all coprimes.
    } else if (n % 3 != 0) {
        ans = 1LL * n * (n - 1) * (n - 3);
    } else {
        // n % 3 == 0 makes (n) and (n - 3) not coprime
        // so in this case, we cannot use (n) and (n - 3) together
        ans = 1LL * (n - 1) * (n - 2) * (n - 3); // they are all coprimes.
    }
    cout << ans << endl;
    return 0;
}