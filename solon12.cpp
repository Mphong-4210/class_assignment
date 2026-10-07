#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,s="";
    cin>>a>>b;
    int i=a.size()-1,j=b.size()-1,nho=0;
    while(i>=0||j>=0||nho>0){
        int x=nho;
        if(i>=0)
            x+=a[i--]-'0';
        if(j>=0)
            x+=b[j--]-'0';
        s+=char(x%8+'0');
        nho=x/8;
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
