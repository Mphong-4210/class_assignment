#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DOANXE.INP", "r", stdin);
    freopen("DOANXE.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long P, L;

    cin >> n >> P >> L;

    vector<long long> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    const double INF = 1e100;
    vector<double> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        long long sumW = 0;
        long long minV = 1e18;

        for (int j = i; j >= 1; j--) {
            sumW += w[j];
            if (sumW > P) break;

            minV = min(minV, v[j]);
            dp[i] = min(dp[i], dp[j - 1] + (double)L / minV);
        }
    }

    cout << fixed << setprecision(2) << dp[n]-1;

    return 0;
}
