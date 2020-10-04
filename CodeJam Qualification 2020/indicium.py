arr=[[0 for q in range(60)] for w in range(60)]
n=0
k=0
q=0
cs=[[False for q in range(60)] for w in range(60)]
rs=[[False for q in range(60)] for w in range(60)]
flag=False

def recur(r,c,m):
	global flag
	if(not flag and r==n and c==n+1 and m==k):
		flag=True
		print('Case #',q,': POSSIBLE')
		for i in range(1,n+1):
			for j in range(1,n+1):
				print(arr[i][j],'',end="")
			print()	
		return	
	elif(r>n):
		return
	elif(c>n):
		recur(r+1,1,m);

	i=1
	while(not flag and i<=n):
		if(not rs[r][i] and not cs[c][i]):
			rs[r][i]=True
			cs[c][i]=True
			if(r==c):
				m=m+i
			arr[r][c]=i
			recur(r,c+1,m)
			rs[r][i]=False
			cs[c][i]=False
			if(r==c):
				m=m-i
			arr[r][c]=0
		i+=1
	
t=int(input())
for q in range(1,t+1):
	s=input()
	s=s.split()
	n=int(s[0])
	k=int(s[1])
	recur(1,1,0)
	if not flag:
		print("Case #",q,": IMPOSIIBLE")
	flag=False
