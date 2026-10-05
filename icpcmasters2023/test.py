n, k = list(map(int,input().split()))
ans = n % k
if ans == 0:
  print(k)
else:
  print(ans)