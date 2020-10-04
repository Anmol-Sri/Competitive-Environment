MOD = 1000000007
arr1 = [0 for i in range(100010)]
arr2 = [0 for i in range(100010)]
arr3 = [0 for i in range(100010)]

def pre():
	arr2[0] = 1
	arr2[1] = 1 
	arr1[0] = 1
	arr1[1] = 1
	arr3[0] = 1
	for i in range(2, 100010):
		arr2[i] = arr2[MOD % i] * (MOD - MOD//i) % MOD 
	for i in range(2, 100010):
		arr1[i] = (arr2[i] * arr1[i - 1]) % MOD 
	for i in range(1, 100010):
		arr3[i] = (arr3[i - 1] * i) % MOD

def calc(x,y):
	return ((arr3[x] * arr1[y]) % MOD * arr1[x - y]) % MOD

pre()
test = int(input())
for asd in range(test):
	n = int(input())
	res=0
	minimum=0
	count_val=0
	s = input()
	s = s.split()
	for i in range(n):
		temp = int(s[i])
		if minimum < temp:
			minimum = temp
			count_val = 1
		elif minimum == temp:
			count_val += 1
	val = 1
	i = 0
	while i < n - count_val:
		val = (2 * val) % MOD
		i += 1
	res = res + (val * 2) % MOD
	i = 1
	while i <= count_val//2 :
		if i != (count_val-i):
			res = (res + (val * (calc(count_val, i) * 2) % MOD ) % MOD ) % MOD
		i += 1
	print(res)
