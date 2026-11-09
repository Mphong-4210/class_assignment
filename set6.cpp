#include<bits/stdc++.h>
using namespace std;

void ffopen(string file){
    if(fopen((file+".inp").c_str(),"r")){
        freopen((file+".inp").c_str(),"r",stdin);
        freopen((file+".out").c_str(),"w",stdout);
    }
}

void solve(){
    int N,M;
    cin>>N>>M;
    vector<int> ds(M);
    for(int i=0;i<M;i++) cin>>ds[i];
    sort(ds.begin(),ds.end());

    string P=to_string(N);
    int L=(int)P.size();
    int DIFF=L+1;
    int PS=L+2;

    int S=N*PS;
    vector<int> par(S,-2);
    vector<char> dg(S,0);

    queue<int> q;
    int ans=-1;

    for(int di=0;di<M && ans<0;di++){
        int d=ds[di];
        if(d==0) continue;
        int r=d%N;
        int ps;
        if(d==P[0]-'0') ps=1;
        else ps=DIFF;
        int st=r*PS+ps;
        if(par[st]==-2){
            par[st]=-1;
            dg[st]=char('0'+d);
            q.push(st);
            if(r==0 && ps==DIFF) ans=st;
        }
    }

    while(!q.empty() && ans<0){
        int st=q.front(); q.pop();
        int r=st/PS, ps=st%PS;
        for(int di=0;di<M;di++){
            int d=ds[di];
            int nr=(r*10+d)%N;
            int nps;
            if(ps==DIFF) nps=DIFF;
            else if(ps==L) nps=DIFF;
            else if(d==P[ps]-'0') nps=ps+1;
            else nps=DIFF;
            int nst=nr*PS+nps;
            if(par[nst]==-2){
                par[nst]=st;
                dg[nst]=char('0'+d);
                q.push(nst);
                if(nr==0 && nps==DIFF){ ans=nst; break; }
            }
        }
    }

    if(ans<0){
        cout<<0;
        return;
    }

    string res;
    int cur=ans;
    while(cur!=-1){
        res.push_back(dg[cur]);
        cur=par[cur];
    }
    reverse(res.begin(),res.end());
    cout<<res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ffopen("BOI");
    solve();
    return 0;
}
