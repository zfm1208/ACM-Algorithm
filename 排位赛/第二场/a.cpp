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
    string s; 
    cin >> y1 >> m1 >> d1 >> s;
    int y2, m2, d2; 
    cin >> y2 >> m2 >> d2;
    string ans[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int sum1 = (y1 - 1) * 360 + (m1 - 1) * 30 + (d1 - 1);
    int sum2 = (y2 - 1) * 360 + (m2 - 1) * 30 + (d2 - 1);
    auto get_id = [&](string s) -> int {
        if(s == "Monday") return 0;
        if(s == "Tuesday") return 1;
        if(s == "Wednesday") return 2;
        if(s == "Thursday") return 3;
        if(s == "Friday") return 4;
    };
    int id = ((get_id(s) + sum2 - sum1) % 5 + 5) % 5;
    cout << ans[id] << "\n";
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