#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll mx=*max_element(arr,arr+n),sum=0;
	for(int i=0;i<n;i++){
		sum=max(arr[i]+sum,arr[i]);
		mx=max(mx,sum);
	}
	cout<<mx<<"\n";
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