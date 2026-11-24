#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
int dist[MAXN], trace[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
freopen("DDNN.INP", "r", stdin);
freopen("DDNN.OUT", "w", stdout);
    int n, m, u, v;
    cin >> n >> m >> u >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    memset(dist, -1, sizeof(dist));

    dist[u] = 0;
    q.push(u);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : adj[x]) {
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                trace[y] = x;
                q.push(y);
            }
        }
    }

    if (dist[v] == -1) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int x = v; x != u; x = trace[x]) {
        path.push_back(x);
    }

    cout << path.size();

    return 0;
}
