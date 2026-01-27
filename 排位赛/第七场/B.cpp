#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[100][100];
void solve(){
    int n,m;
    while(cin >> n >> m){
        memset(s,0,sizeof(s));
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= m;j++){
                cin >> s[i][j];
            }
        }
        // 检查有没有出现 1 
        auto check = [&] (int i, int j ,int len) -> bool {
            for(int w = j; w <= j+len; w++){
                if(s[i][w]!= 'o') {
                    return false;
                }
            }
            int ex = i, ey = j+len;
            if(i+1 <= n && s[i+1][j] == 'o'){
                return false;
            }
            if(i-1 >= 1 && s[i-1][j] == 'o'){
                return false;
            }
            if(j-1 >= 1 && s[i][j-1] == 'o'){
                return false;
            }
            if(i-1 >= 1 && j-1 >= 1 && s[i-1][j-1]== 'o') return false;
            if(i+1 <= n && j-1 >= 1 && s[i+1][j-1]== 'o') return false;
            if(i+1 <= n && s[i+1][ey] == 'o'){
                return false;
            }
            if(i-1 >= 1 && s[i-1][ey] == 'o'){
                return false;
            }
            if(ey+1 <= m && s[i][ey+1] == 'o'){
                return false;
            }
            if(i-1 >= 1 && ey+1 <= m && s[i-1][ey+1]== 'o') return false;
            if(i+1 <= n && ey+1 <=m && s[i+1][ey+1]== 'o') return false;
            return true;
        };
        bool ok = 0;
        for(int len = min(n,m); len >= 2; len--){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(j+len > m) break;
                        if(check(i,j,len)){
                            ok = 1;
                            break;;
                        }
                }
                if(ok) break;
            }
            if(ok)break;
        }
        if(ok) {
            cout << "2018" << endl;
            continue;
        }
        auto check1 = [&] (int i, int j ,int len) -> bool {
            for(int w = i; w <= i+len; w++){
                if(s[w][j]!= 'o') {
                    return false;
                }
            }
            int ex = i + len, ey = j;
            if(i-1 >= 1 && s[i-1][j] == 'o') return false;
            if(j-1 >= 1 && s[i][j-1] == 'o') return false;
            if(j+1 <= m && s[i][j+1] == 'o') return false;
            if(i-1 >= 1 && j-1 >=1 && s[i-1][j-1] == 'o') return false;
            if(i-1 >= 1 && j+1 <= m && s[i-1][j+1] == 'o') return false;

            if(ex +1 <= n && s[ex+1][j] == 'o') return false;
            if(j-1 >= 1 && s[ex][j-1] == 'o')return false;
            if(j+1 <= m && s[ex][j+1] == 'o')return false;
            if(ex+1 <= n && j-1 >=1 && s[ex+1][j-1] == 'o') return false;
            if(ex+1 <= n && j+1 <= m && s[ex+1][j+1] == 'o') return false;

            return true;
        };
        for(int len = min(n,m); len >= 2; len--){
            for(int j = 1; j <= m; j++){
                for(int i = 1; i <= n; i++){
                    if(i+len > n) break;
                        if(check1(i,j,len)){
                            ok = 1;
                            break;;
                        }
                }
                if(ok) break;
            }
            if(ok)break;
        }
        if(ok) {
            cout << "2018" << endl;
            continue;
        }
        cout << "2020" << endl;
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