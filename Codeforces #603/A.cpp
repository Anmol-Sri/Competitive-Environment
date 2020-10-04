#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	ll ans=0;
	if(arr[0]+arr[1]<=arr[2]){
		ans=arr[0]+arr[1];
		cout<<ans<<"\n";
		return ;
	}
	ans=(arr[1]+arr[2]+arr[0])>>1;
	
	
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}