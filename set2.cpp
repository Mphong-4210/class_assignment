#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    set<string> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        string t = "";
        for (int j = i; j < n; j++) {
            t += s[j];
            st.insert(t);
        }
    }

    cout << st.size();
}

int main() {
    freopen("XAUCON.INP", "r", stdin);
    freopen("XAUCON.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
