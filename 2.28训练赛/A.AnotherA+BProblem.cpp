#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
/*
    G: 绿色 这个数字在答案的正确位置上
    P: 蓝色 这个数字在答案中,但位置错误
    B: 黑色 这个数字不在答案中 或者 该数子出现次数> 答案的这个数的出现次数
    ??+??=??
      G  G

    E: 给定等式
    C: 该等式的颜色
*/            
/*
    E:  40+11=51
    C:  PB PP  B
    T:  11+42=53
    E:
    mpb['0']=1;mpp['0']=0;mp['0'] = 0
    mpb['1']=1;mpp['1']=2;mp['1'] = 2
    mpb['2']=0;mpp['2']=0;mp['2'] = 1
    mpb['3']=0;mpp['3']=0;mp['3'] = 1
    mpb['4']=0;mpp['4']=1;mp['4'] = 1
    mpb['5']=0;mpp['5']=0;mp['5'] = 1
*/
void solve(){
    string E,C; cin >> E >> C;
    E = ' ' + E;
    C = ' ' + C;
    auto check = [&] (int n1, int n2, int n3, int n4, int n5, int n6) -> bool {
        int num1 = n1 * 10 + n2;
        int num2 = n3 * 10 + n4;
        int num3 = n5 * 10 + n6;
        if(num3 >= 100) return false;
        if(C[1] == 'G' && n1 != E[1] - '0') return false; 
        if(C[2] == 'G' && n2 != E[2] - '0') return false;
        if(C[4] == 'G' && n3 != E[4] - '0') return false;
        if(C[5] == 'G' && n4 != E[5] - '0') return false;
        if(C[7] == 'G' && n5 != E[7] - '0') return false;
        if(C[8] == 'G' && n6 != E[8] - '0') return false;
        return (num1 + num2 == num3);
    };
    vector<string> ans;
    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            string c1 = to_string(i);
            if(i < 10) c1 = '0' + c1;
            string c2 = to_string(j);
            if(j < 10) c2 = '0' + c2;
            string c3 = to_string(i+j);
            if(i+j < 10) c3 = '0' + c3;
            string tp = c1 + '+' + c2 + '=' + c3;
            
            if(tp.size()!= 8) continue;
            int ok = 0;
            for(int i = 1; i <= 8; i++){
                if(C[i] == 'G' && tp[i-1] != E[i]) {
                    ok = 1;
                    break;
                }
                if(C[i] != 'G' && tp[i-1] == E[i]){
                    ok = 1;
                    break;
                }
            }
            if(ok == 1) continue;
            map<char,int> mp,mpb,mpp;
            for(int k = 1; k <= 8; k++){
                if(C[k] == 'G') continue;
                mp[tp[k-1]]++;
                if(C[k] == 'P')
                mpp[E[k]]++;
                if(C[k] == 'B')
                mpb[E[k]]++;
            }
            for(char num = '0'; num <= '9'; num++){
                if(mpb.find(num)!= mpb.end()){
                    if(mp[num] != mpp[num]){
                        ok = 1;
                        break;
                    }                    
                }else{
                    if(mp[num] < mpp[num]){
                        ok = 1;
                        break;
                    }  
                }
            }
            if(check(tp[0]-'0',tp[1]-'0',tp[3]-'0',tp[4]-'0',tp[6]-'0',tp[7]-'0') == false){
                continue;
            }
            if(ok == 0)ans.push_back(tp);
        }
    }

    cout << ans.size() << endl;
    for(auto s: ans){
        cout << s << endl;
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}