#using 10**10 as INFINITY
def recur(n, k, cur, f, m):
	if n <= cur:
		return 2147483647
	if m[cur] != -1:
		return m[cur]
	# frequency array
	ft = [0 for i in range(101)]
	#tot is for updating the m list in the recursion value
	tot = 2147483647
	cnt = 0
	le = 2147483647
	ret = 2147483647
	i = cur
	while i < n:
		ft[f[i]] += 1
		if ft[f[i]] == 2:
			cnt += 2
		elif ft[f[i]] > 2:
			cnt += 1
		ret = recur(n, k, i + 1, f, m)
		if ret != 2147483647:
			ret += cnt + k
		le = min(le, ret)
		i += 1
	tot = cnt + k
	# m[cur] = min(le, tot)
	if le < tot:
		m[cur] = le
	else:
		m[cur] = tot
	return m[cur]

test = int(input())
asd = 1
while asd <= test:
	n, k = input().split()
	n = int(n)
	k = int(k)
	s = input()
	s = s.split()
	f = [int(x) for x in s]
	m = [-1 for i in range(n)]
	print(recur(n, k, 0, f, m))
	asd += 1
