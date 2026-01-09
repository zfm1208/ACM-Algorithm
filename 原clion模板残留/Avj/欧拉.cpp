#include<bits/stdc++.h>
#define int long long
using namespace std;
int prime[100000005];
bool a[100000005];
int cnt;
void oulare(int x){
    a[0] = a[1] = 1;
    for(int i = 2; i <= x; i++){
        if(!a[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt; j++){
            if(i * prime[j] > x) break;
            a[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve()
{
    int n,m;cin >> n >> m;
    oulare(n);
    while(m--){
        int x; cin >> x;
        cout << prime[x] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}