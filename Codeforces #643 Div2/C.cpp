#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll a,b,c,d;
ll calc(ll i){
	return min(i-c,d-c+1) * (i-a-b+1 - max(0ll,i-b-b) - max(0ll,i-a-c) + max(0ll,i-b-c-1));
}
void solve(){
	ll ans=0;
	cin>>a>>b>>c>>d;


	for(ll i=max(a+b,c);i<=c+d;i++){
		ans+=calc(i);
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}