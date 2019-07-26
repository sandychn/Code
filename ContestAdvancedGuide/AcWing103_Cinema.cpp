// 2019-02-02
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int sciLang[200005], audioLang[200005], subttLang[200005];
int mp[200005 * 3], cnt[200005 * 3];
int siz;

inline int getId(int val) {
    return lower_bound(mp, mp + siz, val) - mp;
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", sciLang + i), mp[i] = sciLang[i];
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", audioLang + i), mp[n + i] = audioLang[i];
    for (int i = 0; i < m; ++i) scanf("%d", subttLang + i), mp[n + m + i] = subttLang[i];
    sort(mp, mp + n + 2 * m);
    siz = unique(mp, mp + n + 2 * m) - mp;
    for (int i = 0; i < n; ++i) {
        ++cnt[getId(sciLang[i])];
    }
    int ans = 0, bestAudio = -1, bestSubtt = -1;
    for (int i = 0; i < m; ++i) {
        int audio = cnt[getId(audioLang[i])], subtt = cnt[getId(subttLang[i])];
        if (audio > bestAudio || (audio == bestAudio && subtt > bestSubtt)) {
            ans = i;
            bestAudio = audio;
            bestSubtt = subtt;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
