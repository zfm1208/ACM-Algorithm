n=int(input())
# print(1);

k=n
x=1
for i in range(1,n+1):
   x*=i
   if(i==n):
     break
x*=x
y=1
k=0
for i in range(1,2*n+1):
   if(i>=n):
     y*=(i-k)
     k=k+1
   if(i==2*n):
      break;  
print(x//y)
