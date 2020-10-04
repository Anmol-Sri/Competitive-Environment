#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int ele=arr[n>>1];
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=abs(arr[i]-ele);
	}
	cout<<ans<<"\n";
	return;
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