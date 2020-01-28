// 2019-02-11
#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int n, p;
stack<int> st;
vector<int> v;

void solve(int now) {
    if (p >= 20) return;
    if (v.size() == n) {
        ++p;
        for (auto x : v) cout << x;
        cout << '\n';
        return;
    }
    if (st.empty() && now <= n) {
        st.push(now);
        solve(now + 1);
        st.pop();
        return;
    }
    // out
    int x = st.top();
    st.pop();
    v.push_back(x);
    solve(now);
    v.pop_back(), st.push(x);

    // in
    if (now <= n) {
        st.push(now);
        solve(now + 1);
        st.pop();
    }
}

int main() {
    cin >> n;
    solve(1);
    return 0;
}
