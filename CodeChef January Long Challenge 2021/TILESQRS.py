def pr(x, y, z):
	print(x, y, z)
	stdout.flush()

t = int(input())
for _ in range(t):
	in = input()
	in = in.split()
	n = int(in[0])
	q = int(in[1])
	k = int(in[2])
	ans = [[-1 for i in range(n)] for i in range(n)]
	pr(1, 1, 1)
	r = int(input())
	if r == -1:
		break
	if r > k:
		ans[1][1] = 0
		ans[1][0] = 1
		ans[0][1] = 1
		ans[0][0] = 0
	elif r < k:
		ans[1][1] = 0
		ans[1][0] = 1
		ans[0][1] = 1
		ans[0][0] = 1
	else:
		ri=0
		ci=1;
		for i in range(0, 4):
			rj=0
			cj=2
			for j in range(0, 3):
				k = r
				pr(1, (rj % 2) + 1, cj)
				r = int(input())
				if r == -1:
					exit()
				if r > k:
					if n == 2:
						flag = True
						ans[1][1] = 0
						ans[1][0] = 1
						ans[0][1] = 1
						ans[0][0] = 0
						break
					k = r
					pr(1, 1, 1)
					r = int(input())
					if r == -1:
						exit()
					if r < k:
						flag=True
						ans[1][1] = 0
						ans[1][0] = 1
						ans[0][1] = 1
						ans[0][0] = 1
						break
					k = r
					pr(1, 1, 1)
					r = int(input())
					if r == -1:
						exit()
				rj += 1
			if flag:
				break
			ri += 1
			k = r
			pr(1, (ri % 2) + 1, ci)
			r = int(input())
			if r == -1:
				exit()
			if(r>k)
			{
			if n == 2:
				flag = True
				ans[0][0] = 0
				ans[0][1] = 1
				ans[1][0] = 1
				ans[1][1] = 0
				break
			
			k = r
			pr(1, 1, 1)
			r = int(input())
			if r == -1:
				exit()
			if r < k:
				flag = True
				ans[0][0] = 1
				ans[0][1] = 1
				ans[1][0] = 1
				ans[1][1] = 0
				break

			k = r
			pr(1, 1, 1)
			r = int(input())
			if r == -1:
				exit()
			}
			}
			}
	sfor(i,2,n-1)
	{
		if(ans[i-1][0]!=0)
		{
		k=r;
		cout<<1<<" "<<i<<" "<<1<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[i-1][0]^=1;
		if(r>k)
		{
		ans[i][0]=1;
		ans[i][1]=0;
		}
		}
		if(ans[i-1][1]!=1)
		{
		k=r;
		cout<<1<<" "<<i<<" "<<2<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[i-1][1]^=1;
		if(r>k)
		{
		ans[i][0]=1;
		ans[i][1]=0;
		}
		}
		if(ans[i][0]!=-1) continue;
		ll cj=0;
		sfor(j,0,3)
		{
		k=r;
		cout<<1<<" "<<i+1<<" "<<(cj%2)+1<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		if(r>k)
		{
		k=r;
		cout<<1<<" "<<i<<" "<<1<<endl;
		fout;
		cin>>r;
		ans[i-1][0]^=1;
		if(r==-1) return false;
		if(r<k)
		{
		ans[i][0]=1;
		ans[i][1]=0;
		break;
		}
		k=r;
		cout<<1<<" "<<i<<" "<<1<<endl;
		fout;
		cin>>r;
		ans[i-1][0]^=1;
		if(r==-1) return false;
		}
		cj++;
		}
	}
	sfor(i,2,n-1)
	{
		if(ans[0][i-1]!=0)
		{
		k=r;
		cout<<1<<" "<<1<<" "<<i<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[0][i-1]^=1;
		if(r>k)
		{
		ans[0][i]=1;
		ans[1][i]=0;
		}
		}
		if(ans[1][i-1]!=1)
		{
		k=r;
		cout<<1<<" "<<2<<" "<<i<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[1][i-1]^=1;
		if(r>k)
		{
		ans[0][i]=1;
		ans[1][i]=0;
		}      
		}
		if(ans[0][i]!=-1) continue;
		ll rj=0;
		sfor(j,0,3)
		{
		k=r;
		cout<<1<<" "<<(rj%2)+1<<" "<<i+1<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		if(r>k)
		{
		k=r;
		cout<<1<<" "<<1<<" "<<i<<endl;
		fout;
		cin>>r;
		ans[0][i-1]^=1;
		if(r==-1) return false;
		if(r<k)
		{
		ans[0][i]=1;
		ans[1][i]=0;
		break;
		}
		k=r;
		cout<<1<<" "<<1<<" "<<i<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[0][i-1]^=1;
		}
		rj++;
		}
	}
	sfor(i,2,n-1)
	{
		sfor(j,2,n-1)
		{
		if(ans[i-1][j-1]!=0)
		{
		k=r;
		cout<<1<<" "<<i<<" "<<j<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[i-1][j-1]^=1;
		}
		if(ans[i-1][j]!=1)
		{
		k=r;
		cout<<1<<" "<<i<<" "<<j+1<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[i-1][j]^=1;
		}
		if(ans[i][j-1]!=1)
		{
		k=r;
		cout<<1<<" "<<i+1<<" "<<j<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		ans[i][j-1]^=1;
		}

		k=r;
		cout<<1<<" "<<i+1<<" "<<j+1<<endl;
		fout;
		cin>>r;
		if(r==-1) return false;
		if(r>k)
		{
		ans[i][j]=0;
		}
		else
		{
		ans[i][j]=1;
		}
		}
	}
	cout<<2<<endl;
	sfor(i,0,n-1)
	{
		sfor(j,0,n-1)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	fout;
	cin>>r;
	if(r==-1) return false;
	return true;		