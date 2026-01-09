//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
//#define int long long
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const long double pi = acos(-1);
const int mod1 = 1e9 + 7,mod2 = 998244853,inf = 0x3f3f3f3f;
const int N = 8e5 + 5;
ull base = 131;
ull P[N];
ull haxi[N]; // haxi[i] ：s[1..i]的哈希值
void init(){
    P[0] = 1;
    for(int i = 1; i <= N; i++){
        P[i] = P[i-1] * base;
    }
}
ull getha(int l,int r){//返回字串s[l..r]的哈希值
    return haxi[r] - haxi[l-1] * P[r-l+1];
}
void solve() {
    init();
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    // 前缀哈希
    for(int i = 1; i <= len; i++){
        haxi[i] = haxi[i -1] * base + s[i];
    }
    for(int L = 1; L <= len/2; L++){
        int la = len % L;
        int cnt = (len - la) / L;
        if(cnt < 2) continue;

        ull A_hash = getha(1,L);
        int pos = -1; // 找到B的块的起始位置
        for(int i = 2; i <= cnt; i++){
            ull now_hash = getha((i-1) * L + 1, i * L);
            if(now_hash != A_hash){
                pos = i;
                break;
            }
        }
        if(pos == -1) continue;

        ull B_hash = getha((pos - 1) * L + 1,  pos *  L);
        if(B_hash == A_hash) continue;
        // 判断是否有非A串非B串的块
        bool ok = true;
        for(int i = 1; i <= cnt; i++){
            ull now_hash = getha((i - 1) * L + 1, i * L);
            if(i < pos){
                if(now_hash != A_hash){
                    ok = false;
                    break;
                }
            }else if(i > pos){
                if(now_hash != A_hash && now_hash != B_hash){
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        // 判断a是否为A的子串
        ok = true;
        for(int i = 0; i < la; i++){
            if(s[len - la + 1 + i] != s[1 + i]){
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        // 检查B的后面是否全是A(不考虑a)
        int st = pos;// B的起始位置
        int en = pos;// B的结束位置
        ok = true;
        while(en <= cnt && getha((en - 1) * L + 1, en * L) == B_hash){
            en++;
        }
        if(en == st) continue; // 找不到B串
         //判断最后一个B串后面是否全为为A串
        for(int i = en; i <= cnt; i++){
            if(getha((i - 1) * L + 1, i * L) != A_hash) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        string A = s.substr(1, L);
        string B = s.substr((st - 1) * L + 1,L);
        cout << A << " " << B << endl;
        return;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
//    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}