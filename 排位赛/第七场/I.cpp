#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
/*
    线段i的端点是(2,4) , (3,4)
    纵坐标相同
*/
void solve(){
    int a1,b1,y1; 
    while(cin >> a1 >> b1 >> y1){
        vector<array<int,3>> a(4);
        a[1] = {a1,b1,y1};
        int a2,b2,y2;
        cin >> a2 >> b2 >> y2;
        a[2] = {a2,b2,y2};
        int a3,b3,y3;
        cin >> a3 >> b3 >> y3;
        a[3] = {a3,b3,y3};
        // 判断是否存在横线
        if(a[1][2] == a[2][2] && a[1][2] == a[3][2]){
            cout << "Yes" << endl;
            continue;
        }
        sort(a.begin()+1,a.end(),[](auto x, auto y){
            return x[2] < y[2];
        });
        if(a[1][2] == a[2][2]){
            if(max(a[1][0],a[2][0]) <= min(a[1][1],a[2][1])){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            ld k = (ld)(a[3][2] - a[2][2]) / (a[2][2] - a[1][2]);
            ld st = a[2][0] + (a[2][0] - a[1][1]) * k;
            ld ed = a[2][1] + (a[2][1] - a[1][0]) * k;
            if(max(st,(ld)a[3][0]) <= min(ed,(ld)a[3][1])){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1; 
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}