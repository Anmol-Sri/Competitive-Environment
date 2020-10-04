t=int(input())
for _ in range(t):
	n=int(input())
	li= list(map(int,input().split()))
	ans=0
	for i in range(n):
		pro=1
		for j in range(i,n,1):
			pro=pro*li[j]
			if(pro%4!=2):
				ans=ans+1
	print(ans)			