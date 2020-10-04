def check_order(a,n):
	for i in range(1,n):
		if a[i]>a[i+1]:
			return False
	return True
	

t=int(input())
for _ in range(t):
	n,k=map(int,input().split())
	#print(n,k)

	p=[0 for i in range(n+1)]
	s=input()
	s="0 "+s
	s=s.split()
	
	a=[int(x) for x in s]
	for i in range(1,n+1):
		p[a[i]]=i

	swap_order=[]
	vis=[False for i in range(n+1)]

	for i in range(1,n+1):
		vis[i]=False
		if i !=p[i]:
			x=p[i]
			y=i
			z=a[i]
			if z==x:
				continue
			swap_order.append([y,z,x])
			# y -> z -> x <-

			store= a[x]
			a[x] = a[z]
			p[a[z]] = x
			a[z] = a[y]
			p[a[y]] = z
			a[y] = store
			p[store]=y

	order=[]
	for i in range(1,n+1):
		if i != p[i] and p[i] == a[i] and not vis[p[i]]:
			order.append([i,p[i]])
			vis[i]=vis[p[i]]=True

	if len(order)%2==1:
		print("-1")
		continue

	lim=len(order)
	i=0
	while(i<lim):
		fir=order[i][0]
		sec=order[i][1]
		c=order[i+1][0]
		d=order[i+1][1]

		swap_order.append([b,c,d])
		
		# b -> c -> d <-

		store = a[d]
		a[d] = a[c]
		p[a[c]] = d
		a[c] = a[b]
		p[a[b]] = c
		a[b] = store
		p[store] = b

		swap_order.append([fir,b,c])
		
		# fir -> b -> c <-

		store = a[c]
		a[c] = a[b]
		p[a[b]] = c
		a[b] = a[fir]
		p[a[fir]] = b
		a[fir] = store
		p[store] = fir

		i+=2

	if len(swap_order)>k or not check_order(a,n):
		print("-1")
		continue

	print(len(swap_order))
	for i in swap_order:
		print(i[0],i[1],i[2])