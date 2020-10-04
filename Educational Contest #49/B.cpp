#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n,q;
	cin>>n>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll count=(x-1)*n+(ll)y;
		ll ans=(count+1)/2LL;
		if((x+y)%2==1){
			ans+=((n*n)+1)/2;
		}
		cout<<ans<<"\n";
	}
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