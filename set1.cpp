#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n, ans = 0;
    cin >> m;

    unordered_set<int> s;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (s.count(x)) ans++;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("DEMPT.INP", "r", stdin);
    freopen("DEMPT.OUT", "w", stdout);

    solve();
    return 0;
}
