//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 2e5 + 5;

void solve() {
    int mp[110][110];
    int n; cin >> n;
    char ch;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> ch;
            mp[i][j] = ch - '0';
        }
    }
    int ans = 0;
    // p(x,y) p1(y,n-x+1) p2(n-x+1,n-y+1) p3(n-y+1,x)
    if(n&1){
        for(int x = 1; x <= n/2; x++){
            for(int y = 1; y <= n/2 + 1; y++){
                pii p1 = {y,n-x+1};
                pii p2 = {n-x+1,n-y+1};
                pii p3 = {n-y+1,x};
                int sum = mp[x][y] + mp[p1.fi][p1.se] + mp[p2.fi][p2.se] + mp[p3.fi][p3.se];
                if(sum==0||sum==4)ans+=0; // 四个拓展点都相同 不用反转 ，对答案没有贡献
                if(sum==1||sum==3)ans+=1; // 四个拓展点仅仅有一个与另外三个不同 需要反转，贡献+1
                if(sum==2)ans+=2; // 四个拓展点有两个与另外两个不同 需要反转，贡献+2
            }
        }
    }else{
        for(int x = 1; x <= n/2; x++){
            for(int y = 1; y <= n/2; y++){
                pii p1 = {y,n-x+1};
                pii p2 = {n-x+1,n-y+1};
                pii p3 = {n-y+1,x};
                int sum = mp[x][y] + mp[p1.fi][p1.se] + mp[p2.fi][p2.se] + mp[p3.fi][p3.se];
                if(sum==0||sum==4)ans+=0;
                if(sum==1||sum==3)ans+=1;
                if(sum==2)ans+=2;
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
