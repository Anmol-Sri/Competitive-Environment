#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,p;
	cin>>n>>p;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll mx_dif=0;
	for(ll i=0;i<n;i++){
		mx_dif=max(mx_dif,arr[i]-i);
	}

	ll val=0;
	for(ll i=0;i<n;i++){
		if(i>=p-1){
			val=max(val, min(mx_dif-(arr[i]-i), i));
		}
	}
	val=max(p-val-1, 0LL);
	cout<<val<<"\n";
	for(int i=0;i<val;i++){
		cout<<mx_dif+i<<" ";
	}
	cout<<"\n";
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

	while(t--){
		solve();
	}

	return 0;
}