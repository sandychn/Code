// 2019-02-07
#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    nth_element(a, a + (n + 1) / 2 - 1, a + n);
    int ans = 0, mid = a[(n + 1) / 2 - 1];
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - mid);
    }
    cout << ans << endl;
    return 0;
}
