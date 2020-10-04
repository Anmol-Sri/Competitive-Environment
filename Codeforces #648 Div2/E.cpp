#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
	ll arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				ans=max(ans,(arr[i]|arr[j]|arr[k]));
			}
		}
	}
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
		
	int t=1;
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}