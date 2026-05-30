#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define vii vector<int>
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
// I 空
// E 有人
// A 任意
void solve(){
    int n,x,s; cin >> n >> x >> s;
    string S; cin >> S; S = " " + S; 
    int ans = 0;
    int cntzz = 0 ;
    int cntzw = 0;
    int cnta  = 0; // 记录A变成E的个数
    for(int i = 1; i <= n; i++){
        if(S[i] == 'I'){ // 必须要空桌子
            cntzz++;
            if(cntzz <= x){
                ans++;
                cntzw++;
            }else{
                cntzz--;
            }
        }else if(S[i] == 'A'){ // 任意，先填充空位置，满了就单开新桌子
            if(cntzw < cntzz * s){ // 坐位没满
                cntzw++;
                ans++;
                cnta++; 
            }else{
                cntzz++;
                if(cntzz <= x){ // 满了
                    ans++;
                    cntzw++;
                }else{
                    cntzz--;
                }
            }
        }else{ // 只能坐有人的座位
            if(cntzw < cntzz * s){ // 座位没满
                cntzw++;
                ans++;
            }else{
                if(cnta > 0 && cntzz < x){// 座位满了，看看
                    cnta--;
                    cntzz++;
                    cntzw++;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
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