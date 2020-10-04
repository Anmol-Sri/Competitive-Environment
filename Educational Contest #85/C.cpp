#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
	ll a[n],b[n];
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	ll mi=LLONG_MAX;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll forward=(i+1)%n;
		ll val=min(a[forward],b[i]);
		ans+=a[forward]-val;
		mi=min(mi,val);
	}
	ans+=mi;
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