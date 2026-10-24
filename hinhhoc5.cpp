#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll d(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Tugiacloi.inp", "r", stdin);
    freopen("Tugiacloi.out", "w", stdout);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)) return 0;

    if (x1 + x3 == x2 + x4 && y1 + y3 == y2 + y4) {
        bool ke = (d(x1, y1, x2, y2) == d(x2, y2, x3, y3));
        bool ch = (d(x1, y1, x3, y3) == d(x2, y2, x4, y4));

        if (ke && ch) cout << 4;      // Vuong
        else if (ch) cout << 3;       // CN
        else if (ke) cout << 2;       // Thoi
        else cout << 1;               // HBH
    } else {
        cout << 5;                    // Thuong
    }

    return 0;
}
