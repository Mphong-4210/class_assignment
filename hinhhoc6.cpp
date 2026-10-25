#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cacdtvg.inp", "r", stdin);
    freopen("cacdtvg.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    map<pair<ll, ll>, ll> mp;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll dx = x2 - x1;
        ll dy = y2 - y1;
        ll g = gcd(dx, dy);
        dx /= g;
        dy /= g;

        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }
        mp[{dx, dy}]++;
    }

    ll ans = 0;
    for (auto it : mp) {
        ll dx = it.first.first;
        ll dy = it.first.second;
        ll c = it.second;

        ll px = -dy;
        ll py = dx;
        if (px < 0 || (px == 0 && py < 0)) {
            px = -px;
            py = -py;
        }

        if (mp.count({px, py})) {
            ans += c * mp[{px, py}];
        }
    }

    cout << ans / 2;

    return 0;
}
