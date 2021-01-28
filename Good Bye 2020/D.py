t = int(input())
for _ in range(t):
  n = int(input())
  weights = list(map(int, input().split()))
  temp = []
  cnt = [0] * (n + 1)
  for i in range(n-1):
    x, y = map(int, input().split())
    y = y - 1
    x = x - 1
    cnt[x] += 1
    cnt[y] += 1
    if cnt[y] > 1:
      temp += [weights[y]]
    if cnt[x] > 1:
      temp += [weights[x]]
  temp = sorted(temp)[::-1]
  summ = sum(weights)
  ans = [str(summ)]
  for i in temp:
    summ += i
    ans += [str(summ)]
  print(" ".join(ans))