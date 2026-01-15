#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
#define pii pair<int,int>
#define sort(a) sort(a.begin()+1,a.end())
#define endl '\n'
const int N = 1e6+5;

void fff(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int dx = 0,dy = 0;
    int ans = 0;
    for(auto c : s){
        if(c == 'U'){
            dy++;
        }else if(c == 'D'){
            dy--;
        }else if(c == 'L'){
            dx--;
        }else if(c == 'R'){
            dx++;
        }
        ans = max(ans,abs(dx) + abs(dy));
    }
    dx = dx * (k-1),dy = dy * (k-1);
    ans = max(ans,abs(dx) + abs(dy));
    for(auto c : s){
        if(c == 'U'){
            dy++;
        }else if(c == 'D'){
            dy--;
        }else if(c == 'L'){
            dx--;
        }else if(c == 'R'){
            dx++;
        }
        ans = max(ans,abs(dx) + abs(dy));
    }    
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}