#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll a,b,c,d;
	cin>>c>>d>>a>>b;
	if(c>d){
		swap(c,d);
	}
	ll ans=(d-c)*a;
	ans=ans+min(c*2*a,c*b);
	cout<<ans<<"\n";
	return;
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