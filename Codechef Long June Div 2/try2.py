s=input()
odd=[]
even=[]
special=0
for i in s:
	if i.isdigit():
		x=int(i)
		if x%2==0:
			even.append(x)
		else:
			odd.append(x)
	elif i.isalpha():
		continue
	else:
		special+=1

even_len=len(even)
odd_len=len(odd)
if odd_len==0 and even_len==0:
	print()
elif(even_len==0):
	for i in odd:
		print(i,end='',sep='')
elif odd_len==0:
	for i in even:
		print(i,end='',sep='')
else:
	if special%2==0:
		if(len(even)<len(odd)):
			for i in range(len(even)):
				print(even[i],sep='',end='')
				print(odd[i],sep='',end='')
			for i in range(len(even),len(odd)):
				print(odd[i],sep='',end='')
		else:
			for i in range(len(odd)):
				print(even[i],sep='',end='')
				print(odd[i],sep='',end='')
			for i in range(len(odd),len(even)):
				print(odd[i],sep='',end='')	
		print()
	else:
		if(len(even)<len(odd)):
			for i in range(len(even)):
				print(odd[i],sep='',end='')
				print(even[i],sep='',end='')
			for i in range(len(even),len(odd)):
				print(odd[i],sep='',end='')
		else:
			for i in range(len(odd)):
				print(odd[i],sep='',end='')
				print(even[i],sep='',end='')
			for i in range(len(odd),len(even)):
				print(odd[i],sep='',end='')
		print()