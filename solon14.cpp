#include<bits/stdc++.h>
using namespace std;
string nhan(string a,int b){
    string s="";
    int nho=0;
    for(int i=a.size()-1;i>=0;i--){
        int x=(a[i]-'0')*b+nho;
        s+=char(x%10+'0');
        nho=x/10;
    }
    while(nho>0){
        s+=char(nho%10+'0');
        nho/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string chia(string a,int b){
    string s="";
    int du=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        int x=du*10+a[i]-'0';
        s+=char(x/b+'0');
        du=x%b;
    }
    while(s.size()>1&&s[0]=='0')
        s.erase(0,1);
    return s;
}
int main(){
    int n;
    cin>>n;
    string s="1";
    for(int i=1;i<=n;i++){
        s=nhan(s,n+i);
        s=chia(s,i);
    }
    s=chia(s,n+1);
    cout<<s;
}
