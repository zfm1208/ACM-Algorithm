#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 1e5+6,mod = 998244353,inf = 1e18+1;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q=(1<<24)+1;
char in[Q],*is=in,*it=in,c;
void read(long long &n){
  for(n=0;(c=gc())<'0'||c>'9';);
  for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}
void zfm(){
    int n,m; 
    read(n);read(m);
    vector<int> a(m+1);
    for(int i = 1; i <= m; i++){
        read(a[i]);
    }
    vector<int> d(m+1);
    for(int i = 2; i <= m; i++){
        d[i] = a[i] - a[i-1];
    }
    d[1] = a[1] - 0 + n - a[m];
    int sum = inf;
    vector<int> ans(m+1);
    for(int i = 2; i <= m; i++){
        ans[i] = ceil((d[i] + d[i-1]) / 2.0);
    }
    ans[1] = ceil((d[m] + d[1]) / 2.0);
    for(int i = 1; i <= m; i++){
        sum = min(sum,ans[i]);
    }
    printf("%lld",sum+1);
}

signed main(){
    ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}