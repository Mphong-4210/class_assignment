#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Point {
    ll x, y;
};

ll cross(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y)
         - (B.y - A.y) * (C.x - A.x);
}

void solve() {
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    ll u = cross(C, D, A);
    ll v = cross(C, D, B);

    if (u == 0 && v == 0) {
        cout << 3;
        return;
    }

    if (u == 0 || v == 0 || (u < 0 && v > 0) || (u > 0 && v < 0)) {
        cout << 1;
        return;
    }

    if ((B.x - A.x) * (D.y - C.y) == (B.y - A.y) * (D.x - C.x)) {
        cout << 2;
        return;
    }

    cout << 4;
}

int main() {
    freopen("DTDT.INP", "r", stdin);
    freopen("DTDT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
