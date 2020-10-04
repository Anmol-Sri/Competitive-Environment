#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	ll ans=0,GCD=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans=gcd(ans,lcm(arr[i],GCD));
		GCD=gcd(GCD,arr[i]);
	}
	cout<<ans<<"\n";
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