#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    s = '#' + s;
    int period = 0, group = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '.') {
            ++period;
            if (s[i - 1] != '.') ++group;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int pos;
        char ch;
        cin >> pos >> ch;
        if (isalpha(s[pos]) != isalpha(ch)) {
            if (s[pos] == '.') {
                --period;
            } else {
                ++period;
            }
            if (s[pos - 1] == '.' && s[pos + 1] == '.' && ch == '.') --group;
            if (s[pos - 1] == '.' && s[pos + 1] == '.' && ch != '.') ++group;
            if (s[pos - 1] != '.' && s[pos + 1] != '.' && ch == '.') ++group;
            if (s[pos - 1] != '.' && s[pos + 1] != '.' && ch != '.') --group;
        }
        s[pos] = ch;
        cout << period - group << endl;
    }
    return 0;
}