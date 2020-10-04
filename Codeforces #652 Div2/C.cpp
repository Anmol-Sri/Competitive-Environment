#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	ll w[k];
	for(ll i=0;i<k;i++){
		cin>>w[i];
	}
	sort(arr,arr+n,greater<int>());
	sort(w,w+k);
	if(n==k){
		cout<<2*sum<<"\n";
		return ;
	}
	ll index=0;
	ll ans=0;
	ll ins[k];
	for(ll i=0;i<k;i++){
		ins[i]=arr[i];
	}
	index=k;
	for(ll i=0;i<k;i++){
		if(w[i]>1){
			index=index+w[i]-2;
			ins[i]+=arr[index];
			index++;
		}
		else{
			ins[i]*=2;
		}
	}
	for(ll i=0;i<k;i++) ans+=ins[i];
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
		clock_t tStart = clock();
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
	#ifndef ONLINE_JUDGE
		cerr<<fixed<<setprecision(10)<<"Time Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
	#endif

	return 0;
}