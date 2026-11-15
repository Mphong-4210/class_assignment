#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef float fl;
typedef long double ldb;
typedef unsigned long long ull;
typedef string str;
#define vll vector<ll>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define dq deque<ll>
#define ret return
#define si size()
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bend(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORN(i,a,b) for(int i=(a); i>=(b); i--)
// Phong

const ll INF = 4e18, NINF = -4e18;
const int MAXN=1e6+42, MAXM=1e3, MOD=1000000007;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, m;
ll ax[15], ay[15];

void manhphong(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void ffopen(string name){
    string infile = name + ".inp";
    string outfile = name + ".out";
    if(FILE* f = fopen(infile.c_str(), "r")){
        fclose(f);
        freopen(infile.c_str(), "r", stdin);
        freopen(outfile.c_str(), "w", stdout);
    }
}

void solve(){
    if (!(cin >> n >> m)) ret;
    FOR(i, 0, n - 1) cin >> ax[i] >> ay[i];

    int ans = 0;
    FOR(k, 0, m - 1){
        ll x, y; 
        cin >> x >> y;
        bool dung = false, sai = false;
        FOR(i, 0, n - 1){
            int j = (i + 1) % n;
            ll c = (ax[j] - ax[i]) * (y - ay[i]) - (ay[j] - ay[i]) * (x - ax[i]);
            if (c > 0) dung = true;
            if (c < 0) sai = true;
        }

        if (!(dung && sai)) ans++;
    }
    cout << ans << el;
}

signed main(){
    ffopen("DGDIEM");

    manhphong();

    solve();
    
    ret 0;
}

/*
    ____  _                         
   / __ \| |__   ___  _ __   __ _ 
  / /_/ | '_ \ / _ \| '_ \ / _` |
  \___  | | | | (_) | | | | (_| |
  (_)   |_| |_|\___/|_| |_|\__, |
                           |___/                         
*/
