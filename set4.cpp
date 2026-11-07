#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("TONGBANGKHONG.INP","r",stdin);
    freopen("TONGBANGKHONG.OUT","w",stdout);
    int n;
    cin>>n;
    set<long long> s;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        s.insert(x);
    }
    int dem=0;
    for(long long x:s){
        if(x<0&&s.count(-x)){
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
