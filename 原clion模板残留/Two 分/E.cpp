
#include<algorithm>
#include<string>
#include<map>
#include<stdio.h>
#include<cstdio>
using namespace std;
int a[100005];
int n;
int check(int mid){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int tem = (upper_bound(a + 1, a + n + 1, a[i] + mid) - a) - 1 - i;
        cnt += tem;
    }
    return cnt;
}
int main(){
    while(scanf("%d", &n) != EOF){
        int m =(n*(n-1)/2+1)/2;
        for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int r = a[n] - a[1],l = 0;
        int mid = (l + r + 1) >> 1;
        while (l < r){
            if (check(mid) >= m) r = mid;
            else l = mid + 1;
            mid = (l + r) >> 1;
        }
        printf("%d\n", r);
    }
}
 