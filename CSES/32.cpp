#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n;
void solve(){
	cin>>n;
	ll arr[n];
	ll sum=0;
	ll mx=0;
	for(ll &i:arr) cin>>i,sum+=i,mx=max(mx,i);
	cout<<max(sum,2*mx)<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

/*    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}