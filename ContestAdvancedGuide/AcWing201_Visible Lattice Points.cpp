// 2019-04-26
#include <iostream>

using namespace std;
const int N = 1e4;
int phi[N + 6], sum[N + 6];

void euler(int n) {
    for (int i = 2; i <= n; ++i) phi[i] = i;
    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    euler(N);
    for (int i = 2; i <= N; ++i) sum[i] = sum[i - 1] + phi[i];
    int t, n;
    cin >> t;
    for (int kase = 1; t--; ++kase) {
        cin >> n;
        cout << kase << ' ' << n << ' ' << sum[n] * 2 + 3 << endl;
    }
    return 0;
}
