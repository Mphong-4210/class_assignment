#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Cacdt.inp", "r", stdin);
    freopen("Cacdt.out", "w", stdout);

    int n;
    cin  >> n;
    map<pair<long long, long long>, long long> direction_count;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        long long g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        if (dx < 0 || (dx == 0 && dy < 0)) {
            dx = -dx;
            dy = -dy;
        }

        direction_count[{dx, dy}]++;
    }
    long long total_pairs = (long long)n * (n - 1) / 2;
    long long parallel_pairs = 0;

    for (auto entry : direction_count) {
        long long c = entry.second;
        parallel_pairs += c * (c - 1) / 2;
    }

    cout << total_pairs - parallel_pairs << "\n";

    return 0;
}
