#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10,mod = 1e9+7,inf = 1e18;
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)

void zfm(){
    int y1 = 0; cin >> y1;
    int n; cin >> n;
    vector<int> vis(N);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        vis[x] = 1;
    }
    int y2 = 0; cin >> y2;
    int cnt = 0;
    for(int i = y1; i <= y2; i++){
        if(vis[i] == 0) cnt++;
    }
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}