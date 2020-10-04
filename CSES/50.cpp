#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	int n,x;
	cin>>n>>x;
	int price[n],pages[n];
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	for(int i=0;i<n;i++){
		cin>>pages[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			dp[i][j]=dp[i-1][j];
			int left=j-price[i-1];
			if(left>=0){
				dp[i][j]=max(dp[i][j],dp[i-1][left]+pages[i-1]);
			}
		}
	}
	cout<<dp[n][x]<<"\n";
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