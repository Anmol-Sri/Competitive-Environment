#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n;
	cin>>n;
	ll arr[n+1]={0};
	std::map<ll, ll> mp;	
	mp[0]++;
	ll cur=0,rem,ans=0;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		cur+=arr[i];
		arr[i]+=arr[i-1];
		arr[i]=arr[i]%n;
		if (arr[i] < 0) arr[i] += n;
		rem=(arr[i]+n)%n;
		//cout<<arr[i]<<" "<<rem<<"\n";
		ans+=mp[rem];
		mp[arr[i]]++;
	}
	cout<<ans<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

 //    #ifndef ONLINE_JUDGE
	//     freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}