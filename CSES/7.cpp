#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll ans=i*i*1LL*(i*i*1LL-1LL)/2-4*1LL*(i-1)*(i-2);
		cout<<max(0LL,ans)<<"\n";
	}
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
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}