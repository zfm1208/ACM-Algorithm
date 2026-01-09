#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000005];
int n,k;
// 机洗 x 分钟  , x*k + mid - x >= a[i]
bool check(int x){
    long long sum = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > x){
            sum += ceil(ceil(a[i]-x)/(k-1));
        }
    return sum <= x;
}
int main(){
    while(cin >> n){
        int mx = -1;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            if(a[i] > mx) mx = a[i];
        }
        cin >> k;
        if(k == 1){cout << mx << endl; return 0;}
        int l = 0,r = mx+1;
        while(r-l>1){
            int mid = (r+l)/2;
            if(check(mid))r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
    return 0;
}