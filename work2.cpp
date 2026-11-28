#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ld = long double;


#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define int ll


void fre(const char *name)
{
    string s = name;
    if (ifstream(s + ".INP").good())
    {
        freopen((s + ".INP").c_str(), "r", stdin);
        freopen((s + ".OUT").c_str(), "w", stdout);
    }
}


const int N = 1e5 + 5;


int n, m, cur;
int tin[N], low[N];
bool cut[N];
vector<int> g[N];


void dfs(int u, int p)
{
    tin[u] = low[u] = ++cur;
    int con = 0;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        if (tin[v])
        {
            low[u] = min(low[u], tin[v]);
        }
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (p != 0 && low[v] >= tin[u])
                cut[u] = true;
            con++;
        }
    }
    if (p == 0 && con >= 2)
        cut[u] = true;
}


signed main()
{
    fast;
    fre("input");


    cin >> n >> m;
    FOR(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    dfs(1, 0);


    int k = 0;
    FOR(i, 1, n)
    if (cut[i])
        k++;
    cout << k << "\n";
    FOR(i, 1, n)
    if (cut[i])
        cout << i << " ";


    return 0;
}
