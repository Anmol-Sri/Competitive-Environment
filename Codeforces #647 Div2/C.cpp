#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e3;
ll n;
ll ans,i;
void solve(){
	cin>>n;
	n+=1;
	ans=0;
	i=60;
	while(i>=0)
	{
		ll g=(1LL<<i);
		if(g<=n){
			ll r=n/g;
			if(n%g!=0)
				r++;
			ans+=(r-1);
			i--;
		}
		else{
			i--;
			continue;
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