#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define fi first
#define se second
#define pii pair<int,int>
#define sort(a) sort(a.begin()+1,a.end())
const int N = 1e6+5;

void fff(){
    int y1, m1, d1; 
    cin >> y1 >> m1 >> d1;
    string s; cin >> s;
    int y2, m2, d2; 
    cin >> y2 >> m2 >> d2;
    int sum1 = y1 * 12 * 30 + m1 * 30 + d1;
    int sum2 = y2 * 12 * 30 + m2 * 30 + d2;
    map<string,int> mp;
    mp["Monday"] = 0;
    mp["Tuesday"] = 1;
    mp["Wednesday"] = 2;
    mp["Thursday"] = 3;
    mp["Friday"] = 4;
    int id = 0;
    for(auto [str,x] : mp){
        if(str == s){
            id = x;
            break;
        }
    }
    id = ((id + sum2 - sum1) % 5 + 5) % 5;
    for(auto [str,x] : mp){
        if(x == id){
            cout << str << endl;
            break;
        }
    }
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