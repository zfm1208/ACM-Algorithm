#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 5e6+9, mod = 1e9+7, inf = 1e18 + 5;
void solve(){
int x;
   cin>>x;
   int jga;
   int jgb;
   int jgc;
   int ma=inf;
   int xx=sqrt(x);
   for(int i=max(1ll,xx-100);i<=min(x,xx+100);i++)
   {
    int j=x/i;
    int k=i*j;
    for(int z=-10;z<=10;z++)
    {
        int jj=j+z;
        if(jj>=0&&jj*i<=x)
        {
            int zz=x-jj*i;
            int ma1=max({i,jj,zz});
            int mi1=min({i,jj,zz});
            ma=min(ma,ma1-mi1);
        }
    }
   }
//    cout<<jga<<' '<<jgb<<' '<<jgc<<'\n';
//    cout<<sqrt(x)<<'\n';
cout<<ma<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}