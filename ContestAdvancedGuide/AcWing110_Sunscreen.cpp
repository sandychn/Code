// 2019-02-07
#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

struct Cow {
    int minspf, maxspf;
    bool operator<(const Cow &b) const {
        return minspf > b.minspf;
    }
} cow[2505];
struct Screen {
    int spf, cover;
};

list<Screen> lst;

int main() {
    int c, l;
    scanf("%d%d", &c, &l);
    for (int i = 1; i <= c; ++i)
        scanf("%d%d", &cow[i].minspf, &cow[i].maxspf);
    for (int i = 1; i <= l; ++i) {
        Screen scr;
        scanf("%d%d", &scr.spf, &scr.cover);
        if (scr.cover)
            lst.push_back(Screen{scr.spf, scr.cover});
    }
    sort(cow + 1, cow + c + 1);
    int ans = 0;
    for (int i = 1; i <= c && !lst.empty(); ++i) {
        list<Screen>::iterator choice = lst.end();
        for (list<Screen>::iterator it = lst.begin(); it != lst.end(); ++it) {
            if (it->spf >= cow[i].minspf && it->spf <= cow[i].maxspf && (choice == lst.end() || it->spf > choice->spf)) {
                choice = it;
            }
        }
        if (choice != lst.end()) {
            ++ans;
            if (--choice->cover == 0)
                lst.erase(choice);
        }
    }
    printf("%d\n", ans);
    return 0;
}
