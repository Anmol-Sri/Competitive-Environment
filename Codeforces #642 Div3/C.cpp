#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=5e5+1;
ll sum[mxN];
void precalc(){
	sum[0]=sum[1]=0;
	sum[3]=8;
	sum[5]=40;
	ll val=3;
	for(int i=7;i<mxN;i=i+2,val++){
		sum[i]=(8*val*val)+sum[i-2];
	}
}
void solve(){
	int n;
	cin>>n;
	cout<<sum[n]<<"\n";
	return ;
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
	precalc();
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}