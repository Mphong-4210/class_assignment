#include <bits/stdc++.h>
using namespace std;
#define dk ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define el '\n'
void solve() {
    freopen("TIMXAU.INP", "r", stdin);
    freopen("TIMXAU.OUT", "w", stdout);
    int k;
    string x;
    if(!(cin>>k>>x)) return;
    int n=x.length();
    set<string> s;
    string t=x;
    for (int i=0;i<n;i++){
        s.insert(t);
        t = t.substr(1)+t[0];
    }
    if(k<1||k>(int)s.size()){
        cout<<-1<<el;
        return;
    }
    auto it=s.begin();
    for(int i=1;i<k;i++){
        it++;
    }
    cout<<*it<<el;
}
signed main(){
    dk;
    solve();
    return 0;
}
