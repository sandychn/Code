/*
 * @Author: Sandy 
 * @Date: 2019-08-09 01:16:03 
 * @Last Modified by: Sandy
 * @Last Modified time: 2019-08-22 00:53:16
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1005;

const string str[] = {"Apple", "iPhone", "iPod", "iPad"};

int main() {
    string s;
    while (cin >> s) {
        for (const string &now : str)
            if (s.find(now) != string::npos) cout << "MAI MAI MAI!\n";
        if (s.find("Sony") != string::npos) cout << "SONY DAFA IS GOOD!\n";
    }
    return 0;
}