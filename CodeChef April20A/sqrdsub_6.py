def solve():
	n=int(input())
	arr=[]
	i=0
	arr.append((-1,0))
	s=input()
	s=s.split()
	s=[int(x) for x in s]
	while i<n:
		t=s[i]
		t=abs(t)
		if t%4==2:
			arr.append((i,1))
		elif t%4==0:
			arr.append((i,0))
		i+=1
	arr.append((n,0))
	ans=n*(n+1)
	ans=int(ans/2)
	i=1
	while i<len(arr)-1:
		if arr[i][1]==0:
			i+=1
			continue
		store=arr[i][0]-arr[i-1][0]
		store=store*(arr[i+1][0]-arr[i][0])
		ans=ans-store
		i+=1
	print(ans)
t=int(input())
for q in range(t):
	solve()			