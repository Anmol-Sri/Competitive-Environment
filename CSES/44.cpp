#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD=1e9+7;
const int mxN=1e6+1;
int n;
ll dp[mxN];
void solve(){
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(6,i);j++){
			dp[i]=(dp[i]+dp[i-j])%MOD;
		}
	}
	cout<<dp[n]<<"\n";
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