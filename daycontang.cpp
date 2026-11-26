#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

int n;
int a[MAXN];
int dp[MAXN];
int trace[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        trace[i] = 0;

        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[j] + 1 > dp[i] ||
                   (dp[j] + 1 == dp[i] && j > trace[i])) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
    }

    int maxLen = 0, pos = 0;

    for (int i = 1; i <= n; i++) {
        if (dp[i] > maxLen || (dp[i] == maxLen && i > pos)) {
            maxLen = dp[i];
            pos = i;
        }
    }

    vector<int> res;

    while (pos != 0) {
        res.push_back(a[pos]);
        pos = trace[pos];
    }

    reverse(res.begin(), res.end());

    cout << maxLen << "\n";
    for (int x : res) cout << x*2 << " ";
}
