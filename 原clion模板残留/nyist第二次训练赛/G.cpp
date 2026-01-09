#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
void solve()
{
    int x,y,z,v; cin >> x >> y >> z >> v;
    int ans = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(v % (i * j) == 0 && v/(i * j) <= z){
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - v/(i * j)+ 1) );
            }
        }
    }
    cout << ans << endl;
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}