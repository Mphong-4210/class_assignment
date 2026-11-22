#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> b(m, vector<int>(n));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int d[] = {-1, 1, 0, 0};
    int e[] = {0, 0, -1, 1};
    int t = 0, q = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1 && b[i][j] == 0) {
                int s = 0, p = 0;
                stack<pair<int, int>> c;
                c.push({i, j});
                b[i][j] = 1;

                while (!c.empty()) {
                    int x = c.top().first;
                    int y = c.top().second;
                    c.pop();
                    ++s;

                    for (int k = 0; k < 4; ++k) {
                        int u = x + d[k];
                        int v = y + e[k];

                        if (u < 0 || u >= m || v < 0 || v >= n || a[u][v] == 0) {
                            ++p;
                        } else if (b[u][v] == 0) {
                            b[u][v] = 1;
                            c.push({u, v});
                        }
                    }
                }

                if (s > t) t = s;
                if (p > q) q = p;
            }
        }
    }

    cout << t << '\n' << q;
    return 0;
}
