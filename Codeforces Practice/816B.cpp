#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+10;
int bit[mxN];
bool cond[mxN];

int sum(int k){
	int s=0;
	while(k>=1){
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}

void upd(int k,int x){
	while(k<=mxN){
		bit[k]+=x;
		k+=k&-k;
	}
}
void solve(){
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		upd(l,1);
		upd(r+1,-1);
	}
	for(int i=1;i<mxN;i++){
		cond[i]=(sum(i)>=k);
	}
	memset(bit,0,sizeof(bit));
	for(int i=0;i<mxN;i++){
		if(cond[i]) upd(i,1);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<sum(b)-sum(a-1)<<"\n";
	}
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
	while(t--){
		solve();
	}
    return 0;
}