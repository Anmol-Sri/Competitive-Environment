#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD=1e9+7;
void solve(){
	ll n;
	cin>>n;
	ll sum=(n*(n+1))/2;
	if(sum%2!=0){
		cout<<"0\n";
		return ;
	}
	ll target=sum/2;

	ll dp[n][target+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=target;j++){
			dp[i][j]=dp[i-1][j];
			ll rem=j-i;
			if(rem>=0){
				dp[i][j]+=dp[i-1][rem];
				dp[i][j]%=MOD;
			}
		}
	}
	cout<<dp[n-1][target]<<"\n";
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