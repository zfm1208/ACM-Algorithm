n=int(input())
k=n
x=1
for i in range(1,n+1):
   x*=i
   if(i==n):
     break
x*=x
y=1
k=0
for i in range(1,n+1):
    y*=n
xx=float(x)
yy=float(y)
print((xx/yy))