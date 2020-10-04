#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll single = a/c;
	if(b<=single){
		cout<<b<<"\n";
		return;
	}
	float temp=1.0*(c-1);
	float ans=single-ceil((b-single)/temp);
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