#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=20;
int st[1<<mxN];
int n,m;
int p,b;

void build(int pos,int l,int r,int x){
	if(l==r){
		cin>>st[pos];
		return;
	}
	int mid = (l+r) >> 1;
	build(pos<<1,l,mid,x-1);
	build(pos<<1|1,mid+1,r,x-1);
	if(x&1){
		st[pos]=st[pos<<1] | st[pos<<1 | 1];
	}
	else{
		st[pos]=st[pos<<1] ^ st[pos<<1 | 1];
	}
}

void update(int pos,int l,int r,int x){
	if(l==r){
		st[pos]=b;
		return;
	}

	int mid = (l+r) >>1;
	if(p<=mid) update(pos<<1,l,mid,x-1);
	else update(pos <<1 |1,mid+1,r,x-1);

	if(x&1) st[pos]=st[pos<<1] | st[pos<<1 | 1];
	else st[pos] = st[pos<< 1] ^ st[pos << 1 | 1];
}

void solve(){
	cin>>n>>m;
	build(1,1,1<<n,n);
	while(m--){
		cin>>p>>b;
		update(1,1,1<<n,n);
		cout<<st[1]<<"\n";
	}
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}