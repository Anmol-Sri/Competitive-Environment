#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD=1e9+7;
void solve(){
	int n;
	cin>>n;
	char s[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	ll dp[n][n];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			if (s[i][j]=='.')
			{
				if(i>0)
				{
					dp[i][j]+=dp[i-1][j];
					dp[i][j]%=MOD;
				}
				if(j>0)
				{
					dp[i][j]+=dp[i][j-1];
					dp[i][j]%=MOD;
				}
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}
	cout<<dp[n-1][n-1]<<"\n";
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