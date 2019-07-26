// 2019-04-18
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1 << 16;
const int M = 1e6;
const int INF = 0x3F3F3F3F;

bool v[N + 5], p[M + 5];
int prime[N + 5], tot;

void primes(int n) {
    tot = 0;
    for (int i = 2; i <= n; ++i) {
        if (v[i]) continue;
        prime[++tot] = i;
        for (int j = i; j <= n / i; ++j) {
            v[i * j] = true;
        }
    }
}

int main() {
    primes(N);
    int l, u;
    while (scanf("%d%d", &l, &u) != EOF) {
        for (int i = 0; i <= u - l; ++i) p[i] = false;

        // for each prime number, visit p[]
        for (int i = 1; i <= tot; ++i) {
            int num = prime[i];
            for (int j = l / num; j <= u / num; ++j) {
                if (j > 1 && 1LL * j * num >= l) {
                    p[1LL * j * num - l] = true;
                }
            }
        }

        vector<int> nums;
        for (int i = 0; i <= u - l; ++i) {
            if (!p[i] && i + l != 1) {
                nums.push_back(i + l);
            }
        }

        pair<int, int> closest, distant;
        int closestDist = INF, distantDist = -INF;

        for (size_t i = 0; i + 1 < nums.size(); ++i) {
            int diff = nums[i + 1] - nums[i];
            if (diff > distantDist) {
                distantDist = diff;
                distant = {nums[i], nums[i + 1]};
            }
            if (diff < closestDist) {
                closestDist = diff;
                closest = {nums[i], nums[i + 1]};
            }
        }

        if (nums.size() <= 1) {
            puts("There are no adjacent primes.");
        } else {
            printf("%d,%d are closest, %d,%d are most distant.\n",
                   closest.first, closest.second, distant.first,
                   distant.second);
        }
    }
    return 0;
}