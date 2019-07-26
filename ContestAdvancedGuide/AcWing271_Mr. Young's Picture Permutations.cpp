// 2019-04-15
#include <cstring>
#include <iostream>

using namespace std;
const int MAX_ROW = 6;
const int MAX_N = 35;

int a[MAX_ROW];
unsigned int dp[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N];

int main() {
    int k;
    while (cin >> k && k) {
        for (int i = 1; i <= k; ++i) cin >> a[i];
        for (int i = k + 1; i <= 5; ++i) a[i] = 0; // 增加人数为0的排

        for (int i1 = 0; i1 <= a[1]; ++i1) {
            for (int i2 = 0; i2 <= a[2]; ++i2) {
                for (int i3 = 0; i3 <= a[3]; ++i3) {
                    for (int i4 = 0; i4 <= a[4]; ++i4) {
                        for (int i5 = 0; i5 <= a[5]; ++i5) {
                            dp[i1][i2][i3][i4][i5] = 0;
                        }
                    }
                }
            }
        }
        dp[0][0][0][0][0] = 1;
        
        for (int i1 = 0; i1 <= a[1]; ++i1) {
            for (int i2 = 0; i2 <= a[2]; ++i2) {
                for (int i3 = 0; i3 <= a[3]; ++i3) {
                    for (int i4 = 0; i4 <= a[4]; ++i4) {
                        for (int i5 = 0; i5 <= a[5]; ++i5) {
                            unsigned int now = dp[i1][i2][i3][i4][i5];
                            if (i1 < a[1]) dp[i1 + 1][i2][i3][i4][i5] += now;
                            if (i2 < a[2] && i1 > i2) dp[i1][i2 + 1][i3][i4][i5] += now;
                            if (i3 < a[3] && i2 > i3) dp[i1][i2][i3 + 1][i4][i5] += now;
                            if (i4 < a[4] && i3 > i4) dp[i1][i2][i3][i4 + 1][i5] += now;
                            if (i5 < a[5] && i4 > i5) dp[i1][i2][i3][i4][i5 + 1] += now;
                        }
                    }
                }
            }
        }
        
        cout << dp[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
    }
    return 0;
}