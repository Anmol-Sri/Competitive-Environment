#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=2e5+1;
ll arr[mxN];
ll n,k;

bool check(ll mid){
	ll cnt=0;
	ll sum=0;
	for(ll i=0;i<n;i++){
		if(arr[i]>mid) return false;
		sum+=arr[i];
		if(sum>mid) cnt++,sum=arr[i];
	}
	cnt++;
	if(cnt<=k) return true;
	return false;
}

void solve(){
	cin>>n>>k;
	ll end=0;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		end+=arr[i];
	}
	ll start=1;
	ll ans=0;
	while(start<=end){
		ll mid=(start+end)>>1;
		if(check(mid)){
			ans=mid;
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	cout<<ans<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    /*#ifndef ONLINE_JUDGE
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