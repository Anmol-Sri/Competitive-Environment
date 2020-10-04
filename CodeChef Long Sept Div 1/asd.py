fact_store_inv_calc = [0 for i in range(100002)] 
num_inv_calc = [0 for i in range(100002)]
fact_store = [0 for i in range(100002)]
MOD = 10**9+7
def pre():
	num_inv_calc[0] = 1
	num_inv_calc[1] = 1
	fact_store[0] = 1
	fact_store_inv_calc[0] = 1
	fact_store_inv_calc[1] = 1
	for i in range(2, 100002): 
		num_inv_calc[i]=num_inv_calc[MOD % i]*(MOD - MOD / i)%MOD; 
	for i in range(2, 100002): 
		fact_store_inv_calc[i] = (num_inv_calc[i] * fact_store_inv_calc[i - 1]) % MOD;
	for i in range(2, 100002): 
		fact_store[i] = (fact_store[i - 1] * i) % MOD

def calc(x, y):
	return ((fact_store[x] * fact_store_inv_calc[y]) % MOD * fact_store_inv_calc[x - y]) % MOD; 

pre()
test = int(input())
for asd in range(test):
	n = int(input())
	ans = 0
	mx = 0
	temp = 0
	s = input()
	s = s.split()
	for i in range(n):
		x = int(s[i])
		if mx < x:
			mx = x
			temp = 1
		else if ma == k:
			temp += 1
	val = 1
	for i in range(n - temp):
		val = (val * 2)%MOD
	ans = ans + (2 * val)%MOD
	for i in range(1, temp//2):
		if not i == (temp - i):
			ans = (ans + (val * (2 * calc(temp, i))%MOD)%MOD)%MOD
	print(ans)