#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

long long n,m,t,out[200050],ans;

int main(){
    long long i,j,u,v;
    cin>>n>>m;
    ans=n;
    while(m--){
        cin>>u>>v;
        if(u>v) swap(u,v);
        if(out[u]==0) ans--;
        out[u]++;
    }
    cin>>t;
    while(t--){
        cin>>j;
        if(j==1){
            cin>>u>>v;
            if(u>v) swap(u,v);
            if(out[u]==0) ans--;
            out[u]++;
        }
        if(j==2){
            cin>>u>>v;
            if(u>v) swap(u,v);
            out[u]--;
            if(out[u]==0) ans++;
        }
        if(j==3){
            cout<<ans<<endl;
        }
    }
    return 0;
}