#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const int INF = 0x3F3F3F3F;
const LL INFLL = 0x3F3F3F3F3F3F3F3FLL;

#ifdef _LOCAL
#include "locals.h"
#else
#define show(...)
#endif

const ULL MAX = 1ULL << 32;

int main() {
    int l, n;
    string op;
    stack<int> st;
    stack<ULL> times;
    bool flow = false;
    cin >> l;
    st.push(1);
    times.push(0);
    while (l--) {
        cin >> op;
        if (op == "add") {
            ++times.top();
            if (times.top() >= MAX) {
                flow = true;
                break;
            }
        } else if (op == "end") {
            ULL t = times.top();
            times.pop();
            ULL nn = st.top();
            st.pop();
            if (t >= MAX / nn) {
                show(t * nn);
                flow = true;
                break;
            }
            times.top() += t * nn;
            if (times.top() >= MAX) {
                flow = true;
                break;
            }
        } else {
            cin >> n;
            st.push(n);
            times.push(0);
        }
    }
    if (flow) {
        cout << "OVERFLOW!!!";
    } else {
        cout << times.top();
    }
    return 0;
}