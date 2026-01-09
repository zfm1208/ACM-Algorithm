//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii ar<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 1e6 + 5;
string ssy[] = {"1z", "2z", "3z", "4z", "5z", "6z", "7z", "1p", "9p", "1s", "9s", "1m", "9m"};

void solve() {
    // 几筒 P 几条 S 几万 M
    // 东南西北风 白板 发财 红中 Z
    // 端牌 七对子irteen orphan :{1p,9p,1s,9s,1m,9m}
    string s;cin >> s;
    vector<string> a;
    for(int i = 0; i < s.size(); i += 2){
        a.push_back(s.substr(i, 2));
    }
    map<string, int> mp;
    for(auto it : a) mp[it] ++;
    //七对
    if(mp.size() == 7){
        int cnt = 0;
        for(auto[x, y] : mp)
            if(y == 2)cnt++;
        if(cnt == 7){
            cout << "7 Pairs" << endl;
            return;
        }
    }
    //十三幺
    if(mp.size() == 13){
        vector<int> b(13);
        for(auto [x, y] : mp)
        {
            bool ok = 0;
            for(int i = 0; i < 13; i ++){
                if(x == ssy[i]){
                    ok = 1;
                    b[i] = 1;
                    break;
                }
            }
            if(!ok){
                cout << "Otherwise" << endl;
                return;
            }
        }
        int sum = 0;
        for(auto x : b) sum += x;
        if(sum == 13) cout << "Thirteen Orphans" << endl;
        else cout << "Otherwise" << endl;
        return;
    }
    else cout << "Otherwise" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
//1
//1s9s1p9p1m9m1z2z3z4z5z6z7z9s