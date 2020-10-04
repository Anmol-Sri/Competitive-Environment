import math

def check(num):
	if(num==0):
		return False
	x=(int)(math.sqrt(num))
	if(x*(x+1)==num):
		return True
	return False

s=input()
n=len(s)
ans=[]
for i in range(n):
	for end in range(i+1,n+1):
		sub=s[i:end]
		num=int(sub)
		if check(num):
			ans.append(num)

if not ans:
	print("-1")
else:
	ans.sort()
	res = [] 
	[res.append(x) for x in ans if x not in res]
	for i in range(len(res)):
		if(i==len(res)-1):
			print(res[i])
		else:
			print(res[i],",",end='',sep='')	
