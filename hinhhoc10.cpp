#include <bits/stdc++.h>
using namespace std;

struct H {
    int x1, y1, x2, y2;
};

bool cmp(H a, H b) {
    if (a.x1 != b.x1) return a.x1 > b.x1;
    if (a.x2 != b.x2) return a.x2 < b.x2;
    if (a.y1 != b.y1) return a.y1 > b.y1;
    return a.y2 < b.y2;
}

H a[10005];
int f[10005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("hcnbn.inp", "r", stdin);
    freopen("hcnbn.out", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }

    sort(a + 1, a + n + 1, cmp);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j].x1 >= a[i].x1 && a[j].x2 <= a[i].x2 &&
                a[j].y1 >= a[i].y1 && a[j].y2 <= a[i].y2) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }

    cout << ans;

    return 0;
}
