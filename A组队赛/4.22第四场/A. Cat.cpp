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
// https://qoj.ac/contest/1834/problem/9701

/*
    从0开始,每四个连续的数字异或和为0
    0^1^2^3 = 0   4^5^6^7 = 0
    所以1^2^...^ x 的前缀和只用看x%4的余数(随后剩下几个数没有被抵消)
    1. x%4=0  pre[x] = x
    2. x%4=1  pre[x] = 1
    3. x%4=2  pre[x] = x+1
    4. x%4=3  pre[x] = 0
*/
int find_pre(int x){
    if(x < 0) return 0;
    int rem = x % 4;
    if (rem == 0) return x;
    if (rem == 1) return 1;
    if (rem == 2) return x + 1;
    if (rem == 3) return 0; 
}
int query(int l, int r) {
    if(l > r) return 0;
    return find_pre(r) ^ find_pre(l-1);
}
void solve(){
    int l,r,s; 
    cin >> l >> r >> s;
    // 寻找第一种异或为 0 的中间区间: [ %4==2, %4==1 ]
    int l1 = 0,r1 = 0;
    for(int i = l; i <= r; i++) if(i % 4 == 2) {
        l1 = i; 
        break;
    }
    for(int i = r; i >= l; i--) if(i % 4 == 1){
        r1 = i;
        break;
    }

    // 寻找第二种异或为 0 的中间区间: [ %4==0, %4==3 ]
    int l2 = 0,r2 = 0;
    for(int i = l; i <= r; i++) if(i % 4 == 0) {
        l2 = i; 
        break;
    }
    for(int i = r; i >= l; i--) if(i % 4 == 3){
        r2 = i;
        break;
    } 
       
    int ans = -1;
    // [l1,r1]
    if(l1 != 0 && r1 != 0 && l1 < r1){
        for(int i = l; i <= l1; i++){
            for(int j = r1; j <= r; j++){
                int val = query(i,l1-1) ^ query(r1+1,j);
                if(val <= s) ans = max(ans, j - i + 1);
            }
        }
    }

    // [l2,r2]
    if(l2 != 0 && r2 != 0 && l2 < r2){
        for(int i = l; i <= l2; i++){
            for(int j = r2; j <= r; j++){
                int val = query(i,l2-1) ^ query(r2+1,j);
                if(val <= s) ans = max(ans, j - i + 1);
            }
        }
    }
    // 不存在[l1,r1]
    for(int i = l; i <= min(r, l + 10); i++){
        for(int j = i; j <= min(r, i + 10); j++){
            int val = query(i,j);
            if(val <= s) ans = max(ans, j - i + 1);            
        }
    }
    // 不存在[l2,r2]
    for(int i = max(l, r - 10); i <= r; i++){
        for(int j = i; j <= r; j++){
            int val = query(i,j);
            if(val <= s) ans = max(ans, j - i + 1);            
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