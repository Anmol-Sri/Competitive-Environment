#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
    ll power=pow(2,n);
    ll range=0;
    
    for(ll i=1;i<=(n/2)-1;i++)
    	power+=pow(2,i);

    for(ll j=(n/2);j<n;j++)
    	range+=pow(2,j);

    ll diff=abs(power-range);
    cout<<diff<<"\n";
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