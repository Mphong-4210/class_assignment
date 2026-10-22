#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("Tamgiacv.inp", "r", stdin);
    freopen("Tamgiacv.out", "w", stdout);

    long long x1, y1, x2, y2, x3, y3;
    if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) return 0;

    long long dx1 = x1 - x2;
    long long dy1 = y1 - y2;
    long long dx2 = x3 - x2;
    long long dy2 = y3 - y2;

    long long dot_product = dx1 * dx2 + dy1 * dy2;

    if (dot_product == 0) {
        long long x4 = x1 + x3 - x2;
        long long y4 = y1 + y3 - y2;
        cout << x4 << " " << y4 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
