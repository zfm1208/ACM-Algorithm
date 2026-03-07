import sys
input = sys.stdin.readline
def solve():
    n = int(input().strip())
    arr = [0] + list(map(int,input().split()))
    arr[1:] = sorted(arr[1:])
    for i in range(1,n+1):
        print(arr[i])
T = input().strip()
T = int(T)
for _ in range(T):
    solve()