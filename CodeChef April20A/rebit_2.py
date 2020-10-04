MOD=998244353
#Code taken from GeeksForGeeks
def gcdExtended(a, b, x, y): 
	# Base Case 
	if a == 0 :  
		x = 0
		y = 1
		return b
	x1 = 1
	y1 = 1 
	gcd = gcdExtended(b%a, a, x1, y1) 
	x = y1 - (b/a) * x1 
	y = x1 
  
	return gcd 

def precalc_string(s):
	num=748683265
	temp_store=[num for i in range(4)]
	ans=[[]]
	bit_or=[]
	bit_and=[]
	bit_xor=[]
	bit_or.append(1)
	bit_and.append(2)
	bit_xor.append(3)
	store=[]
	for n in range(len(s)):
		if s[n]=='#':
			ans.append(temp_store)
			continue
		if s[n]==')':
			while store[len(store)-1]!='(':
				if store[len(store)-1]=='|':
					ans.append(bit_or)
				elif store[len(store)-1]=='&':
					ans.append(bit_and)
				elif store[len(store)-1]=='^':
					ans.append(bit_xor)
				store.pop()
			store.pop()
		elif s[n]=='(' or len(store)==0 or store[len(store)-1]=='(':
			store.append(s[n])
		else:
			if store[len(store)-1]=='|':
				ans.append(bit_or)
			elif store[len(store)-1]=='&':
				ans.append(bit_and)
			elif store[len(store)-1]=='^':
				ans.append(bit_xor)
			store.pop()
			store.append(s[n])
		print(store)
		
	print(bit_and)
	while not len(store)==0:
		if store[len(store)-1]=='|':
			ans.append(bit_or)
		elif store[len(store)-1]=='&':
			ans.append(bit_and)
		elif store[len(store)-1]=='^':
			ans.append(bit_xor)
		store.pop()
	print("ans-precalc - ",ans)	
	return ans

def Calc_or(a,b):
	ans=[0 for i in range(4)]
	store=[]
	term1=0
	ans[0]=(a[0]*b[0])%MOD
	term1=b[0]
	for n in range(1,4):
		term1=(term1+b[n])%MOD
	term1=(term1*a[1])%MOD
	term2=a[0]
	
	term2 = (term2+a[2])%MOD
	term2 = (term2+a[3])%MOD
	term2 = (term2*b[1])%MOD
	term3 = (a[2]*b[3])%MOD
	term4 = (a[3]*b[2])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[1] = store
	term1 = (a[0]*b[2])%MOD
	term2 = (a[2]*b[0])%MOD
	term3 = (a[2]*b[2])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	ans[2] =store
	term1 = (a[0]*b[3])%MOD
	term2 = (a[3]*b[0])%MOD
	term3 = (a[3]*b[3])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	ans[3] = store
	return ans

def Calc_and(a,b):
	ans=[0 for i in range(4)]
	store=[]
	term1=0
	ans[0]=(a[1]*b[1])%MOD
	term1=b[0]
	for n in range(1,4):
		term1=(term1+b[n])%MOD
	term1=(term1*a[0])%MOD
	term2=a[1]
	term2 = (term2+a[2])%MOD
	term2 = (term2+a[3])%MOD
	term2 = (term2*b[0])%MOD
	term3 = (a[2]*b[3])%MOD
	term4 = (a[3]*b[2])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[0] = store
	term1 = (a[1]*b[2])%MOD
	term2 = (a[2]*b[1])%MOD
	term3 = (a[2]*b[2])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	ans[2] =store
	term1 = (a[1]*b[3])%MOD
	term2 = (a[3]*b[1])%MOD
	term3 = (a[3]*b[3])%MOD
	store = term1
	store = (term1+term2)%MOD
	store = (store+term3)%MOD
	ans[3] = store
	return ans

def Calc_xor(a,b):
	store=[]
	ans=[0 for i in range(4)]
	term1 = (a[0]*b[0])%MOD
	term2 = (a[1]*b[1])%MOD
	term3 = (a[2]*b[2])%MOD
	term4 = (a[3]*b[3])%MOD
	store = term1
	store = (store+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[0] = store
	term1 = (a[0]*b[1])%MOD
	term2 = (a[1]*b[0])%MOD
	term3 = (a[2]*b[3])%MOD
	term4 = (a[3]*b[2])%MOD
	store = term1
	store = (store+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[1] = store
	term1 = (a[0]*b[2])%MOD
	term2 = (a[1]*b[3])%MOD
	term3 = (a[2]*b[0])%MOD
	term4 = (a[3]*b[1])%MOD
	store = term1
	store = (store+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[2] = store
	term1 = (a[0]*b[3])%MOD
	term2 = (a[1]*b[2])%MOD
	term3 = (a[2]*b[1])%MOD
	term4 = (a[3]*b[0])%MOD
	store = term1
	store = (store+term2)%MOD
	store = (store+term3)%MOD
	store = (store+term4)%MOD
	ans[3] = store
	return ans

def inverse(a):
	x=1
	y=1
	gcd=gcdExtended(a,MOD,x,y)
	while x<0:
		x+=MOD
	return x%MOD

t=int(input())
for _ in range(t):
	s=input()
	pfix=precalc_string(s)
	print("pfix - ",pfix)
	st=[[]]
	for i in range(len(pfix)):
		print("st - ",st)
		ele=pfix[i]
		if len(ele)==4:
			st.append(ele)
		elif len(ele)==1:
			a=[]
			b=[]
			c=[]
			a=st[len(st)-1]
			st.pop()
			b=st[len(st)-1]
			st.pop()
			if(ele[0]==1):
				c=Calc_or(a,b)
			elif(ele[0]==2):
				c=Calc_and(a,b)
			elif(ele[0]==3):
				c=Calc_xor(a,b)
			st.append(c)
	ele=st[len(st)-1]
	ans=[0 for i in range(4)]
	for i in range(4):
		ans[i]=ele[i]%MOD
		print(ans[i],"",end="")
	print()