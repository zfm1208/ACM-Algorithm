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

void solve(){
    int op;
    char c;
    string s;
    map<int,int> mp;
    int sum = 0;
    int cnt = 0;
    while(1){
        cin >> op >> c >> s;
        if(op == 0){
            break;
        }
        int time = 0;
        int fen = 0;
        for(int i = 0; i < 5; i++){
            if(s[i] == ':'){
                time *= 60;
            }else{
                int num = s[i] - '0';
                if(i > 2){
                    fen = fen * 10 + num;
                }else{
                    time = time * 10 + num; 
                }
            }
        }
        time += fen;
        if(c == 'S'){
            mp[op] = time;
        }
        else if(c == 'E'){
            if(mp.find(op) == mp.end()){
                continue;
            }
            cnt++;
            sum += time - mp[op];
            mp.erase(op);
        }
    }
    if(cnt != 0) {
        sum = (int)(1.0 * sum / cnt + 0.5);
    }
    cout << cnt << " " << sum << endl;
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