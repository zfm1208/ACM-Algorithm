#include<bits/stdc++.h>
using namespace  std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
void solve(){
    int n,m,k;cin >> n >> m >> k;
    if(k <= n-1){
        cout << k << endl;
        return;
    }
    int t =(k-(n-1));
    if(t%n==0){
        int s1;
        if(t/n%2==1)s1=1;
        else s1=n;
        cout << s1+t/n-1 << endl;
    }
    else{
        int s1;
        if(t/n%2==0)s1=n-t%n+1;
        else s1=t%n;
        cout << s1+t/n << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}