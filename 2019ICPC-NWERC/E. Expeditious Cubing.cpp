#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 1e6+7;
long double a[20];
void fff(){
    long double pos;
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }
    cin >> pos;
    sort(a,a+4);
    long double sum1 = a[0] + a[1] + a[2];
    long double sum2 = a[3] + a[1] + a[2];
    sum1=sum1/3;
    sum2=sum2/3;
    if(sum2 <= pos){
        cout << "infinite";
    }else if(sum1 > pos){
        cout << "impossible";
    }else{
        cout << fixed << setprecision(2) << (pos * 3 - ( a[1] + a[2])) << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        fff();
    }
    return 0;
}