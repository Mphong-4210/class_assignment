#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cp(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool onSeg(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    if (cp(x1, y1, x2, y2, x, y) != 0) return false;
    return x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Tugiacm.inp", "r", stdin);
    freopen("Tugiacm.out", "w", stdout);

    ll x1, y1, x2, y2, x3, y3, x4, y4, xm, ym;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> xm >> ym)) return 0;

    if ((xm == x1 && ym == y1) || (xm == x2 && ym == y2) || (xm == x3 && ym == y3) || (xm == x4 && ym == y4)) {
        cout << 4;
        return 0;
    }

    if (onSeg(x1, y1, x2, y2, xm, ym) || onSeg(x2, y2, x3, y3, xm, ym) || 
        onSeg(x3, y3, x4, y4, xm, ym) || onSeg(x4, y4, x1, y1, xm, ym)) {
        cout << 3;
        return 0;
    }

    ll c1 = cp(x1, y1, x2, y2, xm, ym);
    ll c2 = cp(x2, y2, x3, y3, xm, ym);
    ll c3 = cp(x3, y3, x4, y4, xm, ym);
    ll c4 = cp(x4, y4, x1, y1, xm, ym);

    if ((c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0) || (c1 < 0 && c2 < 0 && c3 < 0 && c4 < 0)) cout << 1;
    else cout << 2;

    return 0;
}
