#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Badiem.inp", "r", stdin);
    freopen("Badiem.out", "w", stdout);
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    const double EPS = 1e-9;
    double cp = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);

    if (abs(cp) < EPS) {
        if (cx >= min(ax, bx) - EPS && cx <= max(ax, bx) + EPS &&
            cy >= min(ay, by) - EPS && cy <= max(ay, by) + EPS) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    } else {
        double area = abs(cp) / 2.0;
        double ab = hypot(bx - ax, by - ay);
        double bc = hypot(cx - bx, cy - by);
        double ca = hypot(ax - cx, ay - cy);
        double perimeter = ab + bc + ca;

        cout << fixed << setprecision(3);
        cout << area << "\n";
        cout << perimeter << "\n";
    }

    return 0;
}
