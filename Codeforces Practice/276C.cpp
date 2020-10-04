#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n,q;
	cin>>n>>q;
	ll arr[n];
	for(ll&x:arr) cin>>x;
	sort(arr,arr+n);
	ll update[n]={0};
	while(q--){
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		update[x]++;
		if(y<n-1) update[y+1]--;
	}
	ll ans=0;
	ll calc[n];
	for(ll i=0;i<n;i++){
		ans+=update[i];
		calc[i]=ans;
	}
	sort(calc,calc+n);
	ll qwe=0;
	for(ll i=0;i<n;i++){
		qwe+=(calc[i]*arr[i]*1LL);
	}
	cout<<qwe<<"\n";
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}