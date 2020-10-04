#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ar array

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr) cin>>i;

	vector<vector<ll>> dp(n+1,vector<ll>(3));
	for(int i=0;i<n;i++){
		dp[i+1][0]=max(dp[i+1][0],dp[i][0]+(i%2==0?arr[i]:0));
		if(i+2<=n) dp[i+2][1]=max(dp[i+2][1],max(dp[i][0],dp[i][1])+(i%2==0?arr[i+1]:arr[i]));
		dp[i+1][2]=max(dp[i+1][2],max({dp[i][0],dp[i][1],dp[i][2]})+(i%2==0?arr[i]:0));
	}
	cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
	return  ;
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
		
	// int t=1;
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}