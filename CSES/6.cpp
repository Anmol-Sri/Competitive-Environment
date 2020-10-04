#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int x,y;
	cin>>x>>y;
	int m=max(x,y);
	ll ans=1LL*m*(m-1)+1LL+powl(-1,m)*(x-y)*1LL;
	cout<<ans<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	*/
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}