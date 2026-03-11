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
/*
    red : 1 4
    black: 2 3 5 6
    sum red : a
    sum black : b
*/
void solve(){
    int a,b; cin >> a >> b;
    vector<int> bl({2,3,6,5}),re({1,4});
    map<pii,int> mp;
    for(int i = 0; i <= 3; i++){ // 红色骰子个数
        if(i == 0){
            for(auto x1: bl){
                for(auto x2: bl){
                    for(auto x3: bl){
                        mp[{0,x1+x2+x3}]++;
                    }
                }
            }
        }else if(i == 1){
            for(auto x1: bl){
                for(auto x2: bl){
                    mp[{1,x1+x2}]++;
                    mp[{4,x1+x2}]++;
                }
            }
        }else if(i == 2){
            for(int x1: re){
                for(int x2: re){
                    for(int j: bl){
                        mp[{x1+x2,j}]++;
                    }
                }
            }
        }else if(i == 3){
            for(int x1: re){
                for(int x2: re){
                    for(int x3: re){
                        mp[{x1+x2+x3,0}]++;
                    }
                }
            }
        }
    }
    if(mp.count({a,b})){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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