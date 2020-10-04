def solve():
	binary=["1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"]
	bin_num=[0]*9

	for i in range(9):
		x=binary[i]
		count=0
		for q in x:
			if(q=='1'):
				count+=1
		bin_num[i]=count
				
	n,k=input().split()
	n=int(n)
	k=int(k)
	st=[]
	
	one=[0]*k
	zero=[0]*k

	for i in range(k):
		x=input()
		st.append(x)
		count=0
		for q in x:
			if q=='1':
				count+=1
		one.append(count)
		zero.append(len(x)-count)	

	for i in range(k):
		
