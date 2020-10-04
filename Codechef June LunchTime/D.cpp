#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll calc(ll n){
	return (ll)(log2(n));
}
void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll temp=0;
	int val[32];
	memset(val,0,sizeof(val));
	for(int i=0;i<n;i++){
		cin>>arr[i];
		bitset<32> asd(arr[i]);
		for(int j=0;j<32;j++) val[j]=asd[j];
		temp|=arr[i];
	}
	ll ans=0;
	/*for(int i=0;i<k;i++){
		int pos=calc(arr[i]);
		// cout<<arr[i]<<" - "<<pos<<"\n";
		if(!((1<<(pos))&(ans))){
			ans|=1<<(pos);
		}
		// cout<<"ans = "<<ans<<"\n";
	}*/
	bitset<32> b1(temp);
	cout<<b1<<"\n";
	ll step=0;
	// cout<<temp<<"\n";
	for(int i=32;i>0 && step<k;i--){
		if(temp&(1<<(i-1))){
			ans|=(1<<(i-1));
			bitset<32> b2(ans);
			cout<<b2<<"\n";
			step++;
			temp=temp>>1;
		}
	}
	cout<<ans<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}