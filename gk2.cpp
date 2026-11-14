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

struct Diem {
    ll x, y;
};

bool trung(Diem a, Diem b) {
    ret a.x == b.x && a.y == b.y;
}

ll tichCheo(Diem O, Diem A, Diem B) {
    ret (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool thuocDoan(Diem P, Diem A, Diem B) {
    ret tichCheo(A, B, P) == 0 && min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
}

bool khacDau(ll a, ll b) {
    ret (a > 0 && b < 0) || (a < 0 && b > 0);
}

bool doanCat(Diem A, Diem B, Diem C, Diem D) {
    if (khacDau(tichCheo(A, B, C), tichCheo(A, B, D)) && khacDau(tichCheo(C, D, A), tichCheo(C, D, B))) ret true;
    ret thuocDoan(C, A, B) || thuocDoan(D, A, B) || thuocDoan(A, C, D) || thuocDoan(B, C, D);
}

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
    Diem dinh[3], M, N;
    FOR(i, 0, 2) cin >> dinh[i].x >> dinh[i].y;
    cin >> M.x >> M.y >> N.x >> N.y;

    FOR(i, 0, 2) {
        Diem dau = dinh[i], cuoi = dinh[(i + 1) % 3];
        if (tichCheo(M, N, dau) != 0 || tichCheo(M, N, cuoi) != 0) continue;
        vector<Diem> diemChung;
        if (thuocDoan(dau, M, N)) diemChung.pb(dau);
        if (thuocDoan(cuoi, M, N)) diemChung.pb(cuoi);
        if (thuocDoan(M, dau, cuoi)) diemChung.pb(M);
        if (thuocDoan(N, dau, cuoi)) diemChung.pb(N);
        for (Diem p : diemChung) {
            if (!trung(p, diemChung[0])) {
                cout << 3 << el;
                ret;
            }
        }
    }
    
    int soGiao = 0;
    FOR(i, 0, 2) {
        if (doanCat(M, N, dinh[i], dinh[(i + 1) % 3])) soGiao++;
        if (thuocDoan(dinh[i], M, N)) soGiao--;
    }
    if (soGiao > 0) {
        cout << min(soGiao, 2) << el;
        ret;
    }
    
    ll c1 = tichCheo(dinh[0], dinh[1], M);
    ll c2 = tichCheo(dinh[1], dinh[2], M);
    ll c3 = tichCheo(dinh[2], dinh[0], M);
    
    if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) cout << 4 << el;
    else cout << 0 << el;
}

signed main(){
    ffopen("DTTG");

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
