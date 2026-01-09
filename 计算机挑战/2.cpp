#include<stdio.h>
int read(int x){
    int i,y=0,k; char d[20];
    scanf("%s",d);
	for(i=0;d[i]!='\0';i++){
    	if(d[i]>='0'&&d[i]<='9')      k=d[i]-48;
    	else if(d[i]>='A'&&d[i]<='Z') k=d[i]-55;
    	else return -1;
    	if(k>=x) return -1;
    	y=y*x+k;
	}
	return y;
}
void print(int n){
    if(n<10) printf("%d",n);
    else printf("%c",55+n);
}
void write(int n,int x){
    if(n<x) print(n);
    else{
	    write(n/x,x);
	    print(n%x);
	}
}
int main(){
    int x,y;
	scanf("%d",&x);
	y=read(x);
	//printf("==%d==",y);
	if(y==-1){
	    printf("DATA ERROR!");
	    return 0;
	}
	if(x==10)      write(y,9);
	else if(x==9) write(y,10);
 	else printf("DATA ERROR!");
    return 0;
}