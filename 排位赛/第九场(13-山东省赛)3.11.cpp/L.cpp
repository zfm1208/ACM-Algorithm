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
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// r,c,h,w;
// h:竖高  上- 下+
// w:横宽  左- 右+
void solve(){
    int n,sx,sy;
    cin >> n >> sx >> sy;
    vector<array<int,4>> ans;
    cout << "Yes" << endl;
    int top = 1, down = n;
    int L = 1, R = n;
    int x = 1; // 行
    int y = 1; // 列
    int op = -1;
    while(1)
    {
        if(L == R && top == down) break;
        if(sx != x && sy != y){
            ans.pb({x,y,(down - x), (R - y)});
            x++;
            y++;
            L++;
            top++;
        }else{
            if(sx == x && sy == y){
                op = 1;
            }else if(sx == x){
                op = 2;
            }else if(sy == y){
                op = 3;
            }
            break;
        }
    }
    if(op == -1){
        cout << ans.size() << endl;
        for(auto [a1,a2,a3,a4] : ans){
            cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        }
        return;
    }
    if(op == 1){
        x++;
        y++;
        while(x <= n && y <= n){
            ans.pb({x,y,-(x-top),-(y-L)});
            x++;
            y++;
        }
        cout << ans.size() << endl;
        for(auto [a1,a2,a3,a4] : ans){
            cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        }
        return;
    }
    if(op == 2)
    {
        int ex = n, ey = n;
        int opp = -1;
        while(1)
        {
            if(ex != sx && ey != sy){
                ans.pb({ex,ey,-(ex - top),-(ey - L)});
                ex--;
                ey--;
                R--;
                down--;
            }else{
                break;                
            }
        }
        int xx = down;
        int yy = L;
        while(xx != sx && yy != sy){
            ans.pb({xx,yy,(top-xx),(R-yy)});
            xx--;
            yy++;
        }
        cout << ans.size() << endl;
        for(auto [a1,a2,a3,a4] : ans){
            cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        }
        return;
    }
    if(op == 3)
    {
        int ex = n, ey = n;
        int opp = -1;
        while(1)
        {
            if(ex != sx && ey != sy){
                ans.pb({ex,ey,-(ex - top),-(ey - L)});
                ex--;
                ey--;
                R--;
                down--;
            }else{
                break;                
            }
        }
        int xx = top;
        int yy = R;
        while(xx != sx && yy != sy){
            ans.pb({xx,yy,(down-xx),(L-yy)});
            xx++;
            yy--;
        }
        cout << ans.size() << endl;
        for(auto [a1,a2,a3,a4] : ans){
            cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        }
        return;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}