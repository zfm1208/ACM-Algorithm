#include<stdio.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long n;
        int cnt;
        int g,b=0;
        int a;
        scanf("%lld",&n);
        if(n==1||n==2||n==3){
            printf("NO\n");
        }else{
            for(int i=2;i<=n;i++){
                cnt=0;
                for(int j=2;j<=sqrt(i);j++){
                    if(i%j==0){
                        cnt=1;
                        break;
                    }
                }
                g=i;
                if(cnt==0){
                    a=n-i;
                    for(int i=2;i<=sqrt(a);i++){
                        if(a%i==0){
                            b=1;
                            break;
                        }
                    }
                    if(b==1){
                        printf("%d %d",g,a);
                        printf("\n");
                        break;
                    }
                }
            }
        }
    }
}