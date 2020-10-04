#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),b(n),reward(n);
	map<int,int> compress;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>reward[i];
		b[i]++;
		compress[a[i]];
		compress[b[i]];
	}
	int coords=0;
	for(auto&x:compress) x.second=coords++;

	vector<vector<pair<int,int>>> task(coords);
	for(int i=0;i<n;i++){
		task[compress[b[i]]].push_back({compress[a[i]],reward[i]});
	}
	vector<ll> dp(coords,0);
	for(int i=0;i<coords;i++){
		if(i>0){
			dp[i]=dp[i-1];
		}
		for(auto x:task[i]){
			dp[i]=max(dp[i],dp[x.first]+x.second);
		}
	}
	cout<<dp[coords-1]<<"\n";
	return ; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

/*	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif*/
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}