#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
// 1. 打表发现：最高位 9 种，后面每位 5 种。
// 2. 所以 len 位合法数有 9 * 5^(len - 1) 个。
// 3. 先减掉较短长度的数量，确定答案是几位数。
// 4. 然后从高位到低位构造。
// 5. 当前位的每个候选数字，都对应 p5[剩余位数] 个答案。
// 6. 用除法确定当前位选哪个数字。
// 7. 用取模更新进入当前块后的 n。
void solve(){
    int n; cin >> n;
    vector<int> p5(30);
    p5[0] = 1;
    for(int i = 1; i <= 20; i++){
        p5[i] = p5[i-1] * 5;
    }
    int len = 2;
    for(int i = 2; i <= 20; i++){
        int x = 9 * p5[i-1];
        if(n > x) n -= x;
        else {
            len = i;
            break;
        }
    }
    string ans;
    int last = -1;
    for(int i = 1; i <= len; i++){
        if(i == 1){
            vector<int> cun({1,2,3,4,5,6,7,8,9});
            int rem = len - i;
            int idx = (n - 1) / p5[rem];
            int x = cun[idx];
            ans.push_back(char('0' + x));
            last = x;
            n = (n - 1) % p5[rem] + 1;
        }else{
            if(last & 1){
                vector<int> cun({0,2,4,6,8});
                int rem = len - i;
                int idx = (n - 1) / p5[rem];
                int x = cun[idx];
                ans.push_back(char('0' + x));
                last = x;
                n = (n - 1) % p5[rem] + 1;
            }else{
                vector<int> cun({1,3,5,7,9});
                int rem = len - i;
                int idx = (n - 1) / p5[rem];
                int x = cun[idx];
                ans.push_back(char('0' + x));
                last = x;
                n = (n - 1) % p5[rem] + 1;
            }
        }
    }
    cout << ans << endl;
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
