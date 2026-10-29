#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x[2500], y[2500];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cchunhat.inp", "r", stdin);
    freopen("cchunhat.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    map<pair<pair<ll, ll>, ll>, ll> mp;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll mx = x[i] + x[j];
            ll my = y[i] + y[j];
            ll d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            mp[{{mx, my}, d}]++;
        }
    }

    ll ans = 0;
    for (auto it : mp) {
        ll c = it.second;
        ans += c * (c - 1) / 2;
    }

    cout << ans;

    return 0;
}
